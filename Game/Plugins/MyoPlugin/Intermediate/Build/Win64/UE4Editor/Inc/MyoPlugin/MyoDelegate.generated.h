// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYOPLUGIN_MyoDelegate_generated_h
#error "MyoDelegate.generated.h already included, missing '#pragma once' in MyoDelegate.h"
#endif
#define MYOPLUGIN_MyoDelegate_generated_h

#define Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoDelegate_h_68_GENERATED_BODY \
	friend MYOPLUGIN_API class UScriptStruct* Z_Construct_UScriptStruct_FMyoEmgData(); \
	MYOPLUGIN_API static class UScriptStruct* StaticStruct();


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_MyoPlugin_Source_MyoPlugin_Public_MyoDelegate_h


#define FOREACH_ENUM_MYOSTREAMEMGTYPE(op) \
	op(MYO_STREAM_EMG_DISABLED) \
	op(MYO_STREAM_EMG_ENABLED) 
#define FOREACH_ENUM_MYOUNLOCKTYPE(op) \
	op(MYO_UNLOCK_TIMED) \
	op(MYO_UNLOCK_HOLD) 
#define FOREACH_ENUM_MYOLOCKINGPOLICY(op) \
	op(MYO_LOCKING_POLICY_NONE) \
	op(MYO_LOCKING_POLICY_STANDARD) 
#define FOREACH_ENUM_MYOVIBRATIONTYPE(op) \
	op(MYO_VIBRATION_SHORT) \
	op(MYO_VIBRATION_MEDIUM) \
	op(MYO_VIBRATION_LONG) 
