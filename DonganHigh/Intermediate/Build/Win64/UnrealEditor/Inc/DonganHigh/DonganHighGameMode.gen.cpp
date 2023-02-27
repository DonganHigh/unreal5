// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonganHigh/DonganHighGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDonganHighGameMode() {}
// Cross Module References
	DONGANHIGH_API UClass* Z_Construct_UClass_ADonganHighGameMode_NoRegister();
	DONGANHIGH_API UClass* Z_Construct_UClass_ADonganHighGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_DonganHigh();
// End Cross Module References
	void ADonganHighGameMode::StaticRegisterNativesADonganHighGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADonganHighGameMode);
	UClass* Z_Construct_UClass_ADonganHighGameMode_NoRegister()
	{
		return ADonganHighGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ADonganHighGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADonganHighGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_DonganHigh,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADonganHighGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "DonganHighGameMode.h" },
		{ "ModuleRelativePath", "DonganHighGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADonganHighGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADonganHighGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADonganHighGameMode_Statics::ClassParams = {
		&ADonganHighGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ADonganHighGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADonganHighGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADonganHighGameMode()
	{
		if (!Z_Registration_Info_UClass_ADonganHighGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADonganHighGameMode.OuterSingleton, Z_Construct_UClass_ADonganHighGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADonganHighGameMode.OuterSingleton;
	}
	template<> DONGANHIGH_API UClass* StaticClass<ADonganHighGameMode>()
	{
		return ADonganHighGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADonganHighGameMode);
	struct Z_CompiledInDeferFile_FID_DonganHigh_Source_DonganHigh_DonganHighGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DonganHigh_Source_DonganHigh_DonganHighGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADonganHighGameMode, ADonganHighGameMode::StaticClass, TEXT("ADonganHighGameMode"), &Z_Registration_Info_UClass_ADonganHighGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADonganHighGameMode), 192347640U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DonganHigh_Source_DonganHigh_DonganHighGameMode_h_2127976875(TEXT("/Script/DonganHigh"),
		Z_CompiledInDeferFile_FID_DonganHigh_Source_DonganHigh_DonganHighGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DonganHigh_Source_DonganHigh_DonganHighGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
