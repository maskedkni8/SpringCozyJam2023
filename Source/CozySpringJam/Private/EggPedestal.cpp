
#include "EggPedestal.h"
#include "Components/BoxComponent.h"

UEggPedestal::UEggPedestal()
{
    PrimaryComponentTick.bCanEverTick = false;

    // Create a trigger box
    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    TriggerBox->SetupAttachment(this);
    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerBox->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);
}


void UEggPedestal::BeginPlay()
{
    Super::BeginPlay();
    // Bind overlap events
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &UEggPedestal::OnOverlapBegin);
    TriggerBox->OnComponentEndOverlap.AddDynamic(this, &UEggPedestal::OnOverlapEnd);

    }

void UEggPedestal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    
    // If the overlapping actor is a certain type, activate the pedestal
    if (OtherActor->ActorHasTag(CheckTag))
    {
        bPedestalActive = true;
    }
    
}

void UEggPedestal::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    
    // If the overlapping actor was a certain type, deactivate the pedestal
    if (OtherActor->ActorHasTag(CheckTag))
    {
        bPedestalActive = false;
    }
   
}
 