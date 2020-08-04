// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnvironmentController.generated.h"

UCLASS()
class PROJECTAJAX_API AEnvironmentController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnvironmentController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enviroment")
		 float WorldTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enviroment")
		float TimeAcceleration;
};
