#ifndef C_PLAT_FORM_DIFFERENCE
#define C_PLAT_FORM_DIFFERENCE
#define WRAPPER_WINDOWS
//#define WRAPPER_ANDROID
//#define WRAPPER_IOS
//#define WRAPPER_MAC

#if defined(WRAPPER_ANDROID)
//-------------------------ANDROID START------------------------------------
#include <android/log.h>
#include "../prebuilt/include/IAgoraMediaEngine.h"
#include "../prebuilt/include/IAgoraRtcEngine.h"
#include "../prebuilt/include/IAgoraService.h"
#include "../prebuilt/include/AgoraBase.h"
#include <jni.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES/gl.h>
#include <mutex>
#include <list>
#include <map>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <android/log.h>
#define PRINTF(...) __android_log_print(ANDROID_LOG_INFO, "AgoraUnity_CWrapper", __VA_ARGS__)
//-------------------------ANDROID END------------------------------------
#else
#if defined(WRAPPER_WINDOWS)
#define AGORARTC_EXPORT
//-------------------------WINDOWS START----------------------------------------
//#include "../../sdk_x64/include/IAgoraService.h"
//#include "../../sdk_x64/include/IAgoraRtcEngine.h"
//#include "../../sdk_x64/include/IAgoraMediaEngine.h"
//#include "../../sdk_x64/include/AgoraBase.h"

#include "IAgoraService.h"
#include "IAgoraRtcEngine.h"
#include "IAgoraMediaEngine.h"
#include "AgoraBase.h"

#include <mutex>
#include <list>
#include <map>
#include <string>

#pragma warning(disable : 4800)
#pragma warning(disable : 4172)
#pragma warning(disable : 4018)
#pragma warning(disable : 4996)
#pragma comment(lib, "../../sdk/lib/agora_rtc_sdk.lib")
#define LENGTH_MAX 255
#define NOT_INIT_ENGINE -7
#define NOT_INIT_ENGINE_CHAR "-7"

//-------------------------WINDOWS END----------------------------------------
#else
#if defined(WRAPPER_IOS)
//----------------------IOS  START---------------------
#include "include/IAgoraMediaEngine.h"
#include "include/IAgoraRtcEngine.h"
#include "include/IAgoraService.h"
#include "include/AgoraBase.h"

#include <stdio.h>
#include <memory.h>
#include <string>
#include <OpenGLES/ES2/gl.h>
#include <mutex>
#include <list>
#include <map>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#define PRINTF printf
#define LENGTH_MAX 255
#define NOT_INIT_ENGINE -7
#define NOT_INIT_ENGINE_CHAR "-7"
//----------------------IOS  END---------------------

#else
#if defined(WRAPPER_MAC)
//----------------------IOS  START---------------------
#include <AgoraRtcEngineKit/IAgoraMediaEngine.h>
#include <AgoraRtcEngineKit/IAgoraRtcEngine.h>
#include <AgoraRtcEngineKit/IAgoraService.h>
#include <AgoraRtcEngineKit/AgoraBase.h>

#include <stdio.h>
#include <memory.h>
#include <string>
#include <mutex>
#include <list>
#include <map>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#define PRINTF printf
#define LENGTH_MAX 255
#define NOT_INIT_ENGINE -7
#define NOT_INIT_ENGINE_CHAR "-7"


//----------------------MAC end----------------------
#endif
#endif
#endif
#endif

using namespace agora::rtc;
using namespace std;

#if defined WRAPPER_WINDOWS
typedef void(__stdcall *FUNC)(int, const char *);
typedef void(__stdcall *FUNC_OnJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnConnectionLost)();
typedef void(__stdcall *FUNC_OnConnectionInterrupted)();
typedef void(__stdcall *FUNC_OnLeaveChannel)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
											 unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate,
											 unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate,
											 unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned int userCount, double cpuAppUsage,
											 double cpuTotalUsage);
typedef void(__stdcall *FUNC_OnRequestToken)();
typedef void(__stdcall *FUNC_OnUserJoined)(uid_t uid, int elapsed);
typedef void(__stdcall *FUNC_OnUserOffline)(uid_t uid, int offLineReason);
typedef void(__stdcall *FUNC_OnAudioVolumeIndication)(const char *volumeInfo, int speakerNumber, int totalVolume);
typedef void(__stdcall *FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnSDKWarning)(int warn, const char *msg);
typedef void(__stdcall *FUNC_OnSDKError)(int error, const char *msg);
typedef void(__stdcall *FUNC_OnRtcStats)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
										 unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate,
										 unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate,
										 unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned int userCount, double cpuAppUsage,
										 double cpuTotalUsage);
