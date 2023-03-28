// Copyright 2023 Lê Vương Gia Huân

#pragma once

// DeveloperSettings
#include "Engine/DeveloperSettings.h"

//
#include "RatingSetting.generated.h"

UCLASS(config = RatingSystem, DefaultConfig)
class RATINGSYSTEM_API URatingSetting : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	// set category in project settings
	URatingSetting(const FObjectInitializer& ObjectInitializer);

	// the starting rating from new client
	UPROPERTY(category = RatingSystem, config, EditAnywhere, meta = (ConfigRestartRequired = true, ClampMin = "1", UIMin = "1"))
		int StartingClientRating;

	UPROPERTY(category = RatingSystem, config, EditAnywhere, meta = (ConfigRestartRequired = true, ClampMin = "1", UIMin = "1"))
		int MaxRating;
};