// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "Game.h"
#include "Game.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGame() {}
	void UWiiComponent::StaticRegisterNativesUWiiComponent()
	{
	}
	IMPLEMENT_CLASS(UWiiComponent, 325149234);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();

	GAME_API class UClass* Z_Construct_UClass_UWiiComponent_NoRegister();
	GAME_API class UClass* Z_Construct_UClass_UWiiComponent();
	GAME_API class UPackage* Z_Construct_UPackage_Game();
	UClass* Z_Construct_UClass_UWiiComponent_NoRegister()
	{
		return UWiiComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UWiiComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage_Game();
			OuterClass = UWiiComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushNunchukButtonC, UWiiComponent, bool);
				UProperty* NewProp_bPushNunchukButtonC = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushNunchukButtonC"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushNunchukButtonC, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushNunchukButtonC, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushNunchukButtonZ, UWiiComponent, bool);
				UProperty* NewProp_bPushNunchukButtonZ = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushNunchukButtonZ"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushNunchukButtonZ, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushNunchukButtonZ, UWiiComponent), sizeof(bool), true);
				UProperty* NewProp_nunchukAccelZ = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("nunchukAccelZ"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(nunchukAccelZ, UWiiComponent), 0x0000000000000005);
				UProperty* NewProp_nunchukAccelY = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("nunchukAccelY"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(nunchukAccelY, UWiiComponent), 0x0000000000000005);
				UProperty* NewProp_nunchukAccelX = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("nunchukAccelX"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(nunchukAccelX, UWiiComponent), 0x0000000000000005);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushTwoButton, UWiiComponent, bool);
				UProperty* NewProp_bPushTwoButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushTwoButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushTwoButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushTwoButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushOneButton, UWiiComponent, bool);
				UProperty* NewProp_bPushOneButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushOneButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushOneButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushOneButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushMinusButton, UWiiComponent, bool);
				UProperty* NewProp_bPushMinusButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushMinusButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushMinusButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushMinusButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushPlusButton, UWiiComponent, bool);
				UProperty* NewProp_bPushPlusButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushPlusButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushPlusButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushPlusButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushHomeButton, UWiiComponent, bool);
				UProperty* NewProp_bPushHomeButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushHomeButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushHomeButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushHomeButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushLeftButton, UWiiComponent, bool);
				UProperty* NewProp_bPushLeftButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushLeftButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushLeftButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushLeftButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushRightButton, UWiiComponent, bool);
				UProperty* NewProp_bPushRightButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushRightButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushRightButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushRightButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushDownButton, UWiiComponent, bool);
				UProperty* NewProp_bPushDownButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushDownButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushDownButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushDownButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushUpButton, UWiiComponent, bool);
				UProperty* NewProp_bPushUpButton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushUpButton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushUpButton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushUpButton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushBbutton, UWiiComponent, bool);
				UProperty* NewProp_bPushBbutton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushBbutton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushBbutton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushBbutton, UWiiComponent), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bPushAbutton, UWiiComponent, bool);
				UProperty* NewProp_bPushAbutton = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bPushAbutton"), RF_Public|RF_Transient|RF_Native) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bPushAbutton, UWiiComponent), 0x0000000000000005, CPP_BOOL_PROPERTY_BITMASK(bPushAbutton, UWiiComponent), sizeof(bool), true);
				UProperty* NewProp_motionPlusRoll = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("motionPlusRoll"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(motionPlusRoll, UWiiComponent), 0x0000000000000005);
				UProperty* NewProp_motionPlusYaw = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("motionPlusYaw"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(motionPlusYaw, UWiiComponent), 0x0000000000000005);
				UProperty* NewProp_motionPlusPitch = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("motionPlusPitch"), RF_Public|RF_Transient|RF_Native) UFloatProperty(CPP_PROPERTY_BASE(motionPlusPitch, UWiiComponent), 0x0000000000000005);
PRAGMA_POP
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Custom"));
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("ComponentReplication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushNunchukButtonC, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushNunchukButtonC, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushNunchukButtonZ, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushNunchukButtonZ, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_nunchukAccelZ, TEXT("Category"), TEXT("float"));
				MetaData->SetValue(NewProp_nunchukAccelZ, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_nunchukAccelY, TEXT("Category"), TEXT("float"));
				MetaData->SetValue(NewProp_nunchukAccelY, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_nunchukAccelX, TEXT("Category"), TEXT("float"));
				MetaData->SetValue(NewProp_nunchukAccelX, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushTwoButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushTwoButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushOneButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushOneButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushMinusButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushMinusButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushPlusButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushPlusButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushHomeButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushHomeButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushLeftButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushLeftButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushRightButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushRightButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushDownButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushDownButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushUpButton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushUpButton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushBbutton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushBbutton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_bPushAbutton, TEXT("Category"), TEXT("bool"));
				MetaData->SetValue(NewProp_bPushAbutton, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_motionPlusRoll, TEXT("Category"), TEXT("float"));
				MetaData->SetValue(NewProp_motionPlusRoll, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_motionPlusYaw, TEXT("Category"), TEXT("float"));
				MetaData->SetValue(NewProp_motionPlusYaw, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
				MetaData->SetValue(NewProp_motionPlusPitch, TEXT("Category"), TEXT("float"));
				MetaData->SetValue(NewProp_motionPlusPitch, TEXT("ModuleRelativePath"), TEXT("WiiComponent.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWiiComponent(Z_Construct_UClass_UWiiComponent, TEXT("UWiiComponent"));
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWiiComponent);
	UPackage* Z_Construct_UPackage_Game()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/Game")), false, false));
			ReturnPackage->PackageFlags |= PKG_CompiledIn | 0x00000000;
			FGuid Guid;
			Guid.A = 0xEB7DF748;
			Guid.B = 0x48964CE2;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
