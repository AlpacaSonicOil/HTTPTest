// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpActorTestJSON.generated.h"


USTRUCT()
struct FTest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int userId;

	UPROPERTY()
	int id;

	UPROPERTY()
	FString title;

	UPROPERTY()
	FString body;
};




UCLASS()
class HTTPTEST_API AHttpActorTestJSON : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHttpActorTestJSON();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Test();

	UFUNCTION(BlueprintImplementableEvent)
	void BPEvent(const FString &text, bool success, const FString &textJSON);

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

	FTest PersonJSON;
	
};


