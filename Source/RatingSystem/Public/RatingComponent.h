// Copyright 2023 Lê Vương Gia Huân

#pragma once

// std
#include <atomic>

// engine
#include "Components/ActorComponent.h"

//
#include "RatingComponent.generated.h"

UCLASS()
class RATINGSYSTEM_API URatingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URatingComponent(const FObjectInitializer& ObjectInitializer);

	// THREAD SAFE
	constexpr float&& GetAverageRating() const noexcept;

	// THREAD SAFE
	constexpr unsigned int&& GetRatingCount() const noexcept;

	// add rating and calculate average
	// 1 <= rating <= MaxRating
	// first rating will replace starting rating
	// multithreaded
	void AddRating(const unsigned int& rating) noexcept;

private:
	std::atomic<float> AverageRating;

	std::atomic_uint RatingCount;
};