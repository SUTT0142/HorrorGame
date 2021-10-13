// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorCharacter_LS.h"

// Sets default values
AHorrorCharacter_LS::AHorrorCharacter_LS()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHorrorCharacter_LS::BeginPlay()
{
	Super::BeginPlay();
	
	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using HorrorCharacter."));
}

// Called every frame
void AHorrorCharacter_LS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHorrorCharacter_LS::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AHorrorCharacter_LS::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHorrorCharacter_LS::MoveRight);

	// Set up "look" bindings.
	PlayerInputComponent->BindAxis("Turn", this, &AHorrorCharacter_LS::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AHorrorCharacter_LS::AddControllerPitchInput);

	// Set up "action" bindings.
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHorrorCharacter_LS::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AHorrorCharacter_LS::StopJump);
}

void AHorrorCharacter_LS::MoveForward(float Value)
{
    // Find out which way is "forward" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(Direction, Value);
}

void AHorrorCharacter_LS::MoveRight(float Value)
{
    // Find out which way is "right" and record that the player wants to move that way.
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}

