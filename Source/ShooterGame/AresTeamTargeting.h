#pragma once

#include "CoreMinimal.h"
#include "AresTeamTargeting.generated.h"

UENUM(BlueprintType)
enum class EAresTeamTargeting : uint8
{
	TeamTargeting_ApplyToEveryone          = 0,
	TeamTargeting_ApplyToFriends           = 1,
	TeamTargeting_ApplyToEnemies           = 2,
	TeamTargeting_ApplyToSelfAndEnemies    = 3,
	TeamTargeting_ApplyToNoone              = 4,
	TeamTargeting_Count                     = 5,
};