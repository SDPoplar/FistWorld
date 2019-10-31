// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FISTWORLD_TownActor_generated_h
#error "TownActor.generated.h already included, missing '#pragma once' in TownActor.h"
#endif
#define FISTWORLD_TownActor_generated_h

#define FistWorld_Source_FistWorld_Level_TownActor_h_14_RPC_WRAPPERS
#define FistWorld_Source_FistWorld_Level_TownActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define FistWorld_Source_FistWorld_Level_TownActor_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATownActor(); \
	friend struct Z_Construct_UClass_ATownActor_Statics; \
public: \
	DECLARE_CLASS(ATownActor, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(ATownActor)


#define FistWorld_Source_FistWorld_Level_TownActor_h_14_INCLASS \
private: \
	static void StaticRegisterNativesATownActor(); \
	friend struct Z_Construct_UClass_ATownActor_Statics; \
public: \
	DECLARE_CLASS(ATownActor, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(ATownActor)


#define FistWorld_Source_FistWorld_Level_TownActor_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATownActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATownActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATownActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATownActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATownActor(ATownActor&&); \
	NO_API ATownActor(const ATownActor&); \
public:


#define FistWorld_Source_FistWorld_Level_TownActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATownActor(ATownActor&&); \
	NO_API ATownActor(const ATownActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATownActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATownActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATownActor)


#define FistWorld_Source_FistWorld_Level_TownActor_h_14_PRIVATE_PROPERTY_OFFSET
#define FistWorld_Source_FistWorld_Level_TownActor_h_11_PROLOG
#define FistWorld_Source_FistWorld_Level_TownActor_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_RPC_WRAPPERS \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_INCLASS \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FistWorld_Source_FistWorld_Level_TownActor_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_INCLASS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Level_TownActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FISTWORLD_API UClass* StaticClass<class ATownActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FistWorld_Source_FistWorld_Level_TownActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
