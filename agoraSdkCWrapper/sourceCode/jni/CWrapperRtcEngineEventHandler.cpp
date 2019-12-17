#include "CWrapperRtcEngineEventHandler.h"

#define CHECKWHEATHERINITENGINEEVENT()                         \
    if (CWrapperRtcEngineEventHandler::engineEvent == nullptr) \
    {                                                          \
        return;                                                \
    }

CWrapperRtcEngineEventHandler::CWrapperRtcEngineEventHandler()
{
    CWrapperRtcEngineEventHandler::engineEvent = new EngineEvent();
};

CWrapperRtcEngineEventHandler::~CWrapperRtcEngineEventHandler()
{
    if (CWrapperRtcEngineEventHandler::engineEvent)
    {
        delete CWrapperRtcEngineEventHandler::engineEvent;
    }
};

void CWrapperRtcEngineEventHandler::initEventOnJoinChannelSuccess(FUNC_OnJoinChannelSuccess onJoinChannelSuccess)
{
    CWrapperRtcEngineEventHandler::engineEvent->onJoinChannelSuccess = onJoinChannelSuccess;
}

void CWrapperRtcEngineEventHandler::initEventOnReJoinChannelSuccess(FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess)
{
    CWrapperRtcEngineEventHandler::engineEvent->onReJoinChannelSuccess = onReJoinChannelSuccess;
}

void CWrapperRtcEngineEventHandler::initEventOnConnectionLost(FUNC_OnConnectionLost onConnectionLost)
{
    CWrapperRtcEngineEventHandler::engineEvent->onConnectionLost = onConnectionLost;
}

void CWrapperRtcEngineEventHandler::initEventOnLeaveChannel(FUNC_OnLeaveChannel onLeaveChannel)
{
    CWrapperRtcEngineEventHandler::engineEvent->onLeaveChannel = onLeaveChannel;
}

void CWrapperRtcEngineEventHandler::initEventOnConnectionInterrupted(FUNC_OnConnectionInterrupted onConnectionInterrupted)
{
    CWrapperRtcEngineEventHandler::engineEvent->onConnectionInterrupted = onConnectionInterrupted;
}

void CWrapperRtcEngineEventHandler::initEventOnRequestToken(FUNC_OnRequestToken onRequestToken)
{
    CWrapperRtcEngineEventHandler::engineEvent->onRequestToken = onRequestToken;
}

void CWrapperRtcEngineEventHandler::initEventOnUserJoined(FUNC_OnUserJoined onUserJoined)
{
    CWrapperRtcEngineEventHandler::engineEvent->onUserJoined = onUserJoined;
}

void CWrapperRtcEngineEventHandler::initEventOnUserOffline(FUNC_OnUserOffline onUserOffline)
{
    CWrapperRtcEngineEventHandler::engineEvent->onUserOffline = onUserOffline;
}

void CWrapperRtcEngineEventHandler::initEventOnAudioVolumeIndication(FUNC_OnAudioVolumeIndication onAudioVolumeIndication)
{
    CWrapperRtcEngineEventHandler::engineEvent->onAudioVolumeIndication = onAudioVolumeIndication;
}

void CWrapperRtcEngineEventHandler::initEventOnUserMuteAudio(FUNC_OnUserMuteAudio onUserMuteAudio)
{
    CWrapperRtcEngineEventHandler::engineEvent->onUserMuteAudio = onUserMuteAudio;
}

void CWrapperRtcEngineEventHandler::initEventOnSDKWarning(FUNC_OnSDKWarning onSDKWarning)
{
    CWrapperRtcEngineEventHandler::engineEvent->onSDKWarning = onSDKWarning;
}

void CWrapperRtcEngineEventHandler::initEventOnSDKError(FUNC_OnSDKError onSDKError)
{
    CWrapperRtcEngineEventHandler::engineEvent->onSDKError = onSDKError;
}

void CWrapperRtcEngineEventHandler::initEventOnRtcStats(FUNC_OnRtcStats onRtcStats)
{
    CWrapperRtcEngineEventHandler::engineEvent->onRtcStats = onRtcStats;
}

void CWrapperRtcEngineEventHandler::initEventOnAudioMixingFinished(FUNC_OnAudioMixingFinished onAudioMixingFinished)
{
    CWrapperRtcEngineEventHandler::engineEvent->onAudioMixingFinished = onAudioMixingFinished;
}

void CWrapperRtcEngineEventHandler::initEventOnAudioRouteChanged(FUNC_OnAudioRouteChanged onAudioRouteChanged)
{
    CWrapperRtcEngineEventHandler::engineEvent->onAudioRouteChanged = onAudioRouteChanged;
}

void CWrapperRtcEngineEventHandler::initEventOnFirstRemoteVideoDecoded(FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded)
{
    CWrapperRtcEngineEventHandler::engineEvent->onFirstRemoteVideoDecoded = onFirstRemoteVideoDecoded;
}

