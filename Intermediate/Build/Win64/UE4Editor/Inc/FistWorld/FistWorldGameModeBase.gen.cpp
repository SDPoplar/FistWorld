// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FistWorld/FistWorldGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFistWorldGameModeBase() {}
// Cross Module References
	FISTWORLD_API UClass* Z_Construct_UClass_AFistWorldGameModeBase_NoRegister();
	FISTWORLD_API UClass* Z_Construct_UClass_AFistWorldGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FistWorld();
// End Cross Module References
	void AFistWorldGameModeBase::StaticRegisterNativesAFistWorldGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AFistWorldGameModeBase_NoRegister()
	{
		return AFistWorldGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AFistWorldGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFistWorldGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FistWorld,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFistWorldGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FistWorldGameModeBase.h" },
		{ "ModuleRelativePath", "FistWorldGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFistWorldGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFistWorldGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFistWorldGameModeBase_Statics::ClassParams = {
		&AFistWorldGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_AFistWorldGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AFistWorldGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFistWorldGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFistWorldGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFistWorldGameModeBase, 3317668642);
	template<> FISTWORLD_API UClass* StaticClass<AFistWorldGameModeBase>()
	{
		return AFistWorldGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFistWorldGameModeBase(Z_Construct_UClass_AFistWorldGameModeBase, &AFistWorldGameModeBase::StaticClass, TEXT("/Script/FistWorld"), TEXT("AFistWorldGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFistWorldGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
