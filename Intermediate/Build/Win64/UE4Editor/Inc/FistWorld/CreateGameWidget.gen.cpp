// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FistWorld/Widget/CreateGameWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCreateGameWidget() {}
// Cross Module References
	FISTWORLD_API UClass* Z_Construct_UClass_UCreateGameWidget_NoRegister();
	FISTWORLD_API UClass* Z_Construct_UClass_UCreateGameWidget();
	FISTWORLD_API UClass* Z_Construct_UClass_UPopupWidget();
	UPackage* Z_Construct_UPackage__Script_FistWorld();
// End Cross Module References
	void UCreateGameWidget::StaticRegisterNativesUCreateGameWidget()
	{
	}
	UClass* Z_Construct_UClass_UCreateGameWidget_NoRegister()
	{
		return UCreateGameWidget::StaticClass();
	}
	struct Z_Construct_UClass_UCreateGameWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCreateGameWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPopupWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_FistWorld,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCreateGameWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widget/CreateGameWidget.h" },
		{ "ModuleRelativePath", "Widget/CreateGameWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCreateGameWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCreateGameWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCreateGameWidget_Statics::ClassParams = {
		&UCreateGameWidget::StaticClass,
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
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCreateGameWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UCreateGameWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCreateGameWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCreateGameWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCreateGameWidget, 3991020194);
	template<> FISTWORLD_API UClass* StaticClass<UCreateGameWidget>()
	{
		return UCreateGameWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCreateGameWidget(Z_Construct_UClass_UCreateGameWidget, &UCreateGameWidget::StaticClass, TEXT("/Script/FistWorld"), TEXT("UCreateGameWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCreateGameWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
