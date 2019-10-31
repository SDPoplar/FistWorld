// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FISTWORLD_MainMenu_generated_h
#error "MainMenu.generated.h already included, missing '#pragma once' in MainMenu.h"
#endif
#define FISTWORLD_MainMenu_generated_h

#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execExitGame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExitGame(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasGame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasGame(); \
		P_NATIVE_END; \
	}


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execExitGame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ExitGame(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasGame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasGame(); \
		P_NATIVE_END; \
	}


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMainMenu(); \
	friend struct Z_Construct_UClass_UMainMenu_Statics; \
public: \
	DECLARE_CLASS(UMainMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UMainMenu)


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUMainMenu(); \
	friend struct Z_Construct_UClass_UMainMenu_Statics; \
public: \
	DECLARE_CLASS(UMainMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UMainMenu)


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMainMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainMenu) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainMenu); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainMenu); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMainMenu(UMainMenu&&); \
	NO_API UMainMenu(const UMainMenu&); \
public:


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMainMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMainMenu(UMainMenu&&); \
	NO_API UMainMenu(const UMainMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainMenu); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainMenu); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainMenu)


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_PRIVATE_PROPERTY_OFFSET
#define FistWorld_Source_FistWorld_Widget_MainMenu_h_12_PROLOG
#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_RPC_WRAPPERS \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_INCLASS \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FistWorld_Source_FistWorld_Widget_MainMenu_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_INCLASS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Widget_MainMenu_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FISTWORLD_API UClass* StaticClass<class UMainMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FistWorld_Source_FistWorld_Widget_MainMenu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
