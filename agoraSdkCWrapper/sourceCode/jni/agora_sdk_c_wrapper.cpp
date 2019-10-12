#include "agora_sdk_c_wrapper.h"

extern "C"
{
    static CAgoraSDKObject *cAgoraSDKObject = NULL;
#define CHECKWHEATHERINITAGORASDKOBJECTVOID()                  \
    if (cAgoraSDKObject == nullptr || cAgoraSDKObject == NULL) \
    {                                                          \
        return;                                                \
    }

#define CHECKWHEATHERINITAGORASDKOBJECTINT()                   \
    if (cAgoraSDKObject == nullptr || cAgoraSDKObject == NULL) \
    {                                                          \
        return NOT_INIT_AGORA_SDK_OBJECT;                      \
    }

#define CHECKWHEATHERINITAGORASDKCHAR()                     \
    string s = "-7";                                        \
    if (cAgoraSDKObject == NULL || cAgoraSDKObject == NULL) \
    {                                                       \
        return (char *)s.data();                            \
    }

    void initCallBackObject()
    {
        cAgoraSDKObject = CAgoraSDKObject::getCAgoraSDKInstance();
    }

    void initEventOnJoinChannelSuccess(FUNC_OnJoinChannelSuccess onJoinChannelSuccess)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnJoinChannelSuccess(onJoinChannelSuccess);
    }

    void initEventOnReJoinChannelSuccess(FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnReJoinChannelSuccess(onReJoinChannelSuccess);
    }

    void initEventOnConnectionLost(FUNC_OnConnectionLost onConnectionLost)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnConnectionLost(onConnectionLost);
    }

    void initEventOnLeaveChannel(FUNC_OnLeaveChannel onLeaveChannel)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnLeaveChannel(onLeaveChannel);
    }

    void initEventOnConnectionInterrupted(FUNC_OnConnectionInterrupted onConnectionInterrupted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnConnectionInterrupted(onConnectionInterrupted);
    }

    void initEventOnRequestToken(FUNC_OnRequestToken onRequestToken)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnRequestToken(onRequestToken);
    }

    void initEventOnUserJoined(FUNC_OnUserJoined onUserJoined)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnUserJoined(onUserJoined);
    }

    void initEventOnUserOffline(FUNC_OnUserOffline onUserOffline)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnUserOffline(onUserOffline);
    }

    void initEventOnAudioVolumeIndication(FUNC_OnAudioVolumeIndication onAudioVolumeIndication)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnAudioVolumeIndication(onAudioVolumeIndication);
    }

    void initEventOnUserMuteAudio(FUNC_OnUserMuteAudio onUserMuteAudio)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnUserMuteAudio(onUserMuteAudio);
    }

    void initEventOnSDKWarning(FUNC_OnSDKWarning onSDKWarning)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnSDKWarning(onSDKWarning);
    }

    void initEventOnSDKError(FUNC_OnSDKError onSDKError)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnSDKError(onSDKError);
    }

    void initEventOnRtcStats(FUNC_OnRtcStats onRtcStats)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnRtcStats(onRtcStats);
    }

    void initEventOnAudioMixingFinished(FUNC_OnAudioMixingFinished onAudioMixingFinished)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnAudioMixingFinished(onAudioMixingFinished);
    }

    void initEventOnAudioRouteChanged(FUNC_OnAudioRouteChanged onAudioRouteChanged)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnAudioRouteChanged(onAudioRouteChanged);
    }

    void initEventOnFirstRemoteVideoDecoded(FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnFirstRemoteVideoDecoded(onFirstRemoteVideoDecoded);
    }

    void initEventOnVideoSizeChanged(FUNC_OnVideoSizeChanged onVideoSizeChanged)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnVideoSizeChanged(onVideoSizeChanged);
    }

    void initEventOnClientRoleChanged(FUNC_OnClientRoleChanged onClientRoleChanged)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnClientRoleChanged(onClientRoleChanged);
    }

    void initEventOnUserMuteVideo(FUNC_OnUserMuteVideo onUserMuteVideo)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnUserMuteVideo(onUserMuteVideo);
    }

    void initEventOnMicrophoneEnabled(FUNC_OnMicrophoneEnabled onMicrophoneEnabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnMicrophoneEnabled(onMicrophoneEnabled);
    }

    void initEventOnApiExecuted(FUNC_OnApiExecuted onApiCallExecuted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnApiExecuted(onApiCallExecuted);
    }

    void initEventOnFirstLocalAudioFrame(FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnFirstLocalAudioFrame(onFirstLocalAudioFrame);
    }

    void initEventOnFirstRemoteAudioFrame(FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnFirstRemoteAudioFrame(onFirstRemoteAudioFrame);
    }

    void initEventOnLastmileQuality(FUNC_OnLastmileQuality onLastmileQuality)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnLastmileQuality(onLastmileQuality);
    }

    void initEventOnAudioQuality(FUNC_OnAudioQuality onAudioQuality)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnAudioQuality(onAudioQuality);
    }

    void initEventOnStreamInjectedStatus(FUNC_OnStreamInjectedStatus onStreamInjectedStatus)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnStreamInjectedStatus(onStreamInjectedStatus);
    }

    void initEventOnStreamUnpublished(FUNC_OnStreamUnpublished onStreamUnpublished)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnStreamUnpublished(onStreamUnpublished);
    }

    void initEventOnStreamPublished(FUNC_OnStreamPublished onStreamPublished)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnStreamPublished(onStreamPublished);
    }

    void initEventOnStreamMessageError(FUNC_OnStreamMessageError onStreamMessageError)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnStreamMessageError(onStreamMessageError);
    }

    void initEventOnStreamMessage(FUNC_OnStreamMessage onStreamMessage)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnStreamMessage(onStreamMessage);
    }

    void initEventOnConnectionBanned(FUNC_OnConnectionBanned onConnectionBanned)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnConnectionBanned(onConnectionBanned);
    }

    void initEventOnNetworkQuality(FUNC_OnNetworkQuality onNetworkQuality)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnNetworkQuality(onNetworkQuality);
    }

    bool createEngine(const char *appId)
    {
       // PRINTF(" createEngine ");
        return cAgoraSDKObject->getCAgoraSDKInstance()->createEngine(appId);
    }

    void deleteEngine()
    {
       // PRINTF(" deleteEngine ");
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCAgoraSDKInstance()->deleteEngine();
        cAgoraSDKObject->releaseCAgoraSDKInstance();
        cAgoraSDKObject = NULL;
    }

    const char *getSdkVersion()
    {
        CHECKWHEATHERINITAGORASDKCHAR();
        return cAgoraSDKObject->getCAgoraSDKInstance()->getSdkVersion();
    }

    const char *getMediaEngineVersion()
    {
        CHECKWHEATHERINITAGORASDKCHAR();
        return cAgoraSDKObject->getCAgoraSDKInstance()->getMediaEngineVersion();
    }

    int joinChannel(const char *channelKey, const char *channelName, const char *info, unsigned int uid)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->joinChannel(channelKey, channelName, info, uid);
    }

    int renewToken(const char *token)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->renewToken(token);
    }

    int leaveChannel()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->leaveChannel();
    }

    int enableLastmileTest()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableLastmileTest();
    }

    int disableLastmileTest()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->disableLastmileTest();
    }

    int enableVideo()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableVideo();
    }

    int disableVideo()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->disableVideo();
    }

    int enableLocalVideo(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableLocalVideo(enabled);
    }

    int startPreview()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->startPreview();
    }

    int stopPreview()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopPreview();
    }

    int enableAudio()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableAudio();
    }

    int enableLocalAudio(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableLocalAudio(enabled);
    }

    int disableAudio()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->disableAudio();
    }

    int setParameters(const char *options)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setParameters(options);
    }

    char *getParameter(const char *parameter, const char *args)
    {
        CHECKWHEATHERINITAGORASDKCHAR();
        return cAgoraSDKObject->getCAgoraSDKInstance()->getParameter(parameter, args);
    }

    char *getCallId()
    {
        CHECKWHEATHERINITAGORASDKCHAR();
        std::string sCallId = cAgoraSDKObject->getCAgoraSDKInstance()->getCallId();
        return strdup(sCallId.data());
    }

    void freeObject(void *obj)
    {
        if (obj)
        {
            free(obj);
        }
    }

    int rate(const char *callId, int rating, const char *desc)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->rate(callId, rating, desc);
    }

    int complain(const char *callId, const char *desc)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->complain(callId, desc);
    }

    int setEnableSpeakerphone(int enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setEnableSpeakerphone(enabled);
    }

    int isSpeakerphoneEnabled()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->isSpeakerphoneEnabled();
    }

    int setDefaultAudioRoutetoSpeakerphone(bool defaultToSpeaker)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setDefaultAudioRouteToSpeakerphone(defaultToSpeaker);
    }

    int setSpeakerphoneVolume(int volume)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setSpeakerphoneVolume(volume);
    }

    int enableAudioVolumeIndication(int interval, int smooth)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableAudioVolumeIndication(interval, smooth);
    }

    int startAudioRecording(const char *filePath, int quality)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->startAudioRecording(filePath, quality);
    }

    int stopAudioRecording()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopAudioRecording();
    }

    int startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->startAudioMixing(filePath, loopBack, replace, cycle);
    }

    int stopAudioMixing()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopAudioMixing();
    }

    int pauseAudioMixing()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->pauseAudioMixing();
    }

    int resumeAudioMixing()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->resumeAudioMixing();
    }

    int adjustAudioMixingVolume(int volume)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->adjustAudioMixingVolume(volume);
    }

    int getAudioMixingDuration()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->getAudioMixingDuration();
    }

    int getAudioMixingCurrentPosition()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->getAudioMixingCurrentPosition();
    }

    int setAudioMixingPosition(int pos)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setAudioMixingPosition(pos);
    }

    int startEchoTest()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->startEchoTest();
    }

    int stopEchoTest()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopEchoTest();
    }

    int muteLocalAudioStream(bool muted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->muteLocalAudioStream(muted);
    }

    int muteAllRemoteAudioStreams(bool muted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->muteAllRemoteAudioStreams(muted);
    }

    int muteRemoteAudioStream(unsigned int uid, bool muted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->muteRemoteAudioStream(uid, muted);
    }

    int switchCamera()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->switchCamera();
    }

    int setVideoProfile(int profile, bool swapWidthAndHeight)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setVideoProfile(profile, swapWidthAndHeight);
    }

    int muteLocalVideoStream(bool muted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->muteLocalVideoStream(muted);
    }

    int muteAllRemoteVideoStreams(bool muted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->muteAllRemoteVideoStreams(muted);
    }

    int muteRemoteVideoStream(unsigned int uid, bool muted)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->muteRemoteVideoStream(uid, muted);
    }

    int setLogFile(const char *filePath)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setLogFile(filePath);
    }

    int setLogFilter(unsigned int filter)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setLogFilter(filter);
    }

    int setChannelProfile(int profile)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setChannelProfile(profile);
    }

    int setClientRole(int role)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setClientRole(role);
    }

    int enableDualStreamMode(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableDualStreamMode(enabled);
    }

    int setEncryptionMode(const char *encryptionMode)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setEncryptionMode(encryptionMode);
    }

    int setEncryptionSecret(const char *secret)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setEncryptionSecret(secret);
    }

    int setRemoteVideoStreamType(unsigned int uid, int streamType)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setRemoteVideoStreamType(uid, streamType);
    }

    int startRecordingService(const char *recordingKey)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->startRecordingService(recordingKey);
    }

    int stopRecordingService(const char *recordingKey)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopRecordingService(recordingKey);
    }

    int refreshRecordingServiceStatus()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->refreshRecordingServiceStatus();
    }

    int createDataStream(bool reliable, bool ordered)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        int streamId = 0;
        int ret = 0;
        ret = cAgoraSDKObject->getCAgoraSDKInstance()->createDataStream(&streamId, reliable, ordered);
        if (ret < 0)
        {
        }
        else
        {
            ret = streamId;
        }

        return ret;
    }

    int sendStreamMessage(int streamId, const char *data, size_t length)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->sendStreamMessage(streamId, data, length);
    }

    int setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setRecordingAudioFrameParametersWithSampleRate(sampleRate, channel, mode, samplesPerCall);
    }

    int setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setPlaybackAudioFrameParametersWithSampleRate(sampleRate, channel, mode, samplesPerCall);
    }

    int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setMixedAudioFrameParameters(sampleRate, samplesPerCall);
    }

    int adjustRecordingSignalVolume(int volume)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->adjustRecordingSignalVolume(volume);
    }

    int adjustPlaybackSignalVolume(int volume)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->adjustPlaybackSignalVolume(volume);
    }

    int setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setHighQualityAudioParametersWithFullband(fullband, stereo, fullBitrate);
    }

    int enableInEarMonitoring(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableInEarMonitoring(enabled);
    }

    int enableWebSdkInteroperability(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableWebSdkInteroperability(enabled);
    }

    int setVideoQualityParameters(bool preferFrameRateOverImageQuality)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setVideoQualityParameters(preferFrameRateOverImageQuality);
    }

    int setPlaybackDeviceVolume(int volume)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setPlaybackDeviceVolume(volume);
    }

    int getEffectsVolume()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->getEffectsVolume();
    }

    int setEffectsVolume(int volume)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setEffectsVolume(volume);
    }

    int playEffect(int soundId, const char *filePath, int loopCountPlayEffect, double pitch, double pan, int gain, bool publish)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->playEffect(soundId, filePath, loopCountPlayEffect, pitch, pan, gain, publish);
    }

    int stopEffect(int soundId)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopEffect(soundId);
    }

    int stopAllEffects()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->stopAllEffects();
    }

    int preloadEffect(int soundId, const char *filePath)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->preloadEffect(soundId, filePath);
    }

    int unloadEffect(int soundId)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->unloadEffect(soundId);
    }

    int pauseEffect(int soundId)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->pauseEffect(soundId);
    }

    int pauseAllEffects()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->pauseAllEffects();
    }

    int resumeEffect(int soundId)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->resumeEffect(soundId);
    }

    int resumeAllEffects()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->resumeAllEffects();
    }

    int setLocalVoicePitch(double pitch)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setLocalVoicePitch(pitch);
    }

    int setRemoteVoicePosition(uid_t uid, double pan, double gain)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setRemoteVoicePosition(uid, pan, gain);
    }

    int enableSoundPositionIndication(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableSoundPositionIndication(enabled);
    }

    int setVoiceOnlyMode(bool enabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setVoiceOnlyMode(enabled);
    }

    int setDefaultMuteAllRemoteAudioStreams(bool mute)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setDefaultMuteAllRemoteAudioStreams(mute);
    }

    int setDefaultMuteAllRemoteVideoStreams(bool mute)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setDefaultMuteAllRemoteVideoStreams(mute);
    }

    //video api
    int enableVideoObserver()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->enableVideoObserver();
    }

    int disableVideoObserver()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->disableVideoObserver();
    }

    int generateNativeTexture()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->generateNativeTexture();
    }

    int updateTexture(int texId, unsigned char *data, unsigned int uid)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->updateTexture(texId, data, uid);
    }

    void deleteTexture(int tex)
    {
        CHECKWHEATHERINITAGORASDKOBJECTVOID();
        cAgoraSDKObject->getCAgoraSDKInstance()->deleteTexture(tex);
    }

    int pushExternVideoFrame(int type, int format, void* buffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, long timestamp)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->pushExternVideoFrame(type, format, buffer, stride, height, cropLeft, cropTop, cropRight, cropBottom, rotation, timestamp);
    }

    int setExternalVideoSource(bool enable, bool useTexture)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return cAgoraSDKObject->getCAgoraSDKInstance()->setExternalVideoSource(enable, useTexture);
    }

    int setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, unsigned int transcodingUserUid, int transcodingUsersX, int transcodingUsersY, int transcodingUsersWidth, int transcodingUsersHeight, int transcodingUsersZorder, double transcodingUsersAlpha, int transcodingUsersAudioChannel, const char *transcodingExtraInfo, const char * metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->setLiveTranscoding(width, height, videoBitrate, videoFramerate, lowLatency, videoGroup, video_codec_profile, backgroundColor, userCount, transcodingUserUid, transcodingUsersX, transcodingUsersY, transcodingUsersWidth, transcodingUsersHeight, transcodingUsersZorder, transcodingUsersAlpha, transcodingUsersAudioChannel, transcodingExtraInfo, metaData, watermarkRtcImageUrl, watermarkRtcImageX, watermarkRtcImageY, watermarkRtcImageWidth, watermarkRtcImageHeight, backgroundImageRtcImageUrl, backgroundImageRtcImageX, backgroundImageRtcImageY, backgroundImageRtcImageWidth, backgroundImageRtcImageHeight, audioSampleRate, audioBitrate, audioChannels, audioCodecProfile);
    }

    int addPublishStreamUrl(const char *url, bool transcodingEnabled)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->addPublishStreamUrl(url, transcodingEnabled);
    }

    int removePublishStreamUrl(const char *url)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->removePublishStreamUrl(url);
    }
    
    int configPublisher(int width, int height, int framerate, int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char* injectStreamUrl, const char* publishUrl, const char* rawStreamUrl, const char* extraInfo)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->configPublisher(width, height, framerate, bitrate, defaultLayout, lifecycle, owner, injectStreamWidth, injectStreamHeight, injectStreamUrl, publishUrl, rawStreamUrl, extraInfo);
    }

    int setVideoCompositingLayout(int canvasWidth, int canvasHeight, const char* backgroundColor, uid_t regionUid, double regionX, double regionY, double regionWidth, double regionHeight, int regionZOrder, double regionAlpha, int regionRenderMode, int regionCount, const char* appData, int appDataLength)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->setVideoCompositingLayout(canvasWidth, canvasHeight, backgroundColor, regionUid, regionX, regionY, regionWidth, regionHeight, regionZOrder, regionAlpha, regionRenderMode, regionCount, appData, appDataLength);
    }

    int clearVideoCompositingLayout()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->clearVideoCompositingLayout();
    }

    int addVideoWatermark(const char* url, int x, int y, int width, int height)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->addVideoWatermark(url, x, y, width, height);
    }

    int clearVideoWatermarks()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->clearVideoWatermarks();
    }

    int setBeautyEffectOptions(bool enabled, int beatyOptionsLighteningContrastLevel, float beatyOptionsLighteningLevel, float beatyOptionsSmoothnessLevel, float beatyOptionsRednessLevel)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->setBeautyEffectOptions(enabled, beatyOptionsLighteningContrastLevel, beatyOptionsLighteningLevel, beatyOptionsSmoothnessLevel, beatyOptionsRednessLevel);
    }

    int addInjectStreamUrl(const char* url, int injectStreamWidth, int injectStreamHeight, int injectStreamVideoGop, int injectStreamVideoFramerate, int injectStreamVideoBitrate, int injectStreamAudioSampleRate, int injectStreamAudioBitrate, int injectStreamAudioChannels)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->addInjectStreamUrl(url, injectStreamWidth, injectStreamHeight, injectStreamVideoGop, injectStreamVideoFramerate, injectStreamVideoBitrate, injectStreamAudioSampleRate, injectStreamAudioBitrate, injectStreamAudioChannels);
    }
    
    int removeInjectStreamUrl(const char* url)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->removeInjectStreamUrl(url);
    }

    int setExternalAudioSource(bool enabled, int sampleRate, int channels)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->setExternalAudioSource(enabled, sampleRate, channels);
    }

    int setExternalAudioSink(bool enabled, int sampleRate, int channels)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->setExternalAudioSink(enabled, sampleRate, channels);
    }

    int pushExternalAudioFrame(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->pushAudioFrame(type, samples, bytesPerSample, channels, samplesPerSec, buffer, renderTimeMs, avsync_type);
    }

	int setupLocalVideo(int view, int renderMode, uid_t uid, void* priv)
	{
		CHECKWHEATHERINITAGORASDKOBJECTINT();
		return CAgoraSDKObject::getCAgoraSDKInstance()->setupLocalVideo(view, renderMode, uid, priv);
	}
	
	int setupRemoteVideo(int view, int renderMode, uid_t uid, void* priv)
	{
		CHECKWHEATHERINITAGORASDKOBJECTINT();
		return CAgoraSDKObject::getCAgoraSDKInstance()->setupRemoteVideo(view, renderMode, uid, priv);
	}

    int startScreenCapture(HWND windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate, const char* GameName)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->startScreenCapture(windowId, captureFreq, rc_left, rc_top, rc_width, rc_height, bitrate, GameName);
    }

    int stopScreenCapture()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->stopScreenCapture();
    }

    int startScreenCaptureEx(HWND windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate)
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->startScreenCaptureEx(windowId, captureFreq, rc_left, rc_top, rc_width, rc_height, bitrate);
    }

    int stopScreenCaptureEx()
    {
        CHECKWHEATHERINITAGORASDKOBJECTINT();
        return CAgoraSDKObject::getCAgoraSDKInstance()->stopScreenCaptureEx();
    }

