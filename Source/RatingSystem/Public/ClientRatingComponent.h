// Copyright 2023 Lê Vương Gia Huân

#pragma once

// RatingSystem
#include "RatingComponent.h"

// std
#include <atomic>

// engine
#include "Components/ActorComponent.h"

//
#include "ClientRatingComponent.generated.h"

UCLASS()
class RATINGSYSTEM_API UClientRatingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UClientRatingComponent(const FObjectInitializer& ObjectInitializer);

	// to add rating
	const TWeakObjectPtr<URatingComponent> RatingComponent;

	// get client's rating
	// THREAD SAFE
	decltype(auto) GetRating() const noexcept;

	// set client's rating
	// 1 <= rating <= MaxRating
	// THREAD SAFE
	void SetRating(const int& star) noexcept;

	// add a rating point
	// 1 <= star
	// THREAD SAFE
	void AddStar(const unsigned int& star) noexcept;

	// remove a rating point
	// 1 <= star < rating
	// THREAD SAFE
	void RemoveStar(const unsigned int& star) noexcept;

	// add rating
	// multithreaded
	void rate() noexcept;

private:
	std::atomic_int rating;
};