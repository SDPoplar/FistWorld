// Copyright 2019

#include "ViewportEdgeWidget.h"

UViewportEdgeWidget::UViewportEdgeWidget( const FObjectInitializer& ObjectInitializer )
    : UUserWidget( ObjectInitializer ), m_b_move_flag( false )
{
    this->Visibility = ESlateVisibility::Visible;
}

ACommonMapController* UViewportEdgeWidget::GetController() const noexcept
{
    return Cast<ACommonMapController>( this->GetOwningPlayer() );
}

bool UViewportEdgeWidget::CanMoveTowads() const noexcept
{
    auto pc = bindedEdgeSide.Num() ? this->GetController() : nullptr;
    if( !pc )
    {
        return false;
    }
    for( auto side : this->bindedEdgeSide )
    {
        if( !pc->IsViewportEdgeLocked( side ) )
        {
            return true;
        }
    }
    return false;
}

void UViewportEdgeWidget::TurnOnMove()
{
    this->m_b_move_flag = true;
}

void UViewportEdgeWidget::TurnOffMove()
{
    this->m_b_move_flag = false;
}

void UViewportEdgeWidget::MoveIfTurnedOn()
{
    auto pc = this->m_b_move_flag ? this->GetController() : nullptr;
    if( !pc )
    {
        return;
    }
    for( auto side : this->bindedEdgeSide )
    {
        if( !pc->IsViewportEdgeLocked( side ) )
        {
            pc->MoveTowardsViewportEdge( side );
        }
    }
}
