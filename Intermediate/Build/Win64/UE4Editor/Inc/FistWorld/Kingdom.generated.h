// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FISTWORLD_Kingdom_generated_h
#error "Kingdom.generated.h already included, missing '#pragma once' in Kingdom.h"
#endif
#define FISTWORLD_Kingdom_generated_h

#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsPlayerKingdom) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPlayerKingdom(); \
		P_NATIVE_END; \
	}


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsPlayerKingdom) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPlayerKingdom(); \
		P_NATIVE_END; \
	}


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUKingdom(); \
	friend struct Z_Construct_UClass_UKingdom_Statics; \
public: \
	DECLARE_CLASS(UKingdom, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UKingdom)


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_INCLASS \
private: \
	static void StaticRegisterNativesUKingdom(); \
	friend struct Z_Construct_UClass_UKingdom_Statics; \
public: \
	DECLARE_CLASS(UKingdom, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UKingdom)


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UKingdom(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UKingdom) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKingdom); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKingdom); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKingdom(UKingdom&&); \
	NO_API UKingdom(const UKingdom&); \
public:


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UKingdom(UKingdom&&); \
	NO_API UKingdom(const UKingdom&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKingdom); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKingdom); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UKingdom)


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_PRIVATE_PROPERTY_OFFSET
#define FistWorld_Source_FistWorld_Story_Kingdom_h_22_PROLOG
#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_RPC_WRAPPERS \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_INCLASS \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FistWorld_Source_FistWorld_Story_Kingdom_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_INCLASS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_Story_Kingdom_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FISTWORLD_API UClass* StaticClass<class UKingdom>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FistWorld_Source_FistWorld_Story_Kingdom_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
