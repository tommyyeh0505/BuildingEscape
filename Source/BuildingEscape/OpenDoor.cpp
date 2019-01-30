// Copyright Tommy Yeh 2019

#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	UserCharacter = GetWorld()->GetFirstPlayerController()->GetPawn();
	//Get Owner
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();

	FRotator RotateDoor = FRotator(0.0f, OpenAngle, 0.0f);
	Owner->SetActorRotation(RotateDoor);
	UE_LOG(LogTemp, Warning, TEXT("DoorOpened"));
}

void UOpenDoor::CloseDoor()
{
	AActor* Owner = GetOwner();

	FRotator RotateDoor = FRotator(0.0f, 0.0f, 0.0f);
	Owner->SetActorRotation(RotateDoor);
	UE_LOG(LogTemp, Warning, TEXT("DoorClosed"));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate != NULL && UserCharacter != NULL) {
		if (PressurePlate->IsOverlappingActor(UserCharacter)) {
			if (!Triggered) {
				Triggered = true;
				if (Opened) {
					Opened = false;
					CloseDoor();

				}
				else {
					Opened = true;
					OpenDoor();
				}
			}
		} else {
			Triggered = false;
		}
	}
}

