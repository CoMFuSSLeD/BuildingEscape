// Copyright Joe Fernandez 2016

#include "BuildingEscape.h"
#include "WinPlate.h"


// Sets default values for this component's properties
UWinPlate::UWinPlate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWinPlate::BeginPlay()
{
	Super::BeginPlay();

	ActorThatWins = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Pressure Plate"), *GetOwner()->GetName());
	}
	
	if (!ActorThatWins)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing Pawn"), *GetOwner()->GetName());
	}
	
}


// Called every frame
void UWinPlate::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the trigger volume every frame
	if (GetWinningActorsOnPlate())
	{
		OnWin.Broadcast();
	}
}

bool UWinPlate::GetWinningActorsOnPlate()
{
	bool IsWinner = false;

	if (!PressurePlate) { return IsWinner; }
	if (PressurePlate->IsOverlappingActor(ActorThatWins))
	{
		IsWinner = true;
	}

	return IsWinner;
}

