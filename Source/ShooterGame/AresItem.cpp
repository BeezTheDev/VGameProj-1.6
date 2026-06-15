#include "AresItem.h"
#include "Net/UnrealNetwork.h"

FString AAresItem::GetAssetServiceIDFromClass(const UObject* WorldContextObject, UClass* ItemClass)
{
	return FString();
}

void AAresItem::AuthDestroyInternal()
{
}

void AAresItem::AuthRemoveAndDestroy(EInventoryTransaction TransactionType)
{
}

void AAresItem::AuthSetOwnerTo(AActor* NewOwner)
{
}

FString AAresItem::GetAssetServiceID()
{
	return FString();
}

int32 AAresItem::GetSellPrice(int32 BasePrice)
{
	return BasePrice;
}

void AAresItem::OverrideUIData(TSubclassOf<UBaseContentUIData> OverriddenUIData)
{
}

void AAresItem::ReceiveAuthClearOwningCharacter_Implementation(AShooterCharacter* OldCharacter)
{
}

void AAresItem::ReceiveAuthSetOwningCharacter_Implementation(AShooterCharacter* NewCharacter)
{
}

void AAresItem::ReceiveClientClearOwningCharacter_Implementation(AShooterCharacter* OldCharacter)
{
}

void AAresItem::ReceiveClientSetOwningCharacter_Implementation(AShooterCharacter* NewCharacter)
{
}

void AAresItem::ClientDebugDrawTextOnScreen(const FString& DrawText, const FLinearColor& DrawColor, float DurationOverride) const
{
}

UTexture* AAresItem::GetItemIcon() const
{
	return nullptr;
}

FText AAresItem::GetItemNameText() const
{
	return FText::GetEmpty();
}

EAresItemSlot AAresItem::GetItemSlot() const
{
	return EquippableSlot;
}

FText AAresItem::GetItemTooltipText() const
{
	return FText::GetEmpty();
}

FString AAresItem::GetOriginalOwnerId() const
{
	return OriginalOwnerId;
}

FString AAresItem::GetOriginalOwnerName() const
{
	return OriginalOwnerName;
}

AShooterCharacter* AAresItem::GetPawnOwner() const
{
	return MyPawn;
}

bool AAresItem::IsEquippable() const
{
	return false;
}

void AAresItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAresItem, OriginalOwnerName);
}