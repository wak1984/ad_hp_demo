#ifndef AGORA_SDK_C_WRAPPER
#define AGORA_SDK_C_WRAPPER
#include "AgoraSDKObject.h"
#include <string>
#define NOT_INIT_AGORA_SDK_OBJECT -7
#define NOT_INIT_AGORA_SDK_OBJECT_CHAR "-7"
using namespace std;

const char *TAG = "agora_sdk_c_wrapper";
//----------------Agora Api Start-----------------------------
AGORA_API bool createEngine(const char *appId);
AGORA_API void deleteEngine();
AGORA_API const char *getSdkVersion();
AGORA_API const char *getMediaEngineVersion();
AGORA_API void *getNativeHandle();
AGORA_API int joinChannel(const char *channelKey, const char *channelName, const char *info, unsigned int uid);
AGORA_API int renewToken(const char *token);
AGORA_API int leaveChannel();
AGORA_API int enableLastmileTest();
AGORA_API int disableLastmileTest();
AGORA_API int enableVideo();
AGORA_API int disableVideo();
AGORA_API int enableLocalVideo(bool enabled);
AGORA_API int startPreview();
AGORA_API int stopPreview();
AGORA_API int enableAudio();
AGORA_API int enableLocalAudio(bool enabled);
AGORA_API int disableAudio();
AGORA_API int setParameters(const char *options);
AGORA_API char *getParameter(const char *parameter, const char *args);
AGORA_API char *getCallId();
AGORA_API int rate(const char *callId, int rating, const char *desc);
AGORA_API int complain(const char *callId, const char *desc);
AGORA_API int setEnableSpeakerphone(int enabled);
AGORA_API int isSpeakerphoneEnabled();
AGORA_API int setDefaultAudioRoutetoSpeakerphone(bool defaultToSpeaker);
AGORA_API int setSpeakerphoneVolume(int volume);
AGORA_API int enableAudioVolumeIndication(int interval, int smooth);
AGORA_API int startAudioRecording(const char *filePath, int quality);
AGORA_API int stopAudioRecording();
AGORA_API int startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle);
AGORA_API int stopAudioMixing();
AGORA_API int pauseAudioMixing();
AGORA_API int resumeAudioMixing();
AGORA_API int adjustAudioMixingVolume(int volume);
AGORA_API int getAudioMixingDuration();
AGORA_API int getAudioMixingCurrentPosition();
AGORA_API int setAudioMixingPosition(int pos);
AGORA_API int startEchoTest();
AGORA_API int stopEchoTest();
AGORA_API int muteLocalAudioStream(bool muted);
AGORA_API int muteAllRemoteAudioStreams(bool muted);
AGORA_API int muteRemoteAudioStream(unsigned int uid, bool muted);
AGORA_API int switchCamera();
AGORA_API int setVideoProfile(int profile, bool swapWidthAndHeight);
AGORA_API int muteLocalVideoStream(bool muted);
AGORA_API int muteAllRemoteVideoStreams(bool muted);
AGORA_API int muteRemoteVideoStream(unsigned int uid, bool muted);
AGORA_API int setLogFile(const char *filePath);
AGORA_API int setLogFilter(unsigned int filter);
AGORA_API int setChannelProfile(int profile);
AGORA_API int setClientRole(int role);
AGORA_API int enableDualStreamMode(bool enabled);
AGORA_API int setEncryptionMode(const char *encryptionMode);
AGORA_API int setEncryptionSecret(const char *secret);
AGORA_API int setRemoteVideoStreamType(unsigned int uid, int streamType);
AGORA_API int startRecordingService(const char *recordingKey);
AGORA_API int stopRecordingService(const char *recordingKey);
AGORA_API int refreshRecordingServiceStatus();
AGORA_API int createDataStream(bool reliable, bool ordered);
AGORA_API int sendStreamMessage(int streamId, const char *data, size_t length);
AGORA_API int setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
AGORA_API int setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
AGORA_API int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);
AGORA_API int adjustRecordingSignalVolume(int volume);
AGORA_API int adjustPlaybackSignalVolume(int volume);
AGORA_API int setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate);
AGORA_API int enableInEarMonitoring(bool enabled);
AGORA_API int enableWebSdkInteroperability(bool enabled);
AGORA_API int setVideoQualityParameters(bool preferFrameRateOverImageQuality);
AGORA_API int setLocalVoicePitch(double pitch);
AGORA_API int setRemoteVoicePosition(uid_t uid, double pan, double gain);
AGORA_API int setVoiceOnlyMode(bool enabled);
AGORA_API int setPlaybackDeviceVolume(int volume);
AGORA_API int getEffectsVolume();
AGORA_API int setEffectsVolume(int volume);
AGORA_API int playEffect(int soundId, const char *filePath, int loopCount, double pitch, double pan, int gain, bool publish = false);
AGORA_API int stopEffect(int soundId);
AGORA_API int stopAllEffects();
AGORA_API int preloadEffect(int soundId, const char *filePath);
AGORA_API int unloadEffect(int soundId);
AGORA_API int pauseEffect(int soundId);
AGORA_API int pauseAllEffects();
AGORA_API int resumeEffect(int soundId);
AGORA_API int resumeAllEffects();
AGORA_API void freeObject(void *obj);
AGORA_API int setDefaultMuteAllRemoteAudioStreams(bool mute);
AGORA_API int setDefaultMuteAllRemoteVideoStreams(bool mute);
AGORA_API int pushExternVideoFrame(int type, int format, void* buffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, long timestamp);
AGORA_API int setExternalVideoSource(bool enable, bool useTexture);
AGORA_API int setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, unsigned int transcodingUserUid, int transcodingUsersX, int transcodingUsersY, int transcodingUsersWidth, int transcodingUsersHeight, int transcodingUsersZorder, double transcodingUsersAlpha, int transcodingUsersAudioChannel, const char *transcodingExtraInfo, const char * metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile);
AGORA_API int addPublishStreamUrl(const char *url, bool transcodingEnabled);
AGORA_API int removePublishStreamUrl(const char *url);
AGORA_API int configPublisher(int width, int height, int framerate, int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char* injectStreamUrl, const char* publishUrl, const char* rawStreamUrl, const char* extraInfo);
AGORA_API int setVideoCompositingLayout(int canvasWidth, int canvasHeight, const char* backgroundColor, uid_t regionUid, double regionX, double regionY, double regionWidth, double regionHeight, int regionZOrder, double regionAlpha, int regionRenderMode, int regionCount, const char* appData, int appDataLength);
AGORA_API int clearVideoCompositingLayout();
AGORA_API int addVideoWatermark(const char* url, int x, int y, int width, int height);
AGORA_API int clearVideoWatermarks();
AGORA_API int setBeautyEffectOptions(bool enabled, int beatyOptionsLighteningContrastLevel, float beatyOptionsLighteningLevel, float beatyOptionsSmoothnessLevel, float beatyOptionsRednessLevel);
AGORA_API int addInjectStreamUrl(const char* url, int injectStreamWidth, int injectStreamHeight, int injectStreamVideoGop, int injectStreamVideoFramerate, int injectStreamVideoBitrate, int injectStreamAudioSampleRate, int injectStreamAudioBitrate, int injectStreamAudioChannels);
AGORA_API int removeInjectStreamUrl(const char* url);
AGORA_API int enableSoundPositionIndication(bool enabled);
AGORA_API int setupLocalVideo(int view, int renderMode, uid_t uid, void* priv);
AGORA_API int setupRemoteVideo(int view, int renderMode, uid_t uid, void* priv);
//video api
AGORA_API int enableVideoObserver();
AGORA_API int disableVideoObserver();
AGORA_API int generateNativeTexture();
AGORA_API int updateTexture(int texId, unsigned char *data, unsigned int uid);
AGORA_API void deleteTexture(int tex);
//audio api
AGORA_API int setExternalAudioSource(bool enabled, int sampleRate, int channels);
AGORA_API int setExternalAudioSink(bool enabled, int sampleRate, int channels);
AGORA_API int pushExternalAudioFrame(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);

