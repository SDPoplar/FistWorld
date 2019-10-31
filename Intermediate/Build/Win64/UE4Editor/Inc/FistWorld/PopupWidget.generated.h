// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FISTWORLD_PopupWidget_generated_h
#error "PopupWidget.generated.h already included, missing '#pragma once' in PopupWidget.h"
#endif
#define FISTWORLD_PopupWidget_generated_h

#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPopup) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Popup(); \
		P_NATIVE_END; \
	}


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPopup) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Popup(); \
		P_NATIVE_END; \
	}


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPopupWidget(); \
	friend struct Z_Construct_UClass_UPopupWidget_Statics; \
public: \
	DECLARE_CLASS(UPopupWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UPopupWidget)


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUPopupWidget(); \
	friend struct Z_Construct_UClass_UPopupWidget_Statics; \
public: \
	DECLARE_CLASS(UPopupWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UPopupWidget)


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPopupWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPopupWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPopupWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPopupWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPopupWidget(UPopupWidget&&); \
	NO_API UPopupWidget(const UPopupWidget&); \
public:


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPopupWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPopupWidget(UPopupWidget&&); \
	NO_API UPopupWidget(const UPopupWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPopupWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPopupWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPopupWidget)


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_PRIVATE_PROPERTY_OFFSET
#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_12_PROLOG
#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_RPC_WRAPPERS \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_INCLASS \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_INCLASS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Widget_PopupWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FISTWORLD_API UClass* StaticClass<class UPopupWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FistWorld_Source_FistWorld_Widget_PopupWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