#define FOREACH_ENUM_MYOPOSE(op) \
	op(MYO_POSE_REST) \
	op(MYO_POSE_FIST) \
	op(MYO_POSE_WAVEIN) \
	op(MYO_POSE_WAVEOUT) \
	op(MYO_POSE_FINGERSPREAD) \
	op(MYO_POSE_DOUBLETAP) \
	op(MyoPose::UnusedSpacer_6) \
	op(MyoPose::UnusedSpacer_7) \
	op(MyoPose::UnusedSpacer_8) \
	op(MyoPose::UnusedSpacer_9) \
	op(MyoPose::UnusedSpacer_10) \
	op(MyoPose::UnusedSpacer_11) \
	op(MyoPose::UnusedSpacer_12) \
	op(MyoPose::UnusedSpacer_13) \
	op(MyoPose::UnusedSpacer_14) \
	op(MyoPose::UnusedSpacer_15) \
	op(MyoPose::UnusedSpacer_16) \
	op(MyoPose::UnusedSpacer_17) \
	op(MyoPose::UnusedSpacer_18) \
	op(MyoPose::UnusedSpacer_19) \
	op(MyoPose::UnusedSpacer_20) \
	op(MyoPose::UnusedSpacer_21) \
	op(MyoPose::UnusedSpacer_22) \
	op(MyoPose::UnusedSpacer_23) \
	op(MyoPose::UnusedSpacer_24) \
	op(MyoPose::UnusedSpacer_25) \
	op(MyoPose::UnusedSpacer_26) \
	op(MyoPose::UnusedSpacer_27) \
	op(MyoPose::UnusedSpacer_28) \
	op(MyoPose::UnusedSpacer_29) \
	op(MyoPose::UnusedSpacer_30) \
	op(MyoPose::UnusedSpacer_31) \
	op(MyoPose::UnusedSpacer_32) \
	op(MyoPose::UnusedSpacer_33) \
	op(MyoPose::UnusedSpacer_34) \
	op(MyoPose::UnusedSpacer_35) \
	op(MyoPose::UnusedSpacer_36) \
	op(MyoPose::UnusedSpacer_37) \
	op(MyoPose::UnusedSpacer_38) \
	op(MyoPose::UnusedSpacer_39) \
	op(MyoPose::UnusedSpacer_40) \
	op(MyoPose::UnusedSpacer_41) \
	op(MyoPose::UnusedSpacer_42) \
	op(MyoPose::UnusedSpacer_43) \
	op(MyoPose::UnusedSpacer_44) \
	op(MyoPose::UnusedSpacer_45) \
	op(MyoPose::UnusedSpacer_46) \
	op(MyoPose::UnusedSpacer_47) \
	op(MyoPose::UnusedSpacer_48) \
	op(MyoPose::UnusedSpacer_49) \
	op(MyoPose::UnusedSpacer_50) \
	op(MyoPose::UnusedSpacer_51) \
	op(MyoPose::UnusedSpacer_52) \
	op(MyoPose::UnusedSpacer_53) \
	op(MyoPose::UnusedSpacer_54) \
	op(MyoPose::UnusedSpacer_55) \
	op(MyoPose::UnusedSpacer_56) \
	op(MyoPose::UnusedSpacer_57) \
	op(MyoPose::UnusedSpacer_58) \
	op(MyoPose::UnusedSpacer_59) \
	op(MyoPose::UnusedSpacer_60) \
	op(MyoPose::UnusedSpacer_61) \
	op(MyoPose::UnusedSpacer_62) \
	op(MyoPose::UnusedSpacer_63) \
	op(MyoPose::UnusedSpacer_64) \
	op(MyoPose::UnusedSpacer_65) \
	op(MyoPose::UnusedSpacer_66) \
	op(MyoPose::UnusedSpacer_67) \
	op(MyoPose::UnusedSpacer_68) \
	op(MyoPose::UnusedSpacer_69) \
	op(MyoPose::UnusedSpacer_70) \
	op(MyoPose::UnusedSpacer_71) \
	op(MyoPose::UnusedSpacer_72) \
	op(MyoPose::UnusedSpacer_73) \
	op(MyoPose::UnusedSpacer_74) \
	op(MyoPose::UnusedSpacer_75) \
	op(MyoPose::UnusedSpacer_76) \
	op(MyoPose::UnusedSpacer_77) \
	op(MyoPose::UnusedSpacer_78) \
	op(MyoPose::UnusedSpacer_79) \
	op(MyoPose::UnusedSpacer_80) \
	op(MyoPose::UnusedSpacer_81) \
	op(MyoPose::UnusedSpacer_82) \
	op(MyoPose::UnusedSpacer_83) \
	op(MyoPose::UnusedSpacer_84) \
	op(MyoPose::UnusedSpacer_85) \
	op(MyoPose::UnusedSpacer_86) \
	op(MyoPose::UnusedSpacer_87) \
	op(MyoPose::UnusedSpacer_88) \
	op(MyoPose::UnusedSpacer_89) \
	op(MyoPose::UnusedSpacer_90) \
	op(MyoPose::UnusedSpacer_91) \
	op(MyoPose::UnusedSpacer_92) \
	op(MyoPose::UnusedSpacer_93) \
	op(MyoPose::UnusedSpacer_94) \
	op(MyoPose::UnusedSpacer_95) \
	op(MyoPose::UnusedSpacer_96) \
	op(MyoPose::UnusedSpacer_97) \
	op(MyoPose::UnusedSpacer_98) \
	op(MyoPose::UnusedSpacer_99) \
	op(MyoPose::UnusedSpacer_100) \
	op(MyoPose::UnusedSpacer_101) \
	op(MyoPose::UnusedSpacer_102) \
	op(MyoPose::UnusedSpacer_103) \
	op(MyoPose::UnusedSpacer_104) \
	op(MyoPose::UnusedSpacer_105) \
	op(MyoPose::UnusedSpacer_106) \
	op(MyoPose::UnusedSpacer_107) \
	op(MyoPose::UnusedSpacer_108) \
	op(MyoPose::UnusedSpacer_109) \
	op(MyoPose::UnusedSpacer_110) \
	op(MyoPose::UnusedSpacer_111) \
	op(MyoPose::UnusedSpacer_112) \
	op(MyoPose::UnusedSpacer_113) \
	op(MyoPose::UnusedSpacer_114) \
	op(MyoPose::UnusedSpacer_115) \
	op(MyoPose::UnusedSpacer_116) \
	op(MyoPose::UnusedSpacer_117) \
	op(MyoPose::UnusedSpacer_118) \
	op(MyoPose::UnusedSpacer_119) \
	op(MyoPose::UnusedSpacer_120) \
	op(MyoPose::UnusedSpacer_121) \
	op(MyoPose::UnusedSpacer_122) \
	op(MyoPose::UnusedSpacer_123) \
	op(MyoPose::UnusedSpacer_124) \
	op(MyoPose::UnusedSpacer_125) \
	op(MyoPose::UnusedSpacer_126) \
	op(MyoPose::UnusedSpacer_127) \
	op(MyoPose::UnusedSpacer_128) \
	op(MyoPose::UnusedSpacer_129) \
	op(MyoPose::UnusedSpacer_130) \
	op(MyoPose::UnusedSpacer_131) \
	op(MyoPose::UnusedSpacer_132) \
	op(MyoPose::UnusedSpacer_133) \
	op(MyoPose::UnusedSpacer_134) \
	op(MyoPose::UnusedSpacer_135) \
	op(MyoPose::UnusedSpacer_136) \
	op(MyoPose::UnusedSpacer_137) \
	op(MyoPose::UnusedSpacer_138) \
	op(MyoPose::UnusedSpacer_139) \
	op(MyoPose::UnusedSpacer_140) \
	op(MyoPose::UnusedSpacer_141) \
	op(MyoPose::UnusedSpacer_142) \
	op(MyoPose::UnusedSpacer_143) \
	op(MyoPose::UnusedSpacer_144) \
	op(MyoPose::UnusedSpacer_145) \
	op(MyoPose::UnusedSpacer_146) \
	op(MyoPose::UnusedSpacer_147) \
	op(MyoPose::UnusedSpacer_148) \
	op(MyoPose::UnusedSpacer_149) \
	op(MyoPose::UnusedSpacer_150) \
	op(MyoPose::UnusedSpacer_151) \
	op(MyoPose::UnusedSpacer_152) \
	op(MyoPose::UnusedSpacer_153) \
	op(MyoPose::UnusedSpacer_154) \
	op(MyoPose::UnusedSpacer_155) \
	op(MyoPose::UnusedSpacer_156) \
	op(MyoPose::UnusedSpacer_157) \
	op(MyoPose::UnusedSpacer_158) \
	op(MyoPose::UnusedSpacer_159) \
	op(MyoPose::UnusedSpacer_160) \
	op(MyoPose::UnusedSpacer_161) \
	op(MyoPose::UnusedSpacer_162) \
	op(MyoPose::UnusedSpacer_163) \
	op(MyoPose::UnusedSpacer_164) \
	op(MyoPose::UnusedSpacer_165) \
	op(MyoPose::UnusedSpacer_166) \
	op(MyoPose::UnusedSpacer_167) \
	op(MyoPose::UnusedSpacer_168) \
	op(MyoPose::UnusedSpacer_169) \
	op(MyoPose::UnusedSpacer_170) \
	op(MyoPose::UnusedSpacer_171) \
	op(MyoPose::UnusedSpacer_172) \
	op(MyoPose::UnusedSpacer_173) \
	op(MyoPose::UnusedSpacer_174) \
	op(MyoPose::UnusedSpacer_175) \
	op(MyoPose::UnusedSpacer_176) \
	op(MyoPose::UnusedSpacer_177) \
	op(MyoPose::UnusedSpacer_178) \
	op(MyoPose::UnusedSpacer_179) \
	op(MyoPose::UnusedSpacer_180) \
	op(MyoPose::UnusedSpacer_181) \
	op(MyoPose::UnusedSpacer_182) \
	op(MyoPose::UnusedSpacer_183) \
	op(MyoPose::UnusedSpacer_184) \
	op(MyoPose::UnusedSpacer_185) \
	op(MyoPose::UnusedSpacer_186) \
	op(MyoPose::UnusedSpacer_187) \
	op(MyoPose::UnusedSpacer_188) \
	op(MyoPose::UnusedSpacer_189) \
	op(MyoPose::UnusedSpacer_190) \
	op(MyoPose::UnusedSpacer_191) \
	op(MyoPose::UnusedSpacer_192) \
	op(MyoPose::UnusedSpacer_193) \
	op(MyoPose::UnusedSpacer_194) \
	op(MyoPose::UnusedSpacer_195) \
	op(MyoPose::UnusedSpacer_196) \
	op(MyoPose::UnusedSpacer_197) \
	op(MyoPose::UnusedSpacer_198) \
	op(MyoPose::UnusedSpacer_199) \
	op(MyoPose::UnusedSpacer_200) \
	op(MyoPose::UnusedSpacer_201) \
	op(MyoPose::UnusedSpacer_202) \
	op(MyoPose::UnusedSpacer_203) \
	op(MyoPose::UnusedSpacer_204) \
	op(MyoPose::UnusedSpacer_205) \
	op(MyoPose::UnusedSpacer_206) \
	op(MyoPose::UnusedSpacer_207) \
	op(MyoPose::UnusedSpacer_208) \
	op(MyoPose::UnusedSpacer_209) \
	op(MyoPose::UnusedSpacer_210) \
	op(MyoPose::UnusedSpacer_211) \
	op(MyoPose::UnusedSpacer_212) \
	op(MyoPose::UnusedSpacer_213) \
	op(MyoPose::UnusedSpacer_214) \
	op(MyoPose::UnusedSpacer_215) \
	op(MyoPose::UnusedSpacer_216) \
	op(MyoPose::UnusedSpacer_217) \
	op(MyoPose::UnusedSpacer_218) \
	op(MyoPose::UnusedSpacer_219) \
	op(MyoPose::UnusedSpacer_220) \
	op(MyoPose::UnusedSpacer_221) \
	op(MyoPose::UnusedSpacer_222) \
	op(MyoPose::UnusedSpacer_223) \
	op(MyoPose::UnusedSpacer_224) \
	op(MyoPose::UnusedSpacer_225) \
	op(MyoPose::UnusedSpacer_226) \
	op(MyoPose::UnusedSpacer_227) \
	op(MyoPose::UnusedSpacer_228) \
	op(MyoPose::UnusedSpacer_229) \
	op(MyoPose::UnusedSpacer_230) \
	op(MyoPose::UnusedSpacer_231) \
	op(MyoPose::UnusedSpacer_232) \
	op(MyoPose::UnusedSpacer_233) \
	op(MyoPose::UnusedSpacer_234) \
	op(MyoPose::UnusedSpacer_235) \
	op(MyoPose::UnusedSpacer_236) \
	op(MyoPose::UnusedSpacer_237) \
	op(MyoPose::UnusedSpacer_238) \
	op(MyoPose::UnusedSpacer_239) \
	op(MyoPose::UnusedSpacer_240) \
	op(MyoPose::UnusedSpacer_241) \
	op(MyoPose::UnusedSpacer_242) \
	op(MyoPose::UnusedSpacer_243) \
	op(MyoPose::UnusedSpacer_244) \
	op(MyoPose::UnusedSpacer_245) \
	op(MyoPose::UnusedSpacer_246) \
	op(MyoPose::UnusedSpacer_247) \
	op(MyoPose::UnusedSpacer_248) \
	op(MyoPose::UnusedSpacer_249) \
	op(MyoPose::UnusedSpacer_250) \
	op(MyoPose::UnusedSpacer_251) \
	op(MyoPose::UnusedSpacer_252) \
	op(MyoPose::UnusedSpacer_253) \
	op(MyoPose::UnusedSpacer_254) \
	op(MYO_POSE_UNKNOWN) 
#define FOREACH_ENUM_MYOARMDIRECTION(op) \
	op(MYO_TOWARD_WRIST) \
	op(MYO_TOWARD_ELBOW) \
	op(MYO_DIRECTION_UNKNOWN) 
#define FOREACH_ENUM_MYOARM(op) \
	op(MYO_ARM_RIGHT) \
	op(MYO_ARM_LEFT) \
	op(MYO_ARM_UNKNOWN) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
