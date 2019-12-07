// Copyright 2019

#include "ViewportEdgeLocker.h"
#include "GameFramework/Pawn.h"

AViewportEdgeLocker::AViewportEdgeLocker( const FObjectInitializer& ObjectInitializer ) : ATriggerBox( ObjectInitializer )
{
    FScriptDelegate in, out;
    in.BindUFunction( this, "ActorIn" );
    this->OnActorBeginOverlap.Add( in );
    out.BindUFunction( this, "ActorOut" );
    this->OnActorEndOverlap.Add( out );
}

void AViewportEdgeLocker::ActorIn( AActor*, AActor* other )
{
    APawn* pawn = Cast<APawn>( other );
    auto pc = pawn ? Cast<ACommonMapController>( pawn->GetController() ) : nullptr;
    if( pc )
    {
        pc->SetEdgeLock( this->bindEdge, true );
    }
}

void AViewportEdgeLocker::ActorOut( AActor*, AActor* other )
{
    APawn* pawn = Cast<APawn>( other );
    auto pc = pawn ? Cast<ACommonMapController>( pawn->GetController() ) : nullptr;
    if( pc )
    {
        pc->SetEdgeLock( this->bindEdge, false );
    }
}
