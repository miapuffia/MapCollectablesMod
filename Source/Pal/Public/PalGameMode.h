#pragma once
#include "CoreMinimal.h"
#include "PalGameModeBase.h"
#include "PalGameMode.generated.h"

class APlayerStart;
class UPocketpairUserInfo;

UCLASS(Blueprintable, NonTransient)
class PAL_API APalGameMode : public APalGameModeBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerStart* CachePlayerStart;
    
public:
    APalGameMode(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RestartGame();
    
    UFUNCTION(BlueprintCallable)
    void RespawnPlayer(int32 PlayerIndex);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateSession(const FString& ResponseBody, bool bResponseOK, int32 ResponseCode);
    
    UFUNCTION(BlueprintCallable)
    void OnServerLobbyUpdate() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEOSLoginDedicatedServerComplete(const UPocketpairUserInfo* UserInfo, bool bSuccess, const FString& ErrorStr);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCompleteCreateSession(const FString& ResponseBody, bool bResponseOK, int32 ResponseCode);
    
public:
    UFUNCTION(BlueprintCallable)
    void InitDedicatedServer();
    
protected:
    UFUNCTION(BlueprintCallable)
    APlayerStart* FindPlayerStartWithTag(const FName& Tag);
    
private:
    UFUNCTION(BlueprintCallable)
    void CreateSession(const FString& Address);
    
};

