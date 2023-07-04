// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Rog : ModuleRules
{
	public Rog(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] {  });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {"GameplayAbilities",
	        "GameplayTags",
	        "GameplayTasks",
	        "Core",
	        "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara",
	        "EnhancedInput",
        });
        PrivateDependencyModuleNames.AddRange(new string[]
        {
	        "GameplayMessageRuntime",
	        "UIExtension",
	        "CommonGame",
	        "CommonUser",
	        "ModularGameplayActors",
        });
    }
}
