#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EggPedestal.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COZYSPRINGJAM_API UEggPedestal : public USceneComponent
{
	GENERATED_BODY()

public:
	UEggPedestal();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EggPedestal")
		bool bPedestalActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EggPedestal")
		FName CheckTag;
	

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
		class UBoxComponent* TriggerBox;

	
};