AGORA_API int startScreenCapture(int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate, const char* GameName);
AGORA_API int stopScreenCapture();

AGORA_API int startScreenCaptureEx(HWND windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate);
AGORA_API int stopScreenCaptureEx();

//----------------Agora Api End-----------------------------
//--------------Callback start------------------
AGORA_API void initCallBackObject();
AGORA_API void initEventOnJoinChannelSuccess(FUNC_OnJoinChannelSuccess onJoinChannelSuccess);
AGORA_API void initEventOnReJoinChannelSuccess(FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess);
AGORA_API void initEventOnConnectionLost(FUNC_OnConnectionLost onConnectionLost);
AGORA_API void initEventOnLeaveChannel(FUNC_OnLeaveChannel onLeaveChannel);
AGORA_API void initEventOnConnectionInterrupted(FUNC_OnConnectionInterrupted onConnectionInterrupted);
AGORA_API void initEventOnRequestToken(FUNC_OnRequestToken onRequestToken);
AGORA_API void initEventOnUserJoined(FUNC_OnUserJoined onUserJoined);
AGORA_API void initEventOnUserOffline(FUNC_OnUserOffline onUserOffline);
AGORA_API void initEventOnAudioVolumeIndication(FUNC_OnAudioVolumeIndication onAudioVolumeIndication);
AGORA_API void initEventOnUserMuteAudio(FUNC_OnUserMuteAudio onUserMuteAudio);
AGORA_API void initEventOnSDKWarning(FUNC_OnSDKWarning onSDKWarning);
AGORA_API void initEventOnSDKError(FUNC_OnSDKError onSDKError);
AGORA_API void initEventOnRtcStats(FUNC_OnRtcStats onRtcStats);
AGORA_API void initEventOnAudioMixingFinished(FUNC_OnAudioMixingFinished onAudioMixingFinished);
AGORA_API void initEventOnAudioRouteChanged(FUNC_OnAudioRouteChanged onAudioRouteChanged);
AGORA_API void initEventOnFirstRemoteVideoDecoded(FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded);
AGORA_API void initEventOnVideoSizeChanged(FUNC_OnVideoSizeChanged onVideoSizeChanged);
AGORA_API void initEventOnClientRoleChanged(FUNC_OnClientRoleChanged onClientRoleChanged);
AGORA_API void initEventOnUserMuteVideo(FUNC_OnUserMuteVideo onUserMuteVideo);
AGORA_API void initEventOnMicrophoneEnabled(FUNC_OnMicrophoneEnabled onMicrophoneEnabled);
AGORA_API void initEventOnApiExecuted(FUNC_OnApiExecuted onApiCallExecuted);
AGORA_API void initEventOnFirstLocalAudioFrame(FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame);
AGORA_API void initEventOnFirstRemoteAudioFrame(FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame);
AGORA_API void initEventOnLastmileQuality(FUNC_OnLastmileQuality onLastmileQuality);
AGORA_API void initEventOnAudioQuality(FUNC_OnAudioQuality onAudioQuality);
AGORA_API void initEventOnStreamInjectedStatus(FUNC_OnStreamInjectedStatus onStreamInjectedStatus);
AGORA_API void initEventOnStreamUnpublished(FUNC_OnStreamUnpublished onStreamUnpublished);
AGORA_API void initEventOnStreamPublished(FUNC_OnStreamPublished onStreamPublished);
AGORA_API void initEventOnStreamMessageError(FUNC_OnStreamMessageError onStreamMessageError);
AGORA_API void initEventOnStreamMessage(FUNC_OnStreamMessage onStreamMessage);
AGORA_API void initEventOnConnectionBanned(FUNC_OnConnectionBanned onConnectionBanned);
AGORA_API void initEventOnNetworkQuality(FUNC_OnNetworkQuality onNetworkQuality);
AGORA_API void initEventOnCaptureVideoFrameRaw(FUNC_onCaptureVideoFrameRaw onCaptureVideoFrameRaw);
AGORA_API void initEventOnRenderVideoFrameRaw(FUNC_onRenderVideoFrameRaw onRenderVideoFrameRaw);
//--------------Callback end------------------

//---------jni onload---------
#if defined(WRAPPER_ANDROID)
extern "C" jint JNI_OnLoad(JavaVM *vm, void *);
#endif
#endif
