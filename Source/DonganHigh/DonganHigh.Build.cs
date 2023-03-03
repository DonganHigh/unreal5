// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DonganHigh : ModuleRules
{
	public DonganHigh(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add(ModuleDirectory);

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "UMG", "GameplayTasks" });
    }
}
