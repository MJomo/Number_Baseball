// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyUserWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NUMBER_BASEBALL_MyUserWidget_generated_h
#error "MyUserWidget.generated.h already included, missing '#pragma once' in MyUserWidget.h"
#endif
#define NUMBER_BASEBALL_MyUserWidget_generated_h

#define FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnChatInputTextCommitted);


#define FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyUserWidget(); \
	friend struct Z_Construct_UClass_UMyUserWidget_Statics; \
public: \
	DECLARE_CLASS(UMyUserWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Number_Baseball"), NO_API) \
	DECLARE_SERIALIZER(UMyUserWidget)


#define FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyUserWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMyUserWidget(UMyUserWidget&&); \
	UMyUserWidget(const UMyUserWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyUserWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyUserWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyUserWidget) \
	NO_API virtual ~UMyUserWidget();


#define FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_14_PROLOG
#define FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_INCLASS_NO_PURE_DECLS \
	FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NUMBER_BASEBALL_API UClass* StaticClass<class UMyUserWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Number_Baseball_Source_Number_Baseball_Public_MyUserWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
