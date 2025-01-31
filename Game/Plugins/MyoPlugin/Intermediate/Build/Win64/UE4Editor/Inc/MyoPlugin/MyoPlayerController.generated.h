// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRotator;
class UMyoController;
#ifdef MYOPLUGIN_MyoPlayerController_generated_h
#error "MyoPlayerController.generated.h already included, missing '#pragma once' in MyoPlayerController.h"
#endif
#define MYOPLUGIN_MyoPlayerController_generated_h

#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConvertToMyoOrientationSpace) \
	{ \
		P_GET_STRUCT(FRotator,Z_Param_orientation); \
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_converted); \
		P_FINISH; \
		this->ConvertToMyoOrientationSpace(Z_Param_orientation,Z_Param_Out_converted); \
	} \
 \
	DECLARE_FUNCTION(execPrimaryMyo) \
	{ \
		P_FINISH; \
		*(UMyoController**)Z_Param__Result=this->PrimaryMyo(); \
	} \
 \
	DECLARE_FUNCTION(execRightMyo) \
	{ \
		P_FINISH; \
		*(UMyoController**)Z_Param__Result=this->RightMyo(); \
	} \
 \
	DECLARE_FUNCTION(execLeftMyo) \
	{ \
		P_FINISH; \
		*(UMyoController**)Z_Param__Result=this->LeftMyo(); \
	} \
 \
	DECLARE_FUNCTION(execSetLockingPolicy) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_policy); \
		P_FINISH; \
		this->SetLockingPolicy(MyoLockingPolicy(Z_Param_policy)); \
	} \
 \
	DECLARE_FUNCTION(execIsHubEnabled) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->IsHubEnabled(); \
	}


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConvertToMyoOrientationSpace) \
	{ \
		P_GET_STRUCT(FRotator,Z_Param_orientation); \
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_converted); \
		P_FINISH; \
		this->ConvertToMyoOrientationSpace(Z_Param_orientation,Z_Param_Out_converted); \
	} \
 \
	DECLARE_FUNCTION(execPrimaryMyo) \
	{ \
		P_FINISH; \
		*(UMyoController**)Z_Param__Result=this->PrimaryMyo(); \
	} \
 \
	DECLARE_FUNCTION(execRightMyo) \
	{ \
		P_FINISH; \
		*(UMyoController**)Z_Param__Result=this->RightMyo(); \
	} \
 \
	DECLARE_FUNCTION(execLeftMyo) \
	{ \
		P_FINISH; \
		*(UMyoController**)Z_Param__Result=this->LeftMyo(); \
	} \
 \
	DECLARE_FUNCTION(execSetLockingPolicy) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_policy); \
		P_FINISH; \
		this->SetLockingPolicy(MyoLockingPolicy(Z_Param_policy)); \
	} \
 \
	DECLARE_FUNCTION(execIsHubEnabled) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->IsHubEnabled(); \
	}


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAMyoPlayerController(); \
	friend MYOPLUGIN_API class UClass* Z_Construct_UClass_AMyoPlayerController(); \
	public: \
	DECLARE_CLASS(AMyoPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, MyoPlugin, NO_API) \
	DECLARE_SERIALIZER(AMyoPlayerController) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<AMyoPlayerController*>(this); }


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_INCLASS \
	private: \
	static void StaticRegisterNativesAMyoPlayerController(); \
	friend MYOPLUGIN_API class UClass* Z_Construct_UClass_AMyoPlayerController(); \
	public: \
	DECLARE_CLASS(AMyoPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, MyoPlugin, NO_API) \
	DECLARE_SERIALIZER(AMyoPlayerController) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<AMyoPlayerController*>(this); }


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyoPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyoPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyoPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyoPlayerController); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AMyoPlayerController(const AMyoPlayerController& InCopy); \
public:


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyoPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AMyoPlayerController(const AMyoPlayerController& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyoPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyoPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyoPlayerController)


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_10_PROLOG
#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_RPC_WRAPPERS \
	Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_INCLASS \
	Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_INCLASS_NO_PURE_DECLS \
	Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h_13_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class MyoPlayerController."); \
PRAGMA_POP


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
