// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpActorTestJSON.h"

#include "HTTPActorTest.h"
#include "Json.h"
#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

// Sets default values
AHttpActorTestJSON::AHttpActorTestJSON()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHttpActorTestJSON::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHttpActorTestJSON::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHttpActorTestJSON::Test()
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &AHttpActorTestJSON::OnResponseReceived);
	Request->SetURL("https://jsonplaceholder.typicode.com/posts/1");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void AHttpActorTestJSON::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	const FString content = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct(content, &PersonJSON,0,0);

	const FString text = PersonJSON.body;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, text);

	BPEvent(Response->GetContentAsString(),bConnectedSuccessfully, text);

}

