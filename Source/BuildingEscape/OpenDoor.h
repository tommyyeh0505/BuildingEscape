// Copyright Tommy Yeh 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoorForSetInterval();

	void OpenCloseDoorTick();

		
private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = -80.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* UserCharacter;

	UPROPERTY(EditAnywhere)
	bool Opened = false;

	UPROPERTY(EditAnywhere)
	bool Triggered = false;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.5f;

	float DoorLastOpenedTime = 0.0f;
};
