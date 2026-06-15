#pragma once

#include "CoreMinimal.h"
#include "EAresEquippableInput.generated.h"

UENUM(BlueprintType)
enum class EAresEquippableInput : uint8
{
	EquippableInput_Primary_Trigger    = 0,
	EquippableInput_Secondary_Trigger  = 1,
	EquippableInput_Reload             = 2,
	EquippableInput_ZoomToggle         = 3,
	EquippableInput_Use                = 4,
	EquippableInput_Drop                = 5,
	EquippableInput_Activate            = 6,
	EquippableInput_SwipeUp             = 7,
	EquippableInput_SwipeDown           = 8,
	EquippableInput_SwipeLeft           = 9,
	EquippableInput_SwipeRight          = 10,
	EquippableInput_Count               = 11,
	EquippableInput_Invalid             = 254,
};