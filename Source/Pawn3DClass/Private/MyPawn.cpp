#include "MyPawn.h"
#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"

AMyPawn::AMyPawn()
{
 	PrimaryActorTick.bCanEverTick = true;

}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	
}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Move
				);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AMyPawn::Look
				);
			}
		}

	}
}

void AMyPawn::Move(const FInputActionValue& value) {
	if (!Controller) return;
	const FVector2D MoveInput = value.Get<FVector2D>();

	if(!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
		UE_LOG(LogTemp, Warning, TEXT("Move X"));
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
		UE_LOG(LogTemp, Warning, TEXT("Move Y"));
	}
}

void AMyPawn::Look(const FInputActionValue& value) {

	FVector2D LookInput = value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Look"));
	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}