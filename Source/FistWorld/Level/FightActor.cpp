// Copyright 2019

#include "FightActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/FighterNamePanelComponent.h"
#include "Story/Kingdom.h"
#include "Level/ArcherActor.h"
#include "Level/ShieldActor.h"
#include "Level/RiderActor.h"
#include "FightReporter.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "Components/FighterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "RandomMaker.h"
#include <math.h>

// Sets default values
AFightActor::AFightActor() : TickAfterTurnOn(), m_o_warrior_binded( nullptr ), m_f_last_attack( 0 ), m_f_attack_cd( 1.0f )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    bCanBeDamaged = true;
    this->bCanAffectNavigationGeneration = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>( "root comp" );
    this->m_comp_capsule = CreateDefaultSubobject<UCapsuleComponent>( "Collection" );
    this->m_comp_capsule->InitCapsuleSize( 100.0f, 120.0f );
    this->m_comp_capsule->SetCanEverAffectNavigation( true );
    this->m_comp_capsule->SetCollisionProfileName( "BlockAll" );
    this->m_comp_capsule->SetupAttachment( RootComponent );
    this->m_comp_capsule->SetRelativeLocation( FVector( 0, 0, 60.0f ) );
    this->m_comp_capsule->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
    this->m_mesh_warrior = CreateDefaultSubobject<USkeletalMeshComponent>( "Warrior body" );
    this->m_mesh_warrior->SetupAttachment( this->m_comp_capsule );
    this->m_mesh_warrior->SetRelativeLocation( FVector( 0, 0, -60.0f ) );
    
    this->m_comp_pawn_move = CreateDefaultSubobject<UFighterMovementComponent>( "Movement" );
    this->m_comp_pawn_move->SetUpdatedComponent( RootComponent );
    this->AutoPossessAI = EAutoPossessAI::Spawned;

    this->m_comp_namepanel = CreateDefaultSubobject<UFighterNamePanelComponent>( TEXT( "Name panel" ) );
    this->m_comp_namepanel->SetupAttachment( RootComponent );
    this->m_comp_namepanel->SetRelativeLocation( FVector( 0, 0, 120.0f ) );

}

UPawnMovementComponent* AFightActor::GetMovementComponent() const
{
    return this->m_comp_pawn_move;
}

// Called when the game starts or when spawned
void AFightActor::BeginPlay()
{
	AActor::BeginPlay();
}

// Called every frame
void AFightActor::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
    CHECK_TICK_TURNON_NORET;
    this->FighterTick( DeltaTime );
}

void AFightActor::LoadWarrior( UWarrior* warrior )
{
    this->m_o_warrior_binded = warrior;
    this->m_f_max_health = warrior->GetMaxSoldierNumber() * 1.0f;
    this->m_f_current_health = warrior->GetSoldierNumber() * 1.0f;
    this->m_f_attack_base = warrior->GetStrong() * 1.0;
}

AFightActor* AFightActor::SpawnWarrior( UWarrior* warrior, UWorld* inWorld )
{
    AFightActor* actor = nullptr;
    switch( warrior->GetWarriorType() )
    {
    case EWarriorType::SHIELD:
        actor = inWorld->SpawnActor<AShieldActor>();
        break;
    case EWarriorType::RIDER:
        actor = inWorld->SpawnActor<ARiderActor>();
        break;
    case EWarriorType::ARCHER:
        actor = inWorld->SpawnActor<AArcherActor>();
        break;
    default:
        return nullptr;
    }
    actor->LoadWarrior( warrior );
    return actor;
}

void AFightActor::BindReporter( AFightReporter* reporter )
{
    this->m_o_reporter = reporter;
}

float AFightActor::GetHealthPercent() const noexcept
{
    return this->m_f_current_health / this->m_f_max_health;
}

void AFightActor::SetAliveTarget( TArray<AFightActor*> all )
{
    AFightActor* target = this->SelectTarget( all );
    if( !target )
    {
        return;
    }
    if( this->GetDistanceTo( target ) < this->m_f_attack_range )
    {
        this->WantAttack( target );
    }
    else
    {
        this->WantMoveTo( target );
    }
}

AFightActor* AFightActor::SelectTarget( TArray<AFightActor*> all )
{
    AFightActor* target = nullptr;
    float distance = 0;
    for( auto item : all )
    {
        float d = target ? this->GetDistanceTo( item ) : 0;
        if( !target || (d < distance) )
        {
            target = item;
            distance = d;
        }
    }
    return target;
}

void AFightActor::WantAttack( AFightActor* targetActor )
{
    float now = this->GetWorld()->TimeSeconds;
    if( ( this->m_f_last_attack > 0 ) && ( now - this->m_f_last_attack < this->m_f_attack_cd ) )
    {
        return;
    }

    float damage = ( this->m_f_attack_base + RandomMaker::IntRange( -10, 10 ) )
        * this->GetAttackMagnification( targetActor->GetBindedWarrior()->GetWarriorType(), this->GetDistanceTo( targetActor ) );
    FDamageEvent de;
    if( targetActor->TakeDamage( damage, de, this->GetController(), this ) > 0 )
    {
        this->m_f_last_attack = now;
    }
}

void AFightActor::WantMoveTo( AFightActor* targetActor )
{
    auto ai = Cast<AAIController>( this->GetController() );
    if( ai )
    {
        ai->MoveToActor( targetActor );
    }
}

float AFightActor::TakeDamage( float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser )
{
    if( !this->m_o_reporter || !this->m_o_reporter->IsValidLowLevelFast() )
    {
        UE_LOG( LogTemp, Error, TEXT( "No fight reporter valid" ) );
        return 0;
    }
    UE_LOG( LogTemp, Display, TEXT( "%s been attacked, damage=%f, health=%f/%f, %f from attacker" ),
        *(this->m_o_warrior_binded->GetWarriorName()), DamageAmount, this->m_f_current_health, this->m_f_max_health,
        this->GetDistanceTo( DamageCauser ) );
    bool willBeKill = DamageAmount > this->m_f_current_health;
    float realDamage = willBeKill ? this->m_f_current_health : DamageAmount;
    if( !this->m_o_reporter->ReportDamage( this, Cast<AFightActor>( DamageCauser ), DamageAmount, willBeKill ) )
    {
        return 0;
    }
    if( willBeKill )
    {
        this->m_f_current_health = 0;
        this->m_o_warrior_binded->SetSoldierNumber( 0 );
        this->Destroy();
    }
    else
    {
        this->m_f_current_health -= DamageAmount;
        this->m_o_warrior_binded->SetSoldierNumber( ceil( this->m_f_current_health ) );
    }
    return realDamage;
}

float AFightActor::GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept
{
    return 1.0f;
}

UWarrior* AFightActor::GetBindedWarrior() const noexcept
{
    return this->m_o_warrior_binded;
}