void CWrapperRtcEngineEventHandler::initEventOnVideoSizeChanged(FUNC_OnVideoSizeChanged onVideoSizeChanged)
{
    CWrapperRtcEngineEventHandler::engineEvent->onVideoSizeChanged = onVideoSizeChanged;
}

void CWrapperRtcEngineEventHandler::initEventOnClientRoleChanged(FUNC_OnClientRoleChanged onClientRoleChanged)
{
    CWrapperRtcEngineEventHandler::engineEvent->onClientRoleChanged = onClientRoleChanged;
}

void CWrapperRtcEngineEventHandler::initEventOnUserMuteVideo(FUNC_OnUserMuteVideo onUserMuteVideo)
{
    CWrapperRtcEngineEventHandler::engineEvent->onUserMuteVideo = onUserMuteVideo;
}

void CWrapperRtcEngineEventHandler::initEventOnMicrophoneEnabled(FUNC_OnMicrophoneEnabled onMicrophoneEnabled)
{
    CWrapperRtcEngineEventHandler::engineEvent->onMicrophoneEnabled = onMicrophoneEnabled;
}

void CWrapperRtcEngineEventHandler::initEventOnApiExecuted(FUNC_OnApiExecuted onApiCallExecuted)
{
    CWrapperRtcEngineEventHandler::engineEvent->onApiCallExecuted = onApiCallExecuted;
}

void CWrapperRtcEngineEventHandler::initEventOnFirstLocalAudioFrame(FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame)
{
    CWrapperRtcEngineEventHandler::engineEvent->onFirstLocalAudioFrame = onFirstLocalAudioFrame;
}

void CWrapperRtcEngineEventHandler::initEventOnFirstRemoteAudioFrame(FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame)
{
    CWrapperRtcEngineEventHandler::engineEvent->onFirstRemoteAudioFrame = onFirstRemoteAudioFrame;
}

void CWrapperRtcEngineEventHandler::initEventOnLastmileQuality(FUNC_OnLastmileQuality onLastmileQuality)
{
    CWrapperRtcEngineEventHandler::engineEvent->onLastmileQuality = onLastmileQuality;
}

void CWrapperRtcEngineEventHandler::initEventOnAudioQuality(FUNC_OnAudioQuality onAudioQuality)
{
    CWrapperRtcEngineEventHandler::engineEvent->onAudioQuality = onAudioQuality;
}

void CWrapperRtcEngineEventHandler::initEventOnStreamInjectedStatus(FUNC_OnStreamInjectedStatus onStreamInjectedStatus)
{
    CWrapperRtcEngineEventHandler::engineEvent->onStreamInjectedStatus = onStreamInjectedStatus;
}

void CWrapperRtcEngineEventHandler::initEventOnStreamUnpublished(FUNC_OnStreamUnpublished onStreamUnpublished)
{
    CWrapperRtcEngineEventHandler::engineEvent->onStreamUnpublished = onStreamUnpublished;
}

void CWrapperRtcEngineEventHandler::initEventOnStreamPublished(FUNC_OnStreamPublished onStreamPublished)
{
    CWrapperRtcEngineEventHandler::engineEvent->onStreamPublished = onStreamPublished;
}

void CWrapperRtcEngineEventHandler::initEventOnStreamMessageError(FUNC_OnStreamMessageError onStreamMessageError)
{
    CWrapperRtcEngineEventHandler::engineEvent->onStreamMessageError = onStreamMessageError;
}

void CWrapperRtcEngineEventHandler::initEventOnStreamMessage(FUNC_OnStreamMessage onStreamMessage)
{
    CWrapperRtcEngineEventHandler::engineEvent->onStreamMessage = onStreamMessage;
}

void CWrapperRtcEngineEventHandler::initEventOnConnectionBanned(FUNC_OnConnectionBanned onConnectionBanned)
{
    CWrapperRtcEngineEventHandler::engineEvent->onConnectionBanned = onConnectionBanned;
}

void CWrapperRtcEngineEventHandler::initEventOnNetworkQuality(FUNC_OnNetworkQuality onNetworkQuality)
{
    CWrapperRtcEngineEventHandler::engineEvent->onNetworkQuality = onNetworkQuality;
}


void CWrapperRtcEngineEventHandler::initEventOnCaptureVideoFrameRaw(FUNC_OnCaptureVideoFrameRaw onCaptureVideoFrameRaw)
{
    CWrapperRtcEngineEventHandler::engineEvent->onCaptureVideoFrameRaw = onCaptureVideoFrameRaw;
}


void CWrapperRtcEngineEventHandler::initEventOnRenderVideoFrameRaw(FUNC_OnRenderVideoFrameRaw onRenderVideoFrameRaw)
{
    CWrapperRtcEngineEventHandler::engineEvent->onRenderVideoFrameRaw = onRenderVideoFrameRaw;
}

