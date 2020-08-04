// Fill out your copyright notice in the Description page of Project Settings.


#include "DelieveryBox.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ADelieveryBox::ADelieveryBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent >(TEXT("BoxMesh"));
	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	BoxMesh->AttachToComponent(RootComponent, ARules);
	MenuText = CreateDefaultSubobject<UTextRenderComponent>("MenuText");
	MenuText->SetupAttachment(RootComponent);
	MenuText->SetRelativeLocation(FVector(60, 20, -10));
	TimeLeft = 0;
	WorldTime = 0;
	
}

// Called when the game starts or when spawned
void ADelieveryBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADelieveryBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (DisplayMenu) 
	{
		switch (MenuItemEnum)
		{
		case MenuItem::AttemptToDeliever:
			MenuText->SetText(FText::FromString("Attempt TO Deliever"));
			break;
		case MenuItem::CheckDelieveyLabel:
			MenuText->SetText(FText::FromString("Check Delievery Label"));
			break;
		case MenuItem::GrabBox:
			MenuText->SetText(FText::FromString("Grab Box"));
			break;
		case MenuItem::ScanTicket:
			MenuText->SetText(FText::FromString("Scan Ticket"));
			break;

		case MenuItem::TimeLeft:
			MenuText->SetText(FText::Join(FText::FromString("Time Left: "), FText::AsNumber(TimeLeft)));
			break;

		default:
			break;
		}
	}
	else
	{
		
		MenuText->SetText(FText::FromString(""));
	}
	DisplayMenu = false;
}

void ADelieveryBox::CheckDestination()
{

}

void ADelieveryBox::CheckTimeLeft()
{
	TimeLeft = 0;
	TimeLeft = WorldTime - DelieveryTime;
}

void ADelieveryBox::AttemptToDeliever()
{
}

void ADelieveryBox::ScanTicket()
{
}

void ADelieveryBox::Destroy()
{
}

void ADelieveryBox::Damage()
{
}

void ADelieveryBox::CalculateScore()
{
}

void ADelieveryBox::ScrollMenuDown()
{
	
	MenuItemEnum == MenuItemEnum - 1;
} 
void ADelieveryBox::ScrollMenuUp()
{
	MenuItemEnum == MenuItemEnum + 1;
	
}
void ADelieveryBox::SelectMenuItem()
{
	switch (MenuItemEnum)
	{
		case MenuItem::AttemptToDeliever:
			AttemptToDeliever();
			break;

	default:
		break;
	}
}