typedef void(__stdcall *FUNC_OnNetworkQuality)(uid_t uid, int txQuality, int rxQuality);										 
typedef void(__stdcall *FUNC_OnAudioMixingFinished)();
typedef void(__stdcall *FUNC_OnAudioRouteChanged)(int route);
typedef void(__stdcall *FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width, int height, int elapsed);
typedef void(__stdcall *FUNC_OnVideoSizeChanged)(uid_t uid, int width, int height, int elapsed);
typedef void(__stdcall *FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void(__stdcall *FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
typedef void(__stdcall *FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void(__stdcall *FUNC_OnApiExecuted)(int err, const char *api, const char *result);
typedef void(__stdcall *FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void(__stdcall *FUNC_OnFirstRemoteAudioFrame)(uid_t userId, int elapsed);
typedef void(__stdcall *FUNC_OnLastmileQuality)(int quality);
typedef void(__stdcall *FUNC_OnAudioQuality)(uid_t userId, int quality, unsigned short delay, unsigned short lost);
typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url, uid_t userId, int status);
typedef void(__stdcall *FUNC_OnStreamUnpublished)(const char *url);
typedef void(__stdcall *FUNC_OnStreamPublished)(const char *url, int error);
typedef void(__stdcall *FUNC_OnStreamMessageError)(uid_t userId, int streamId, int code, int missed, int cached);
typedef void(__stdcall *FUNC_OnStreamMessage)(uid_t userId, int streamId, const char *data, size_t length);
typedef void(__stdcall *FUNC_OnConnectionBanned)();
typedef void(__stdcall* FUNC_onCaptureVideoFrameRaw)(int width, int height, const unsigned char* yBuffer, int rotation);
typedef void(__stdcall* FUNC_onRenderVideoFrameRaw)(uid_t userId, int width, int height, const unsigned char* yBuffer, int rotation);
#else

typedef void (*FUNC)(int, const char *);
typedef void (*FUNC_OnJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
typedef void (*FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
typedef void (*FUNC_OnConnectionLost)();
typedef void (*FUNC_OnConnectionInterrupted)();
typedef void (*FUNC_OnLeaveChannel)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
									unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate,
									unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate,
									unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned int userCount, double cpuAppUsage,
									double cpuTotalUsage);
typedef void (*FUNC_OnRequestToken)();
typedef void (*FUNC_OnUserJoined)(uid_t uid, int elapsed);
typedef void (*FUNC_OnUserOffline)(uid_t uid, int offLineReason);
typedef void (*FUNC_OnAudioVolumeIndication)(const char *volumeInfo, int speakerNumber, int totalVolume);
typedef void (*FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
typedef void (*FUNC_OnSDKWarning)(int warn, const char *msg);
typedef void (*FUNC_OnSDKError)(int error, const char *msg);
typedef void (*FUNC_OnRtcStats)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes,
								unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate,
								unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate,
								unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned int userCount, double cpuAppUsage,
								double cpuTotalUsage);
typedef void (*FUNC_OnNetworkQuality)(uid_t uid, int txQuality, int rxQuality);
typedef void (*FUNC_OnAudioMixingFinished)();
typedef void (*FUNC_OnAudioRouteChanged)(int route);
typedef void (*FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width, int height, int elapsed);
typedef void (*FUNC_OnVideoSizeChanged)(uid_t uid, int width, int height, int elapsed);
typedef void (*FUNC_OnClientRoleChanged)(int oldRole, int newRole);
typedef void (*FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
typedef void (*FUNC_OnMicrophoneEnabled)(bool isEnabled);
typedef void (*FUNC_OnApiExecuted)(int err, const char *api, const char *result);
typedef void (*FUNC_OnFirstLocalAudioFrame)(int elapsed);
typedef void (*FUNC_OnFirstRemoteAudioFrame)(uid_t userId, int elapsed);
typedef void (*FUNC_OnLastmileQuality)(int quality);
typedef void (*FUNC_OnAudioQuality)(uid_t userId, int quality, unsigned short delay, unsigned short lost);
typedef void (*FUNC_OnStreamInjectedStatus)(const char *url, uid_t userId, int status);
typedef void (*FUNC_OnStreamUnpublished)(const char *url);
typedef void (*FUNC_OnStreamPublished)(const char *url, int error);
typedef void (*FUNC_OnStreamMessageError)(uid_t userId, int streamId, int code, int missed, int cached);
typedef void (*FUNC_OnStreamMessage)(uid_t userId, int streamId, const char *data, size_t length);
typedef void (*FUNC_OnConnectionBanned)();
#endif
#endif

void PRINTFLog(const char *pLog, int nLen);
