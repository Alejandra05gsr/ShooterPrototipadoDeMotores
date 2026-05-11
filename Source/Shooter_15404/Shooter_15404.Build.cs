// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Shooter_15404 : ModuleRules
{
	public Shooter_15404(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Shooter_15404",
			"Shooter_15404/Variant_Platforming",
			"Shooter_15404/Variant_Platforming/Animation",
			"Shooter_15404/Variant_Combat",
			"Shooter_15404/Variant_Combat/AI",
			"Shooter_15404/Variant_Combat/Animation",
			"Shooter_15404/Variant_Combat/Gameplay",
			"Shooter_15404/Variant_Combat/Interfaces",
			"Shooter_15404/Variant_Combat/UI",
			"Shooter_15404/Variant_SideScrolling",
			"Shooter_15404/Variant_SideScrolling/AI",
			"Shooter_15404/Variant_SideScrolling/Gameplay",
			"Shooter_15404/Variant_SideScrolling/Interfaces",
			"Shooter_15404/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