void CWrapperRtcEngineEventHandler::initEventOnRemoteVideoStats(FUNC_OnRemoteVideoStats onRemoteVideoStats)
{
    CWrapperRtcEngineEventHandler::engineEvent->onRemoteVideoStats = onRemoteVideoStats;
}

void CWrapperRtcEngineEventHandler::onJoinChannelSuccess(const char *channel, uid_t userId, int elapsed)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onJoinChannelSuccess == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onJoinChannelSuccess(channel, userId, elapsed);
}

void CWrapperRtcEngineEventHandler::onLeaveChannel(const RtcStats &stats)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onLeaveChannel == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onLeaveChannel(stats.duration,
                                                               stats.txBytes, stats.rxBytes, stats.txKBitRate,
                                                               stats.rxKBitRate,
                                                               stats.rxAudioKBitRate, stats.txAudioKBitRate,
                                                               stats.rxVideoKBitRate,
                                                               stats.txVideoKBitRate, stats.lastmileDelay,
                                                               stats.userCount,
                                                               stats.cpuAppUsage, stats.cpuTotalUsage);
}

void CWrapperRtcEngineEventHandler::onRejoinChannelSuccess(const char *channel, uid_t userId, int elapsed)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onReJoinChannelSuccess == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onReJoinChannelSuccess(channel, userId, elapsed);
}

void CWrapperRtcEngineEventHandler::onUserJoined(uid_t userId, int elapsed)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onUserJoined == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onUserJoined(userId, elapsed);
}

void CWrapperRtcEngineEventHandler::onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onClientRoleChanged == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onClientRoleChanged((int)oldRole, (int)newRole);
}

void CWrapperRtcEngineEventHandler::onUserOffline(uid_t userId, USER_OFFLINE_REASON_TYPE reason)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onUserOffline == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onUserOffline(userId, reason);
}

void CWrapperRtcEngineEventHandler::onUserMuteAudio(uid_t userId, bool muted)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onUserMuteAudio == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onUserMuteAudio(userId, muted);
}

void CWrapperRtcEngineEventHandler::onFirstRemoteVideoDecoded(uid_t userId, int width, int height, int elapsed)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onFirstRemoteVideoDecoded == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onFirstRemoteVideoDecoded(userId, width, height, elapsed);
}

void CWrapperRtcEngineEventHandler::onUserMuteVideo(uid_t userId, bool muted)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onUserMuteVideo == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onUserMuteVideo(userId, muted);
}

void CWrapperRtcEngineEventHandler::onAudioRoutingChanged(int routing)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onAudioRouteChanged == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onAudioRouteChanged(routing);
}

void CWrapperRtcEngineEventHandler::onConnectionLost()
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onConnectionLost == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onConnectionLost();
}

void CWrapperRtcEngineEventHandler::onRequestToken()
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onRequestToken == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onRequestToken();
}

void CWrapperRtcEngineEventHandler::onAudioVolumeIndication(const AudioVolumeInfo *speakers, unsigned int speakerNumber,
                                                            int totalVolume)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onAudioVolumeIndication == NULL)
        return;

    char szMsg[LENGTH_MAX] = {};
    std::string strPostMsg = "";
    for (int i = 0; i < speakerNumber; i++)
    {
        AudioVolumeInfo *pAVI = (AudioVolumeInfo *)(speakers + i);
        sprintf(szMsg, "%s\t%d\t%d", strPostMsg.data(), pAVI->uid, pAVI->volume);
        strPostMsg = szMsg;
    }
    sprintf(szMsg, "%s", strPostMsg.data());
    CWrapperRtcEngineEventHandler::engineEvent->onAudioVolumeIndication(szMsg, speakerNumber, totalVolume);
}

void CWrapperRtcEngineEventHandler::onWarning(int warn, const char *msg)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onSDKWarning == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onSDKWarning(warn, msg);
}

void CWrapperRtcEngineEventHandler::onError(int err, const char *msg)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onSDKError == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onSDKError(err, msg);
}
//
void CWrapperRtcEngineEventHandler::onRtcStats(const RtcStats &stats)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onRtcStats == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onRtcStats(stats.duration, stats.txBytes, stats.rxBytes,
                                                           stats.txKBitRate, stats.rxKBitRate,
                                                           stats.rxAudioKBitRate, stats.txAudioKBitRate,
                                                           stats.rxVideoKBitRate, stats.txVideoKBitRate,
                                                           stats.lastmileDelay,
                                                           stats.userCount, stats.cpuAppUsage,
                                                           stats.cpuTotalUsage);
}

