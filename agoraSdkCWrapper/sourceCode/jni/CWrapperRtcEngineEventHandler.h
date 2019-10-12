#ifndef CWRAPPER_RTC_ENGINE_EVENT_HANDLER
#define CWRAPPER_RTC_ENGINE_EVENT_HANDLER
#include <string>
#include "CPlatformDifference.h"
#define LENGTH_MAX 255
using namespace agora::rtc;
using namespace agora::media;
using namespace agora::base;
using namespace std;

class EngineEvent
{
public:
  FUNC_OnJoinChannelSuccess onJoinChannelSuccess = NULL;
  FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess = NULL;
  FUNC_OnLeaveChannel onLeaveChannel = NULL;
  FUNC_OnConnectionLost onConnectionLost = NULL;
  FUNC_OnConnectionInterrupted onConnectionInterrupted = NULL;
  FUNC_OnRequestToken onRequestToken = NULL;
  FUNC_OnUserJoined onUserJoined = NULL;
  FUNC_OnUserOffline onUserOffline = NULL;
  FUNC_OnAudioVolumeIndication onAudioVolumeIndication = NULL;
  FUNC_OnUserMuteAudio onUserMuteAudio = NULL;
  FUNC_OnSDKWarning onSDKWarning = NULL;
  FUNC_OnSDKError onSDKError = NULL;
  FUNC_OnRtcStats onRtcStats = NULL;
  FUNC_OnAudioMixingFinished onAudioMixingFinished = NULL;
  FUNC_OnAudioRouteChanged onAudioRouteChanged = NULL;
  FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded = NULL;
  FUNC_OnVideoSizeChanged onVideoSizeChanged = NULL;
  FUNC_OnClientRoleChanged onClientRoleChanged = NULL;
  FUNC_OnUserMuteVideo onUserMuteVideo = NULL;
  FUNC_OnMicrophoneEnabled onMicrophoneEnabled = NULL;
  FUNC_OnApiExecuted onApiCallExecuted = NULL;
  FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame = NULL;
  FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame = NULL;
  FUNC_OnLastmileQuality onLastmileQuality = NULL;
  FUNC_OnAudioQuality onAudioQuality = NULL;
  FUNC_OnStreamInjectedStatus onStreamInjectedStatus = NULL;
  FUNC_OnStreamUnpublished onStreamUnpublished = NULL;
  FUNC_OnStreamPublished onStreamPublished = NULL;
  FUNC_OnStreamMessageError onStreamMessageError = NULL;
  FUNC_OnStreamMessage onStreamMessage = NULL;
  FUNC_OnConnectionBanned onConnectionBanned = NULL;
  FUNC_OnNetworkQuality onNetworkQuality = NULL;
  FUNC_onCaptureVideoFrameRaw onCaptureVideoFrameRaw = NULL;
  FUNC_onRenderVideoFrameRaw onRenderVideoFrameRaw = NULL;
};

class CWrapperRtcEngineEventHandler : public IRtcEngineEventHandler
{
private:
  EngineEvent *engineEvent = nullptr;
  const char *TAG = "CWrapperRtcEngineEventHandler";

public:
  CWrapperRtcEngineEventHandler();
  ~CWrapperRtcEngineEventHandler();

  void initEventOnJoinChannelSuccess(FUNC_OnJoinChannelSuccess onJoinChannelSuccess);

  void initEventOnReJoinChannelSuccess(FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess);

  void initEventOnConnectionLost(FUNC_OnConnectionLost onConnectionLost);

  void initEventOnLeaveChannel(FUNC_OnLeaveChannel onLeaveChannel);

  void initEventOnConnectionInterrupted(FUNC_OnConnectionInterrupted onConnectionInterrupted);

  void initEventOnRequestToken(FUNC_OnRequestToken onRequestToken);

  void initEventOnUserJoined(FUNC_OnUserJoined onUserJoined);

  void initEventOnUserOffline(FUNC_OnUserOffline onUserOffline);

  void initEventOnAudioVolumeIndication(FUNC_OnAudioVolumeIndication onAudioVolumeIndication);

  void initEventOnUserMuteAudio(FUNC_OnUserMuteAudio onUserMuteAudio);

  void initEventOnSDKWarning(FUNC_OnSDKWarning onSDKWarning);

  void initEventOnSDKError(FUNC_OnSDKError onSDKError);

  void initEventOnRtcStats(FUNC_OnRtcStats onRtcStats);

  void initEventOnAudioMixingFinished(FUNC_OnAudioMixingFinished onAudioMixingFinished);

  void initEventOnAudioRouteChanged(FUNC_OnAudioRouteChanged onAudioRouteChanged);

