// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FistWorld/Widget/PopupWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePopupWidget() {}
// Cross Module References
	FISTWORLD_API UClass* Z_Construct_UClass_UPopupWidget_NoRegister();
	FISTWORLD_API UClass* Z_Construct_UClass_UPopupWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_FistWorld();
	FISTWORLD_API UFunction* Z_Construct_UFunction_UPopupWidget_Popup();
// End Cross Module References
	void UPopupWidget::StaticRegisterNativesUPopupWidget()
	{
		UClass* Class = UPopupWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Popup", &UPopupWidget::execPopup },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPopupWidget_Popup_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPopupWidget_Popup_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Widget/PopupWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPopupWidget_Popup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPopupWidget, nullptr, "Popup", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPopupWidget_Popup_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UPopupWidget_Popup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPopupWidget_Popup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPopupWidget_Popup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPopupWidget_NoRegister()
	{
		return UPopupWidget::StaticClass();
	}
	struct Z_Construct_UClass_UPopupWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPopupWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_FistWorld,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPopupWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPopupWidget_Popup, "Popup" }, // 3867218339
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPopupWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widget/PopupWidget.h" },
		{ "ModuleRelativePath", "Widget/PopupWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPopupWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPopupWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPopupWidget_Statics::ClassParams = {
		&UPopupWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPopupWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UPopupWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPopupWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPopupWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPopupWidget, 3947419942);
	template<> FISTWORLD_API UClass* StaticClass<UPopupWidget>()
	{
		return UPopupWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPopupWidget(Z_Construct_UClass_UPopupWidget, &UPopupWidget::StaticClass, TEXT("/Script/FistWorld"), TEXT("UPopupWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPopupWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
