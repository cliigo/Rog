#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogRog, Log, All);

#define ROG_LOG(Text) UE_LOG(LogRog, Log, TEXT(Text));

