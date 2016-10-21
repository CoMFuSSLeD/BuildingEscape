// Copyright Joe Fernandez 2016

#pragma once

#include "Components/ActorComponent.h"
#include "WinPlate.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWinEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UWinPlate : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWinPlate();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	bool GetWinningActorsOnPlate();

	UPROPERTY(BlueprintAssignable)
	FWinEvent OnWin;

private:

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;
	
	UPROPERTY(EditAnywhere)
	AActor* ActorThatWins = nullptr;
};
