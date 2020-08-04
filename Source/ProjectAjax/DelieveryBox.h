// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelieveryBox.generated.h"
UENUM()
enum MenuItem
{
	GrabBox     UMETA(DisplayName = "Grab Box"),
	CheckDelieveyLabel      UMETA(DisplayName = "Check Delievey Label"),
	TimeLeft   UMETA(DisplayName = "Time Left"),
	ScanTicket  UMETA(DisplayName = "Scan Ticket"),
	AttemptToDeliever UMETA(DisplayName = "Attempt To Deliever"),
};
UCLASS()
class PROJECTAJAX_API ADelieveryBox : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADelieveryBox();

	UFUNCTION(BlueprintCallable)
		void CheckDestination();

	UFUNCTION(BlueprintCallable)
		void CheckTimeLeft();

	UFUNCTION(BlueprintCallable)
		void AttemptToDeliever();

	UFUNCTION(BlueprintCallable)
		void ScanTicket();

	UFUNCTION(BlueprintCallable)
		void Destroy();

	UFUNCTION(BlueprintCallable)
		void Damage();

	UFUNCTION(BlueprintCallable)
		void CalculateScore();

	UFUNCTION(BlueprintCallable)
		void ScrollMenuDown();

	UFUNCTION(BlueprintCallable)
		void ScrollMenuUp();

	UFUNCTION(BlueprintCallable)
		void SelectMenuItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float DistanceToDestination;
	float EstimatedTime;
	bool TicketScanned = false;

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enviroment")
		float& WorldTime = EstimatedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
		bool DisplayMenu;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
		class UTextRenderComponent* MenuText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
		TEnumAsByte<MenuItem> MenuItemEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		class UStaticMeshComponent* BoxMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delievey Details")
		FText Ticket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delievey Details")
		float TimeLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delievey Details")
		float DelieveryTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Delievey Details")
		AActor* BoxDestination;

};
