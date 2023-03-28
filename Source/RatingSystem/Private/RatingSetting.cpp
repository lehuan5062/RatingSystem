// Copyright 2023 Lê Vương Gia Huân

// RatingSystem
#include "RatingSetting.h"

// set category in project settings
URatingSetting::URatingSetting(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), StartingClientRating{ 5 }, MaxRating{ 10 }
{
	CategoryName = "Plugins";
}