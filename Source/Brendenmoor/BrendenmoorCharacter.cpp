// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Brendenmoor.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "BrendenmoorCharacter.h"

//////////////////////////////////////////////////////////////////////////
// ABrendenmoorCharacter

ABrendenmoorCharacter::ABrendenmoorCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	standardAttributes = CreateDefaultSubobject<UCStandardAttributes>(FName("StandardAttributes"));
	battleSystemComponent = CreateDefaultSubobject<UBattleSystemComponent>(FName("BattleSystem"));
	//targettingSystem = CreateDefaultSubobject<UTargettingSystemComponent>(FName("TargettingSystem"));

	AddOwnedComponent(standardAttributes);
	//AddOwnedComponent(targettingSystem);
}

void ABrendenmoorCharacter::GetAllCharactersInScene()
{
	TArray<AActor*> arrayFoundCharacters;
	TArray<AActor*> arrayCharactersToAdd;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABrendenmoorCharacter::StaticClass(), arrayFoundCharacters);

	for (int32 arrayLocation = 0; arrayLocation < arrayFoundCharacters.Num(); arrayLocation++)
	{
		if (arrayFoundCharacters[arrayLocation] != this)
		{
			arrayCharactersToAdd.Add(arrayFoundCharacters[arrayLocation]);
		}
	}

	UpdateCharacterArray(arrayCharactersToAdd);
}

void ABrendenmoorCharacter::UpdateCharacterArray(TArray<AActor*> pCharacterArray)
{
	targettingSystem->arrayAllLoadedCharacters = pCharacterArray;
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABrendenmoorCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABrendenmoorCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABrendenmoorCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABrendenmoorCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABrendenmoorCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ABrendenmoorCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ABrendenmoorCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ABrendenmoorCharacter::OnResetVR);
}


void ABrendenmoorCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ABrendenmoorCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ABrendenmoorCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ABrendenmoorCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABrendenmoorCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABrendenmoorCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ABrendenmoorCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ABrendenmoorCharacter::ToggleAutoAttack()
{
	if (battleSystemComponent->IsAttacking())
	{
		battleSystemComponent->StopAutoAttack();
	}
	else
	{
		if (autoAttackSkill)
		{
			battleSystemComponent->StartAutoAttack(autoAttackSkill);
		}
	}
}

void ABrendenmoorCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetAllCharactersInScene();
}

void ABrendenmoorCharacter::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}