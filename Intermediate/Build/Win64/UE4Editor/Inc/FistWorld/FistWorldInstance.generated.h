// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FISTWORLD_FistWorldInstance_generated_h
#error "FistWorldInstance.generated.h already included, missing '#pragma once' in FistWorldInstance.h"
#endif
#define FISTWORLD_FistWorldInstance_generated_h

#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_RPC_WRAPPERS
#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFistWorldInstance(); \
	friend struct Z_Construct_UClass_UFistWorldInstance_Statics; \
public: \
	DECLARE_CLASS(UFistWorldInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UFistWorldInstance)


#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUFistWorldInstance(); \
	friend struct Z_Construct_UClass_UFistWorldInstance_Statics; \
public: \
	DECLARE_CLASS(UFistWorldInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/FistWorld"), NO_API) \
	DECLARE_SERIALIZER(UFistWorldInstance)


#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFistWorldInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFistWorldInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFistWorldInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFistWorldInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFistWorldInstance(UFistWorldInstance&&); \
	NO_API UFistWorldInstance(const UFistWorldInstance&); \
public:


#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFistWorldInstance(UFistWorldInstance&&); \
	NO_API UFistWorldInstance(const UFistWorldInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFistWorldInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFistWorldInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFistWorldInstance)


#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_PRIVATE_PROPERTY_OFFSET
#define FistWorld_Source_FistWorld_FistWorldInstance_h_14_PROLOG
#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_RPC_WRAPPERS \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_INCLASS \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FistWorld_Source_FistWorld_FistWorldInstance_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_PRIVATE_PROPERTY_OFFSET \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_INCLASS_NO_PURE_DECLS \
	FistWorld_Source_FistWorld_FistWorldInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FISTWORLD_API UClass* StaticClass<class UFistWorldInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FistWorld_Source_FistWorld_FistWorldInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
