// Copyright 2023 Lê Vương Gia Huân

// RatingSystem
#include "ClientRatingComponent.h"
#include "RatingSetting.h"

// default value
UClientRatingComponent::UClientRatingComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), rating{ GetMutableDefault<URatingSetting>()->StartingClientRating } {}

// get client's rating
// THREAD SAFE
decltype(auto) UClientRatingComponent::GetRating() const noexcept
{
	static const auto&& MaxRating{ MoveTemp(GetMutableDefault<URatingSetting>()->MaxRating) };
	return FMath::Clamp(rating, 1, MaxRating);
}

// set client's rating
// THREAD SAFE
void UClientRatingComponent::SetRating(const int& star) noexcept { rating = star; }

// add a rating point
// 1 <= star
// THREAD SAFE
void UClientRatingComponent::AddStar(const unsigned int& star = 1) noexcept { rating += star; }

// remove a rating point
// 1 <= star < rating
// THREAD SAFE
void UClientRatingComponent::RemoveStar(const unsigned int& star = 1) noexcept { rating -= star; }

// add rating
// multithreaded
void UClientRatingComponent::rate() noexcept
{
	checkSlow(RatingComponent.IsValid()) RatingComponent->AddRating(GetRating());
}