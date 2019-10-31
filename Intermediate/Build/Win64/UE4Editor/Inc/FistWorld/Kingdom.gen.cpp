// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FistWorld/Story/Kingdom.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKingdom() {}
// Cross Module References
	FISTWORLD_API UClass* Z_Construct_UClass_UKingdom_NoRegister();
	FISTWORLD_API UClass* Z_Construct_UClass_UKingdom();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_FistWorld();
	FISTWORLD_API UFunction* Z_Construct_UFunction_UKingdom_IsPlayerKingdom();
// End Cross Module References
	void UKingdom::StaticRegisterNativesUKingdom()
	{
		UClass* Class = UKingdom::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsPlayerKingdom", &UKingdom::execIsPlayerKingdom },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics
	{
		struct Kingdom_eventIsPlayerKingdom_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Kingdom_eventIsPlayerKingdom_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Kingdom_eventIsPlayerKingdom_Parms), &Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Story/Kingdom.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKingdom, nullptr, "IsPlayerKingdom", nullptr, nullptr, sizeof(Kingdom_eventIsPlayerKingdom_Parms), Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UKingdom_IsPlayerKingdom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UKingdom_IsPlayerKingdom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UKingdom_NoRegister()
	{
		return UKingdom::StaticClass();
	}
	struct Z_Construct_UClass_UKingdom_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKingdom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_FistWorld,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UKingdom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UKingdom_IsPlayerKingdom, "IsPlayerKingdom" }, // 600145224
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKingdom_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Story/Kingdom.h" },
		{ "ModuleRelativePath", "Story/Kingdom.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKingdom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKingdom>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UKingdom_Statics::ClassParams = {
		&UKingdom::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UKingdom_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UKingdom_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UKingdom()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UKingdom_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UKingdom, 518433114);
	template<> FISTWORLD_API UClass* StaticClass<UKingdom>()
	{
		return UKingdom::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UKingdom(Z_Construct_UClass_UKingdom, &UKingdom::StaticClass, TEXT("/Script/FistWorld"), TEXT("UKingdom"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKingdom);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
