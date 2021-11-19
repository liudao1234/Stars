// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"
#include <cmath>
// Sets default values
AStar::AStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f, 0.0f, 0.0f);
	//OrbitRadius = 100.0f;
	RunningTime = 0.0f;
	LongAxis = ShortAxis = 100.0f;
	TimeStretch = 1.0f;
	SelfRotationVector = FRotator(0.0f, 0.0f, 30.0f);
	RingRotatorSpeed = 0.1f;
}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(InitialLocation);
	i = 0;
}

// Called every frame
void AStar::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();

	if (bIsSurrounding && !bIsSun&& (Sun != NULL)) {
		//如果自己是行星就公转并自转
		//公转
		S_Location = Sun->GetActorLocation();
		NewLocation.X = LongAxis * FMath::Sin(TimeStretch * RunningTime) + S_Location.X;
		NewLocation.Y = ShortAxis * FMath::Cos(TimeStretch * RunningTime) + S_Location.Y;
		SetActorLocation(NewLocation);
		//自转
		AddActorLocalRotation(SelfRotationVector, false);

		RunningTime += DeltaTime;
	}
	else if (bIsSun) {
		//如果自己是太阳就自转
		AddActorLocalRotation(SelfRotationVector, false);

		RunningTime += DeltaTime;
	}
	else if(bIsRing){
		i++;
		float LocalRotation = FMath::FRand() - 0.5f;
		float RotationX = RingRotatorSpeed * FMath::FRandRange(0.0f, 10.0f);
		float RotationY = RingRotatorSpeed * FMath::FRandRange(0.0f, 10.0f);
		float RotationZ = RingRotatorSpeed * FMath::FRandRange(0.0f, 10.0f);
		if (i > 120) {
			//AddActorLocalRotation(SelfRotationVector * LocalRotation, false);
			SelfRotationVector = FRotator(RotationX, RotationY, RotationZ);
			i = 0;
		}
		
		
		AddActorWorldRotation(SelfRotationVector, false);
		
		RunningTime += DeltaTime;
	}
}

