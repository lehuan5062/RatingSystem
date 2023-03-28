// Copyright 2023 Lê Vương Gia Huân

// RatingSystem
#include "RatingComponent.h"
#include "RatingSetting.h"

// core
#include "Tasks/Task.h"

// default value
URatingComponent::URatingComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), AverageRating{ 3. }, RatingCount{} {}

// THREAD SAFE
constexpr float&& URatingComponent::GetAverageRating() const noexcept { return AverageRating; }

// THREAD SAFE
constexpr unsigned int&& URatingComponent::GetRatingCount() const noexcept { return RatingCount; }

// add rating and calculate average
// 1 <= rating <=5
// first rating will replace starting rating
// multithreaded
void URatingComponent::AddRating(const unsigned int& rating) noexcept
{
	UE::Tasks::Launch(UE_SOURCE_LOCATION, [this, &rating] {
		const auto&& count{ RatingCount.load() };
		static const auto&& MaxRating{ MoveTemp(GetMutableDefault<URatingSetting>()->MaxRating) };
		AverageRating = ((AverageRating * count) + FMath::Clamp(rating, 1, 5)) / (count + 1); });

	UE::Tasks::Launch(UE_SOURCE_LOCATION, [this] { RatingCount++; });
}