// Copyright Epic Games, Inc. All Rights Reserved.

#include "CozySpringJamGameMode.h"
#include "CozySpringJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACozySpringJamGameMode::ACozySpringJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