#if defined(WRAPPER_ANDROID)
    jint JNI_OnLoad(JavaVM *vm, void *)
    {
        JNIEnv *env;
        vm->GetEnv((void **)&env, JNI_VERSION_1_6);
        jclass rtcEngineImpClass = env->FindClass("io/agora/rtc/internal/RtcEngineImpl");
        jmethodID methodId = env->GetStaticMethodID(rtcEngineImpClass, "loadNativeLibrary", "()V");
        env->CallStaticVoidMethod(rtcEngineImpClass, methodId);
        PRINTF("JNI_OnLoad");
        return (JNI_VERSION_1_6);
    }
#endif
}

AGORA_API void initEventOnCaptureVideoFrameRaw(FUNC_onCaptureVideoFrameRaw onCaptureVideoFrameRaw)
{
    CHECKWHEATHERINITAGORASDKOBJECTVOID();
    cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnCaptureVideoFrameRaw(onCaptureVideoFrameRaw);
}

AGORA_API void initEventOnRenderVideoFrameRaw(FUNC_onRenderVideoFrameRaw onRenderVideoFrameRaw)
{
    CHECKWHEATHERINITAGORASDKOBJECTVOID();
    cAgoraSDKObject->getCWrapperRtcEngineEventHandler()->initEventOnRenderVideoFrameRaw(onRenderVideoFrameRaw);
}
