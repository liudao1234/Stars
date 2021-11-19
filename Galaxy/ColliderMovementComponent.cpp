// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
		return;
	}

	FVector DisiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f)*10.f;

	if (!DisiredMovementThisFrame.IsNearlyZero()) {
		FHitResult Hit;
		SafeMoveUpdatedComponent(DisiredMovementThisFrame, UpdatedComponent->GetComponentRotation(),true,Hit);
		if (Hit.IsValidBlockingHit()) {
			SlideAlongSurface(DisiredMovementThisFrame, 1.0 - Hit.Time, Hit.Normal, Hit);
		}
	}
}
