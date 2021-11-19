// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class GALAXY_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStar();

	UPROPERTY(VisibleAnywhere,Category = "StaticMesh")
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vectors")
	FVector InitialLocation;
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite,Category = "Surround")
	AActor* Sun;
	//UPROPERTY(EditInstanceOnly,Category = "Surround")
	//float OrbitRadius;
	UPROPERTY(EditInstanceOnly, Category = "Surround")
	bool bIsSun;
	UPROPERTY(EditInstanceOnly, Category = "Surround")
	bool bIsSurrounding;
	UPROPERTY(EditInstanceOnly, Category = "Surround")
	bool bIsRing;
	UPROPERTY(EditAnywhere, Category = "Surround|OrbitShape")
	float LongAxis;
	UPROPERTY(EditAnywhere, Category = "Surround|OrbitShape")
	float ShortAxis;
	UPROPERTY(EditAnywhere, Category = "Surround|OrbitShape")
	float TimeStretch;
	UPROPERTY(EditAnywhere, Category = "Surround|Vector")
	FVector InitVector;
	UPROPERTY(EditAnywhere, Category = "Surround|Vector")
	FRotator SelfRotationVector;
	UPROPERTY(EditAnywhere, Category = "Surround|RoundSpeed")
	float RingRotatorSpeed;

	FVector S_Location;
	int i;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float RunningTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
