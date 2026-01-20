#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

struct FInputActionValue;

UCLASS()
class PAWN3DCLASS_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

	

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void Move(const FInputActionValue& value);

	UFUNCTION()
	void Look(const FInputActionValue& value);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
