// Fill out your copyright notice in the Description page of Project Settings.


#include "HTTPActorTest.h"
#include "Json.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"







// Sets default values
AHTTPActorTest::AHTTPActorTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHTTPActorTest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHTTPActorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHTTPActorTest::Test()
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &AHTTPActorTest::OnResponseReceived);
	Request->SetURL("https://jsonplaceholder.typicode.com/posts/1");
	Request->SetVerb("GET");
	Request->ProcessRequest();

}

void AHTTPActorTest::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());

	//FString testo = FString("prova");
	BPEvent(Response->GetContentAsString(),bConnectedSuccessfully);

	
}

