// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FistWorld/FistWorldInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFistWorldInstance() {}
// Cross Module References
	FISTWORLD_API UClass* Z_Construct_UClass_UFistWorldInstance_NoRegister();
	FISTWORLD_API UClass* Z_Construct_UClass_UFistWorldInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_FistWorld();
// End Cross Module References
	void UFistWorldInstance::StaticRegisterNativesUFistWorldInstance()
	{
	}
	UClass* Z_Construct_UClass_UFistWorldInstance_NoRegister()
	{
		return UFistWorldInstance::StaticClass();
	}
	struct Z_Construct_UClass_UFistWorldInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFistWorldInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_FistWorld,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFistWorldInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "FistWorldInstance.h" },
		{ "ModuleRelativePath", "FistWorldInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFistWorldInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFistWorldInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFistWorldInstance_Statics::ClassParams = {
		&UFistWorldInstance::StaticClass,
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
		0x001000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UFistWorldInstance_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UFistWorldInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFistWorldInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFistWorldInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFistWorldInstance, 2745726834);
	template<> FISTWORLD_API UClass* StaticClass<UFistWorldInstance>()
	{
		return UFistWorldInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFistWorldInstance(Z_Construct_UClass_UFistWorldInstance, &UFistWorldInstance::StaticClass, TEXT("/Script/FistWorld"), TEXT("UFistWorldInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFistWorldInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