  void initEventOnFirstRemoteVideoDecoded(FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded);

  void initEventOnVideoSizeChanged(FUNC_OnVideoSizeChanged onVideoSizeChanged);

  void initEventOnClientRoleChanged(FUNC_OnClientRoleChanged onClientRoleChanged);

  void initEventOnUserMuteVideo(FUNC_OnUserMuteVideo onUserMuteVideo);

  void initEventOnMicrophoneEnabled(FUNC_OnMicrophoneEnabled onMicrophoneEnabled);

  void initEventOnApiExecuted(FUNC_OnApiExecuted onApiCallExecuted);

  void initEventOnFirstLocalAudioFrame(FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame);

  void initEventOnFirstRemoteAudioFrame(FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame);

  void initEventOnLastmileQuality(FUNC_OnLastmileQuality onLastmileQuality);

  void initEventOnAudioQuality(FUNC_OnAudioQuality onAudioQuality);

  void initEventOnStreamInjectedStatus(FUNC_OnStreamInjectedStatus onStreamInjectedStatus);

  void initEventOnStreamUnpublished(FUNC_OnStreamUnpublished onStreamUnpublished);

  void initEventOnStreamPublished(FUNC_OnStreamPublished onStreamPublished);

  void initEventOnStreamMessageError(FUNC_OnStreamMessageError onStreamMessageError);

  void initEventOnStreamMessage(FUNC_OnStreamMessage onStreamMessage);

  void initEventOnConnectionBanned(FUNC_OnConnectionBanned onConnectionBanned);

  void initEventOnNetworkQuality(FUNC_OnNetworkQuality onNetworkQuality);

  void initEventOnCaptureVideoFrameRaw(FUNC_onCaptureVideoFrameRaw onCaptureVideoFrameRaw);

  void initEventOnRenderVideoFrameRaw(FUNC_onRenderVideoFrameRaw onRenderVideoFrameRaw);

  void onJoinChannelSuccess(const char *channel, uid_t userId, int elapsed);

  void onLeaveChannel(const RtcStats &stats);

  void onRejoinChannelSuccess(const char *channel, uid_t userId, int elapsed);

  void onUserJoined(uid_t userId, int elapsed);

  void onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole);

  void onUserOffline(uid_t userId, USER_OFFLINE_REASON_TYPE reason);

  void onUserMuteAudio(uid_t userId, bool muted);

  void onFirstRemoteVideoDecoded(uid_t userId, int width, int height, int elapsed);

  void onUserMuteVideo(uid_t userId, bool muted);

  void onAudioRoutingChanged(int routing);

  void onConnectionLost();

  void onRequestToken();

  void onAudioVolumeIndication(const AudioVolumeInfo *speakers, unsigned int speakerNumber,
                               int totalVolume);

  void onWarning(int warn, const char *msg);

  void onError(int err, const char *msg);
  //
  void onRtcStats(const RtcStats &stats);
  //
  void onAudioMixingFinished();

  void onVideoSizeChanged(uid_t userId, int width, int height, int rotation);

  void onConnectionInterrupted();

  void onMicrophoneEnabled(bool enabled);

  void onAudioQuality(uid_t userId, int quality, unsigned short delay, unsigned short lost);

  void onRemoteVideoTransportStats(
      uid_t uid, unsigned short delay, unsigned short lost,
      unsigned short rxKBitRate);
  void onRemoteAudioTransportStats(
      uid_t uid, unsigned short delay, unsigned short lost,
      unsigned short rxKBitRate);

  void onStreamInjectedStatus(const char *url, uid_t userId, int status);

  void onTranscodingUpdated();

  void onStreamUnpublished(const char *url);

  void onStreamPublished(const char *url, int error);

  void onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted);

  void onActiveSpeaker(uid_t userId);

  void onFirstRemoteAudioFrame(uid_t userId, int elapsed);

  void onFirstLocalAudioFrame(int elapsed);

  void onMediaEngineStartCallSuccess();

  void onMediaEngineLoadSuccess();

  void onStreamMessageError(uid_t userId, int streamId, int code, int missed, int cached);

  void onStreamMessage(uid_t userId, int streamId, const char *data, size_t length);

  void onRefreshRecordingServiceStatus(int status);

  void onConnectionBanned();

  void onLastmileQuality(int quality);

  void onVideoStopped();

  void onApiCallExecuted(int err, const char *api, const char *result);

  void onNetworkQuality(uid_t uid, int txQuality, int rxQuality);

  void onCaptureVideoFrameRaw(int width, int height, const unsigned char* yBuffer, int rotation);

  void onRenderVideoFrameRaw(uid_t userId, int width, int height, const unsigned char* yBuffer, int rotation);
};

#endif