void CWrapperRtcEngineEventHandler::onNetworkQuality(uid_t uid, int txQuality, int rxQuality)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onNetworkQuality == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onNetworkQuality(uid, txQuality, rxQuality);
}


void CWrapperRtcEngineEventHandler::onCaptureVideoFrameRaw(int width, int height, const unsigned char* yBuffer, int rotation)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onCaptureVideoFrameRaw == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onCaptureVideoFrameRaw(width, height, yBuffer, rotation);
}


void CWrapperRtcEngineEventHandler::onRenderVideoFrameRaw(uid_t userId, int width, int height, const unsigned char* yBuffer, int rotation)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onRenderVideoFrameRaw == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onRenderVideoFrameRaw(userId, width, height, yBuffer, rotation);
}

void CWrapperRtcEngineEventHandler::onRemoteVideoStats(const RemoteVideoStats& stats)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onRemoteVideoStats == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onRemoteVideoStats(stats.uid, stats.delay, stats.width, stats.height, stats.receivedBitrate, stats.receivedFrameRate, stats.rxStreamType);
}

//
void CWrapperRtcEngineEventHandler::onAudioMixingFinished()
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onAudioMixingFinished == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onAudioMixingFinished();
}

void CWrapperRtcEngineEventHandler::onVideoSizeChanged(uid_t userId, int width, int height, int rotation)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onVideoSizeChanged == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onVideoSizeChanged(userId, width, height, rotation);
}

void CWrapperRtcEngineEventHandler::onConnectionInterrupted()
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onConnectionInterrupted == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onConnectionInterrupted();
}

void CWrapperRtcEngineEventHandler::onMicrophoneEnabled(bool enabled)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onMicrophoneEnabled == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onMicrophoneEnabled(enabled);
}

void CWrapperRtcEngineEventHandler::onFirstRemoteAudioFrame(uid_t userId, int elapsed)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onFirstRemoteAudioFrame == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onFirstRemoteAudioFrame(userId, elapsed);
}

void CWrapperRtcEngineEventHandler::onFirstLocalAudioFrame(int elapsed)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onFirstLocalAudioFrame == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onFirstLocalAudioFrame(elapsed);
}

void CWrapperRtcEngineEventHandler::onApiCallExecuted(int err, const char *api, const char *result)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onApiCallExecuted == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onApiCallExecuted(err, api, result);
}

void CWrapperRtcEngineEventHandler::onLastmileQuality(int quality)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onLastmileQuality == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onLastmileQuality(quality);
}

void CWrapperRtcEngineEventHandler::onAudioQuality(uid_t userId, int quality, unsigned short delay, unsigned short lost)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onAudioQuality == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onAudioQuality(userId, quality, delay, lost);
}

void CWrapperRtcEngineEventHandler::onRemoteVideoTransportStats(
    uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate)
{
}

void CWrapperRtcEngineEventHandler::onRemoteAudioTransportStats(
    uid_t uid, unsigned short delay, unsigned short lost,
    unsigned short rxKBitRate)
{
}

void CWrapperRtcEngineEventHandler::onStreamInjectedStatus(const char *url, uid_t userId, int status)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onStreamInjectedStatus == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onStreamInjectedStatus(url, userId, status);
}

void CWrapperRtcEngineEventHandler::onTranscodingUpdated()
{
}

void CWrapperRtcEngineEventHandler::onStreamUnpublished(const char *url)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onStreamUnpublished == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onStreamUnpublished(url);
}

void CWrapperRtcEngineEventHandler::onStreamPublished(const char *url, int error)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onStreamPublished == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onStreamPublished(url, error);
}

void CWrapperRtcEngineEventHandler::onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted)
{
}

void CWrapperRtcEngineEventHandler::onActiveSpeaker(uid_t userId)
{
}

void CWrapperRtcEngineEventHandler::onMediaEngineStartCallSuccess()
{
}

void CWrapperRtcEngineEventHandler::onMediaEngineLoadSuccess()
{
}

void CWrapperRtcEngineEventHandler::onStreamMessageError(uid_t userId, int streamId, int code, int missed, int cached)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onStreamMessageError == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onStreamMessageError(userId, streamId, code, missed, cached);
}

void CWrapperRtcEngineEventHandler::onStreamMessage(uid_t userId, int streamId, const char *data, size_t length)
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onStreamMessage == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onStreamMessage(userId, streamId, data, length);
}

void CWrapperRtcEngineEventHandler::onRefreshRecordingServiceStatus(int status)
{
}

void CWrapperRtcEngineEventHandler::onConnectionBanned()
{
    if (CWrapperRtcEngineEventHandler::engineEvent->onConnectionBanned == NULL)
        return;

    CWrapperRtcEngineEventHandler::engineEvent->onConnectionBanned();
}

void CWrapperRtcEngineEventHandler::onVideoStopped()
{
}