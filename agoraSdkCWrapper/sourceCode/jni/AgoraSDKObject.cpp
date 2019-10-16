#include "AgoraSDKObject.h"

CAgoraSDKObject *CAgoraSDKObject::cAgoraSDKObjectInstance = nullptr;

CAgoraSDKObject::~CAgoraSDKObject()
{
    CAgoraSDKObject::irtcEngine = nullptr;
    if (CAgoraSDKObject::cWrapperRtcEngineEventHandler)
    {
        delete CAgoraSDKObject::cWrapperRtcEngineEventHandler;
    }
}

CAgoraSDKObject::CAgoraSDKObject()
{
    CAgoraSDKObject::cWrapperRtcEngineEventHandler = new CWrapperRtcEngineEventHandler();
}

CAgoraSDKObject *CAgoraSDKObject::getCAgoraSDKInstance()
{
    if (cAgoraSDKObjectInstance == nullptr)
    {
        cAgoraSDKObjectInstance = new CAgoraSDKObject();
    }
    return cAgoraSDKObjectInstance;
};

void CAgoraSDKObject::releaseCAgoraSDKInstance()
{
    if (cAgoraSDKObjectInstance)
    {
        delete cAgoraSDKObjectInstance;
        cAgoraSDKObjectInstance = nullptr;
    }
}

bool CAgoraSDKObject::createEngine(const char *appId)
{
    RtcEngineContext engineContext;
    engineContext.appId = appId;
    engineContext.eventHandler = getCWrapperRtcEngineEventHandler();
    irtcEngine = createAgoraRtcEngine();
    bool init = irtcEngine->initialize(engineContext);
    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
    mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
    if (mediaEngine)
        mediaEngine->registerVideoFrameObserver(this);
    return init;
}

CWrapperRtcEngineEventHandler *CAgoraSDKObject::getCWrapperRtcEngineEventHandler()
{
    return cWrapperRtcEngineEventHandler;
}

IRtcEngine *CAgoraSDKObject::getCWrapperIRtcEngine()
{
    return irtcEngine;
}

int CAgoraSDKObject::joinChannel(const char *channelKey, const char *channelName, const char *info, uid_t uid)
{
    return irtcEngine->joinChannel(channelKey, channelName, info, uid);
}

int CAgoraSDKObject::leaveChannel()
{
    return irtcEngine->leaveChannel();
}

void CAgoraSDKObject::deleteEngine()
{
    irtcEngine->release(true);
    //delete cWrapperRtcEngineEventHandler;
}

const char *CAgoraSDKObject::getSdkVersion()
{
    return irtcEngine->getVersion(0);
}

const char *CAgoraSDKObject::getMediaEngineVersion()
{
    return "0";
}

int CAgoraSDKObject::renewToken(const char *token)
{
    return irtcEngine->renewToken(token);
}

int CAgoraSDKObject::enableLastmileTest()
{
    return irtcEngine->enableLastmileTest();
}

int CAgoraSDKObject::disableLastmileTest()
{
    return irtcEngine->disableLastmileTest();
}

int CAgoraSDKObject::enableVideo()
{
    return irtcEngine->enableVideo();
}

int CAgoraSDKObject::disableVideo()
{
    return irtcEngine->disableVideo();
}

int CAgoraSDKObject::enableLocalVideo(bool enabled)
{
    RtcEngineParameters param(*irtcEngine);
    return param.enableLocalVideo(enabled);
}

int CAgoraSDKObject::startPreview()
{
    return irtcEngine->startPreview();
}

int CAgoraSDKObject::stopPreview()
{
    return irtcEngine->stopPreview();
}

int CAgoraSDKObject::enableAudio()
{
    return irtcEngine->enableAudio();
}

int CAgoraSDKObject::enableLocalAudio(bool enabled)
{
    return irtcEngine->enableLocalAudio(enabled);
}

int CAgoraSDKObject::disableAudio()
{
    return irtcEngine->disableAudio();
}

int CAgoraSDKObject::setParameters(const char *options)
{
    AParameter aparameter(irtcEngine);
    return aparameter->setParameters(options);
}

char *CAgoraSDKObject::getParameter(const char *parameter, const char *args)
{
    return 0;
}

std::string CAgoraSDKObject::getCallId()
{
    agora::util::AString sCallId;
    irtcEngine->getCallId(sCallId);
    return sCallId->data();
}

int CAgoraSDKObject::rate(const char *callId, int rating, const char *desc)
{
    return irtcEngine->rate(callId, rating, desc);
}

int CAgoraSDKObject::complain(const char *callId, const char *desc)
{
    return irtcEngine->complain(callId, desc);
}

int CAgoraSDKObject::setEnableSpeakerphone(int enabled)
{
#ifdef WRAPPER_WINDOWS
    return -1;
#else
#ifdef WRAPPER_MAC
    return -1;
#else
    return irtcEngine->setEnableSpeakerphone(enabled);
#endif
#endif
}

int CAgoraSDKObject::isSpeakerphoneEnabled()
{

#ifdef WRAPPER_WINDOWS
    return -1;
#else
#ifdef WRAPPER_MAC
    return -1;
#else
    return irtcEngine->isSpeakerphoneEnabled();
#endif
#endif
}

int CAgoraSDKObject::setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker)
{

#ifdef WRAPPER_WINDOWS
    return -1;
#else
#ifdef WRAPPER_MAC
    return -1;
#else
    return irtcEngine->setDefaultAudioRouteToSpeakerphone(defaultToSpeaker);
#endif
#endif
}

int CAgoraSDKObject::setSpeakerphoneVolume(int volume)
{
    return 0;
}

int CAgoraSDKObject::enableAudioVolumeIndication(int interval, int smooth)
{
    RtcEngineParameters param(*irtcEngine);
    return param.enableAudioVolumeIndication(interval, smooth);
}

int CAgoraSDKObject::startAudioRecording(const char *filePath, int quality)
{
    RtcEngineParameters param(*irtcEngine);
    return param.startAudioRecording(filePath, (AUDIO_RECORDING_QUALITY_TYPE)quality);
}

int CAgoraSDKObject::stopAudioRecording()
{
	return 0;
    //return irtcEngine->stopAudioRecording();
}

int CAgoraSDKObject::startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle)
{
    RtcEngineParameters param(*irtcEngine);
    return param.startAudioMixing(filePath, loopBack, replace, cycle);
}

int CAgoraSDKObject::stopAudioMixing()
{
    RtcEngineParameters param(*irtcEngine);
    return param.stopAudioMixing();
}

int CAgoraSDKObject::pauseAudioMixing()
{
    RtcEngineParameters param(*irtcEngine);
    return param.pauseAudioMixing();
}

int CAgoraSDKObject::resumeAudioMixing()
{
    RtcEngineParameters param(*irtcEngine);
    return param.resumeAudioMixing();
}

int CAgoraSDKObject::adjustAudioMixingVolume(int volume)
{
    RtcEngineParameters param(*irtcEngine);
    return param.adjustAudioMixingVolume(volume);
}

int CAgoraSDKObject::getAudioMixingDuration()
{
    RtcEngineParameters param(*irtcEngine);
    return param.getAudioMixingDuration();
}

int CAgoraSDKObject::getAudioMixingCurrentPosition()
{
    RtcEngineParameters param(*irtcEngine);
    return param.getAudioMixingCurrentPosition();
}

int CAgoraSDKObject::setAudioMixingPosition(int pos)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setAudioMixingPosition(pos);
}

int CAgoraSDKObject::startEchoTest()
{
    return irtcEngine->startEchoTest();
}

int CAgoraSDKObject::stopEchoTest()
{
    return irtcEngine->stopEchoTest();
}

int CAgoraSDKObject::muteLocalAudioStream(bool muted)
{
    RtcEngineParameters param(*irtcEngine);
    return param.muteLocalAudioStream(muted);
}

int CAgoraSDKObject::muteAllRemoteAudioStreams(bool muted)
{
    RtcEngineParameters param(*irtcEngine);
    return param.muteAllRemoteAudioStreams(muted);
}

int CAgoraSDKObject::muteRemoteAudioStream(uid_t uid, bool muted)
{
    RtcEngineParameters param(*irtcEngine);
    return param.muteRemoteAudioStream(uid, muted);
}

int CAgoraSDKObject::switchCamera()
{

#ifdef WRAPPER_WINDOWS
    return -1;
#else
#ifdef WRAPPER_MAC
    return -1;
#else
    return irtcEngine->switchCamera();
#endif
#endif
}

int CAgoraSDKObject::setVideoProfile(int profile, bool swapWidthAndHeight)
{
    return irtcEngine->setVideoProfile((VIDEO_PROFILE_TYPE)profile, swapWidthAndHeight);
}

int CAgoraSDKObject::muteLocalVideoStream(bool muted)
{
    RtcEngineParameters param(*irtcEngine);
    return param.muteLocalVideoStream(muted);
}

int CAgoraSDKObject::muteAllRemoteVideoStreams(bool muted)
{
    RtcEngineParameters param(*irtcEngine);
    return param.muteAllRemoteVideoStreams(muted);
}

int CAgoraSDKObject::muteRemoteVideoStream(uid_t uid, bool muted)
{
    RtcEngineParameters param(*irtcEngine);
    return param.muteRemoteVideoStream(uid, muted);
}

int CAgoraSDKObject::setLogFile(const char *filePath)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setLogFile(filePath);
}

int CAgoraSDKObject::setLogFilter(unsigned int filter)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setLogFilter(filter);
}

int CAgoraSDKObject::setChannelProfile(int profile)
{
    return irtcEngine->setChannelProfile((CHANNEL_PROFILE_TYPE)profile);
}

int CAgoraSDKObject::setClientRole(int role)
{
    return irtcEngine->setClientRole((CLIENT_ROLE_TYPE)role);
}

int CAgoraSDKObject::enableDualStreamMode(bool enabled)
{
    RtcEngineParameters param(*irtcEngine);
    return param.enableDualStreamMode(enabled);
}

int CAgoraSDKObject::setEncryptionMode(const char *encryptionMode)
{
    return irtcEngine->setEncryptionMode(encryptionMode);
}

int CAgoraSDKObject::setEncryptionSecret(const char *secret)
{
    return irtcEngine->setEncryptionSecret(secret);
}

int CAgoraSDKObject::setRemoteVideoStreamType(uid_t uid, int streamType)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setRemoteVideoStreamType(uid, (REMOTE_VIDEO_STREAM_TYPE)streamType);
}

int CAgoraSDKObject::startRecordingService(const char *recordingKey)
{
    // RtcEngineParameters rtcEngineParameters(irtcEngine);
    // return rtcEngineParameters.startRecordingService(recordingKey);
    return 0;
}

int CAgoraSDKObject::stopRecordingService(const char *recordingKey)
{
    // RtcEngineParameters rtcEngineParameters(irtcEngine);
    // return rtcEngineParameters.stopRecordingService(recordingKey);
    return 0;
}

int CAgoraSDKObject::refreshRecordingServiceStatus()
{
    // RtcEngineParameters rtcEngineParameters(irtcEngine);
    // return rtcEngineParameters.refreshRecordingServiceStatus();
    return 0;
}

int CAgoraSDKObject::createDataStream(int *streamId, bool reliable, bool ordered)
{
    return irtcEngine->createDataStream(streamId, reliable, ordered);
}

int CAgoraSDKObject::sendStreamMessage(int streamId, const char *data, size_t length)
{
    return irtcEngine->sendStreamMessage(streamId, data, length);
}

int CAgoraSDKObject::setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setRecordingAudioFrameParameters(sampleRate, channel, (RAW_AUDIO_FRAME_OP_MODE_TYPE)mode, samplesPerCall);
}

int CAgoraSDKObject::setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setPlaybackAudioFrameParameters(sampleRate, channel, (RAW_AUDIO_FRAME_OP_MODE_TYPE)mode, samplesPerCall);
}

int CAgoraSDKObject::setMixedAudioFrameParameters(int sampleRate, int samplesPerCall)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setMixedAudioFrameParameters(sampleRate, samplesPerCall);
}

int CAgoraSDKObject::adjustRecordingSignalVolume(int volume)
{
    RtcEngineParameters param(*irtcEngine);
    return param.adjustRecordingSignalVolume(volume);
}

int CAgoraSDKObject::adjustPlaybackSignalVolume(int volume)
{
    RtcEngineParameters param(*irtcEngine);
    return param.adjustPlaybackSignalVolume(volume);
}

int CAgoraSDKObject::setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate)
{
    //return irtcEngine->setHighQualityAudioParameters(fullband, stereo, fullBitrate);
    RtcEngineParameters rtcEngineParameters(irtcEngine);
    return rtcEngineParameters.setHighQualityAudioParameters(fullband, stereo, fullBitrate);
}

int CAgoraSDKObject::enableInEarMonitoring(bool enabled)
{
    //return irtcEngine->enableInEarMonitoring(enabled);
    return 0;
}

int CAgoraSDKObject::enableWebSdkInteroperability(bool enabled)
{
    RtcEngineParameters param(*irtcEngine);
    return param.enableWebSdkInteroperability(enabled);
}

int CAgoraSDKObject::setVideoQualityParameters(bool preferFrameRateOverImageQuality)
{
    //return irtcEngine->setVideoQualityParameters(preferFrameRateOverImageQuality);
    RtcEngineParameters rtcEngineParameters(irtcEngine);
    return rtcEngineParameters.setVideoQualityParameters(preferFrameRateOverImageQuality);
}

int CAgoraSDKObject::setPlaybackDeviceVolume(int volume)
{
    //return irtcEngine->setPlaybackDeviceVolume(volume);
     RtcEngineParameters rtcEngineParameters(irtcEngine);
    return rtcEngineParameters.setPlaybackDeviceVolume(volume);
}

int CAgoraSDKObject::getEffectsVolume()
{
    RtcEngineParameters param(*irtcEngine);
    return param.getEffectsVolume();
}

int CAgoraSDKObject::setEffectsVolume(int volume)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setEffectsVolume(volume);
}

int CAgoraSDKObject::playEffect(int soundId, const char *filePath, int loopCount, double pitch, double pan, int gain, bool publish)
{
    RtcEngineParameters param(*irtcEngine);
    return param.playEffect(soundId, filePath, loopCount, pitch, pan, gain, publish);
}

int CAgoraSDKObject::stopEffect(int soundId)
{
    RtcEngineParameters param(*irtcEngine);
    return param.stopEffect(soundId);
}

int CAgoraSDKObject::stopAllEffects()
{
    RtcEngineParameters param(*irtcEngine);
    return param.stopAllEffects();
}

int CAgoraSDKObject::preloadEffect(int soundId, const char *filePath)
{
    RtcEngineParameters param(*irtcEngine);
    return param.preloadEffect(soundId, (char*)filePath);
}

int CAgoraSDKObject::unloadEffect(int soundId)
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
    return rtcEngineParameters.unloadEffect(soundId);
}

int CAgoraSDKObject::pauseEffect(int soundId)
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.pauseEffect(soundId);
}

int CAgoraSDKObject::pauseAllEffects()
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.pauseAllEffects();
}

int CAgoraSDKObject::resumeEffect(int soundId)
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.resumeEffect(soundId);
}

int CAgoraSDKObject::resumeAllEffects()
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.resumeAllEffects();
}

int CAgoraSDKObject::setLocalVoicePitch(double pitch)
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.setLocalVoicePitch(pitch);
}

int CAgoraSDKObject::setRemoteVoicePosition(uid_t uid, double pan, double gain)
{
    return -1;
	// return irtcEngine->setRemoteVoicePosition(uid, pan, gain);
}

int CAgoraSDKObject::setVoiceOnlyMode(bool enabled)
{
    //return irtcEngine->setVoiceOnlyMode(enabled);
    return 0;
}

int CAgoraSDKObject::setDefaultMuteAllRemoteAudioStreams(bool mute)
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.setDefaultMuteAllRemoteAudioStreams(mute);
}

int CAgoraSDKObject::setDefaultMuteAllRemoteVideoStreams(bool mute)
{
	RtcEngineParameters rtcEngineParameters(irtcEngine);
	return rtcEngineParameters.setDefaultMuteAllRemoteVideoStreams(mute);
}

int CAgoraSDKObject::setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor,unsigned int userCount, unsigned int transcodingUserUid, int transcodingUsersX, int transcodingUsersY, int transcodingUsersWidth, int transcodingUsersHeight, int transcodingUsersZorder,double transcodingUsersAlpha, int transcodingUsersAudioChannel, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX,int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY,int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile)
{
    if (irtcEngine)
    {
        LiveTranscoding liveTranscoding;
        liveTranscoding.width = width;
        liveTranscoding.height = height;
        liveTranscoding.videoBitrate = videoBitrate;
        liveTranscoding.videoFramerate = videoFramerate;
        liveTranscoding.lowLatency = lowLatency;
        liveTranscoding.videoGop = videoGroup;
        liveTranscoding.videoCodecProfile = (VIDEO_CODEC_PROFILE_TYPE)video_codec_profile;
        liveTranscoding.backgroundColor = backgroundColor;
        liveTranscoding.userCount = userCount;
        TranscodingUser transcodingUser;
        transcodingUser.uid = transcodingUserUid;
        transcodingUser.x = transcodingUsersX;
        transcodingUser.y = transcodingUsersY;
        transcodingUser.width = transcodingUsersWidth;
        transcodingUser.height = transcodingUsersHeight;
        transcodingUser.zOrder = transcodingUsersZorder;
        transcodingUser.alpha = transcodingUsersAlpha;
        transcodingUser.audioChannel = transcodingUsersAudioChannel;
        liveTranscoding.transcodingUsers = &transcodingUser;
        liveTranscoding.transcodingExtraInfo = transcodingExtraInfo;
        liveTranscoding.metadata = metaData;
        RtcImage watermark;
        watermark.url = watermarkRtcImageUrl;
        watermark.x = watermarkRtcImageX;
        watermark.y = watermarkRtcImageY;
        watermark.width = watermarkRtcImageWidth;
        watermark.height = watermarkRtcImageHeight;
        liveTranscoding.watermark = &watermark;
        RtcImage backgroundImage;
        backgroundImage.url = backgroundImageRtcImageUrl;
        backgroundImage.x = backgroundImageRtcImageX;
        backgroundImage.y = backgroundImageRtcImageY;
        backgroundImage.width = backgroundImageRtcImageWidth;
        backgroundImage.height = backgroundImageRtcImageHeight;
        liveTranscoding.backgroundImage = &backgroundImage;
        liveTranscoding.audioSampleRate = (AUDIO_SAMPLE_RATE_TYPE)audioSampleRate;
        liveTranscoding.audioBitrate = audioBitrate;
        liveTranscoding.audioChannels = audioChannels;
        return irtcEngine->setLiveTranscoding(liveTranscoding);
    }
    else
    {
        return -1;
    }
}

int CAgoraSDKObject::addPublishStreamUrl(const char *url, bool transcodingEnabled)
{
    return irtcEngine->addPublishStreamUrl(url, transcodingEnabled);
}

int CAgoraSDKObject::removePublishStreamUrl(const char *url)
{
    return irtcEngine->removePublishStreamUrl(url);
}

int CAgoraSDKObject::configPublisher(int width, int height, int framerate, int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char* injectStreamUrl, const char* publishUrl, const char* rawStreamUrl, const char* extraInfo)
{
    PublisherConfiguration publishConfig;
    publishConfig.width = width;
    publishConfig.height = height;
    publishConfig.framerate = framerate;
    publishConfig.bitrate = bitrate;
    publishConfig.defaultLayout = defaultLayout;
    publishConfig.lifecycle = lifecycle;
    publishConfig.owner = owner;
    publishConfig.injectStreamWidth = injectStreamWidth;
    publishConfig.injectStreamHeight = injectStreamHeight;
    publishConfig.injectStreamUrl = injectStreamUrl;
    publishConfig.publishUrl = publishUrl;
    publishConfig.rawStreamUrl = rawStreamUrl;
    publishConfig.extraInfo = extraInfo;
    return irtcEngine->configPublisher(publishConfig);
}

int CAgoraSDKObject::setVideoCompositingLayout(int canvasWidth, int canvasHeight, const char* backgroundColor, uid_t regionUid, double regionX, double regionY, double regionWidth, double regionHeight, int regionZOrder, double regionAlpha, int regionRenderMode, int regionCount, const char* appData, int appDataLength)
{
    VideoCompositingLayout videoCompositingLayout;
    videoCompositingLayout.canvasWidth = canvasWidth;
    videoCompositingLayout.canvasHeight = canvasHeight;
    videoCompositingLayout.backgroundColor = backgroundColor;
    videoCompositingLayout.regionCount = regionCount;
    videoCompositingLayout.appData = appData;
    videoCompositingLayout.appDataLength = appDataLength;

    VideoCompositingLayout::Region region;
    region.uid =regionUid;
    region.x = regionX;
    region.y = regionY;
    region.width = regionWidth;
    region.height = regionHeight;
    region.zOrder = regionZOrder;
    region.alpha = regionAlpha;
    region.renderMode = (RENDER_MODE_TYPE)regionRenderMode;

    videoCompositingLayout.regions = &region;

    return irtcEngine->setVideoCompositingLayout(videoCompositingLayout);
}

int CAgoraSDKObject::clearVideoCompositingLayout()
{
    return irtcEngine->clearVideoCompositingLayout();
}

int CAgoraSDKObject::addVideoWatermark(const char* url, int x, int y, int width, int height)
{
    RtcImage rtcImage;
    rtcImage.url = url;
    rtcImage.x = x;
    rtcImage.y = y;
    rtcImage.width = width;
    rtcImage.height = height;
    return irtcEngine->addVideoWatermark(rtcImage);
}

int CAgoraSDKObject::clearVideoWatermarks()
{
    return irtcEngine->clearVideoWatermarks();
}

int CAgoraSDKObject::setBeautyEffectOptions(bool enabled, int beatyOptionsLighteningContrastLevel, float beatyOptionsLighteningLevel, float beatyOptionsSmoothnessLevel, float beatyOptionsRednessLevel)
{
    /*BeautyOptions beautyOptions;
    beautyOptions.lighteningContrastLevel = (agora::rtc::BeautyOptions::LIGHTENING_CONTRAST_LEVEL)beatyOptionsLighteningContrastLevel;
    beautyOptions.lighteningLevel = beatyOptionsLighteningLevel;
    beautyOptions.smoothnessLevel = beatyOptionsSmoothnessLevel;
    beautyOptions.rednessLevel = beatyOptionsRednessLevel;

    return irtcEngine->setBeautyEffectOptions(enabled, beautyOptions);*/
    return -1;
}

int CAgoraSDKObject::addInjectStreamUrl(const char* url, int injectStreamWidth, int injectStreamHeight, int injectStreamVideoGop, int injectStreamVideoFramerate, int injectStreamVideoBitrate, int injectStreamAudioSampleRate, int injectStreamAudioBitrate, int injectStreamAudioChannels)
{
    InjectStreamConfig injectStreamConfig;
    injectStreamConfig.width = injectStreamWidth;
    injectStreamConfig.height = injectStreamHeight;
    injectStreamConfig.videoGop = injectStreamVideoGop;
    injectStreamConfig.videoFramerate = injectStreamVideoFramerate;
    injectStreamConfig.videoBitrate = injectStreamVideoBitrate;
    injectStreamConfig.audioSampleRate = (AUDIO_SAMPLE_RATE_TYPE)injectStreamAudioSampleRate;
    injectStreamConfig.audioBitrate = injectStreamAudioBitrate;
    injectStreamConfig.audioChannels = injectStreamAudioChannels;
    return irtcEngine->addInjectStreamUrl(url, injectStreamConfig);
}

int CAgoraSDKObject::removeInjectStreamUrl(const char* url)
{
    return irtcEngine->removeInjectStreamUrl(url);
}

int CAgoraSDKObject::pushExternVideoFrame(int type, int format, void* buffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, long timestamp)
{
        agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
        mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
        if (mediaEngine)
        {
            ExternalVideoFrame externalVideoFrame;
            externalVideoFrame.type = ExternalVideoFrame::VIDEO_BUFFER_TYPE::VIDEO_BUFFER_RAW_DATA;
            externalVideoFrame.format = ExternalVideoFrame::VIDEO_PIXEL_FORMAT::VIDEO_PIXEL_BGRA;
            externalVideoFrame.buffer = buffer;
            externalVideoFrame.stride = stride;
            externalVideoFrame.height = height;
            externalVideoFrame.cropLeft = cropLeft;
            externalVideoFrame.cropTop = cropTop;
            externalVideoFrame.cropRight = cropRight;
            externalVideoFrame.cropBottom = cropBottom;
            externalVideoFrame.rotation = rotation;
            externalVideoFrame.timestamp = timestamp;
            mediaEngine->pushVideoFrame(&externalVideoFrame);
            return 0;
        }
        else
        {
            return -1;
        }
}

int CAgoraSDKObject::setExternalVideoSource(bool enable, bool useTexture)
{
        agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
        mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
        if (mediaEngine)
        {
            
            mediaEngine->setExternalVideoSource(enable, useTexture);
            return 0;
        }
        else
        {
            return -1;
        }
}


int CAgoraSDKObject::startScreenCapture(int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate, const char* GameName)
{
    Rect rc(rc_left, rc_top, rc_width, rc_height);
    return irtcEngine->startScreenCapture(captureFreq, &rc, bitrate, GameName);
}


int CAgoraSDKObject::stopScreenCapture()
{
    return irtcEngine->stopScreenCapture();
}

int CAgoraSDKObject::startScreenCaptureEx(HWND windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate)
{
    Rect rc(rc_left, rc_top, rc_width, rc_height);
    return irtcEngine->startScreenCaptureEx(windowId, captureFreq, &rc, bitrate);
}


int CAgoraSDKObject::stopScreenCaptureEx()
{
    return irtcEngine->stopScreenCaptureEx();
}

class  RawVideoFrameBufMgr
{
public:
    class RawVideoFrameBuf {
    public:
        RawVideoFrameBuf()
            : bufSize_(0)
            , buf_(NULL) {

        }

        ~RawVideoFrameBuf() {
            if (buf_)
                delete[] buf_;
        }

        BYTE* GetBuf(int size) {
            if (size > bufSize_) {
                if (buf_)
                    delete[] buf_;
                buf_ = new BYTE[size];
                bufSize_ = size;
            }
            return buf_;
        }
    private:
        int bufSize_;
        BYTE* buf_;
    };
public:
    RawVideoFrameBufMgr() {

     }
    ~RawVideoFrameBufMgr() {

    }

    BYTE* GetBuf(int size) {
        DWORD tid = GetCurrentThreadId();
        std::lock_guard<std::mutex> lock(mtx_);
        std::shared_ptr<RawVideoFrameBuf> spBuf;
        auto it = mapThreadId2Buf_.find(tid);
        if (it == mapThreadId2Buf_.end()) {
            spBuf.reset(new RawVideoFrameBuf());
            mapThreadId2Buf_[tid] = spBuf;
        }
        else {
            spBuf = it->second;
        }
        return spBuf->GetBuf(size);
    }

private:
    std::map<DWORD, std::shared_ptr<RawVideoFrameBuf>> mapThreadId2Buf_;
    std::mutex mtx_;
};
static RawVideoFrameBufMgr rawVideoFrameBufMgr_;

bool CAgoraSDKObject::onCaptureVideoFrame(VideoFrame& videoFrame)
{
    if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_YUV420
        || !videoFrame.yBuffer
        || !videoFrame.uBuffer
        || !videoFrame.vBuffer
        || videoFrame.width <= 0
        || videoFrame.height <= 0)
    {
        return false;
    }

    int size = videoFrame.width * videoFrame.height;
    int u_size = size / 4;
    size += size / 2;
    BYTE* YUVbuf = rawVideoFrameBufMgr_.GetBuf(size);
    if (!YUVbuf)
        return false;
    BYTE* start_src = (BYTE*)videoFrame.yBuffer;
    BYTE* start_targ = YUVbuf;
    for (int i = 0; i < videoFrame.height; i++)
    {
        memcpy(start_targ, start_src, videoFrame.width);
        start_src += videoFrame.yStride;
        start_targ += videoFrame.width;
    }
    memcpy(start_targ, videoFrame.uBuffer, u_size);
    start_targ += u_size;

    memcpy(start_targ, videoFrame.vBuffer, u_size);
    start_targ += u_size;

    if (cWrapperRtcEngineEventHandler)
        cWrapperRtcEngineEventHandler->onCaptureVideoFrameRaw(
            videoFrame.width, videoFrame.height,
            (const unsigned char*)YUVbuf/*videoFrame.yBuffer*/, videoFrame.rotation);
    return true;
}


bool CAgoraSDKObject::onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame)
{
    if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_YUV420
        || !videoFrame.yBuffer
        || !videoFrame.uBuffer
        || !videoFrame.vBuffer
        || videoFrame.width <= 0
        || videoFrame.height <= 0)
    {
        return false;
    }

    int size = videoFrame.width * videoFrame.height;
    int u_size = size / 4;
    size += size / 2;
    BYTE* YUVbuf = rawVideoFrameBufMgr_.GetBuf(size);
    if (!YUVbuf)
        return false;
    BYTE* start_src = (BYTE*)videoFrame.yBuffer;
    BYTE* start_targ = YUVbuf;
    for (int i = 0; i < videoFrame.height; i++)
    {
        memcpy(start_targ, start_src, videoFrame.width);
        start_src += videoFrame.yStride;
        start_targ += videoFrame.width;
    }
    memcpy(start_targ, videoFrame.uBuffer, u_size);
    start_targ += u_size;

    memcpy(start_targ, videoFrame.vBuffer, u_size);
    start_targ += u_size;

    if (cWrapperRtcEngineEventHandler)
        cWrapperRtcEngineEventHandler->onRenderVideoFrameRaw(uid,
            videoFrame.width, videoFrame.height,
            (const unsigned char*)YUVbuf/*videoFrame.yBuffer*/, videoFrame.rotation);
    return true;
}

int CAgoraSDKObject::enableVideoObserver()
{
    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
    mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
    if (mediaEngine)
    {
        mediaEngine->registerVideoFrameObserver(&videoFrameObserver);
        return 0;
    }
    else
    {
        return -1;
    }
}

int CAgoraSDKObject::disableVideoObserver()
{
    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
    mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
    if (mediaEngine)
    {
        mediaEngine->registerVideoFrameObserver(NULL);
    }
    videoFrameObserver.reset();
    return 0;
}

int CAgoraSDKObject::generateNativeTexture()
{
    int texId = videoFrameObserver.createTexture();
    return texId;
}

int CAgoraSDKObject::updateTexture(int texId, unsigned char *data, unsigned int uid)
{
    return videoFrameObserver.updateTexture(texId, data, uid);
}

void CAgoraSDKObject::deleteTexture(int tex)
{
    videoFrameObserver.deleteTexture(tex);
}

int CAgoraSDKObject::setExternalAudioSource(bool enabled, int sampleRate, int channels)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setExternalAudioSource(enabled, sampleRate, channels);
}

int CAgoraSDKObject::setExternalAudioSink(bool enabled, int sampleRate, int channels)
{
    RtcEngineParameters param(*irtcEngine);
    return param.setExternalAudioSink(enabled, sampleRate, channels);
}

int CAgoraSDKObject::pushAudioFrame(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type)
{
        agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
        mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
        if (mediaEngine)
        {
            IAudioFrameObserver::AudioFrame audioFrame;
            audioFrame.type = (IAudioFrameObserver::AUDIO_FRAME_TYPE)type;
            audioFrame.samples = samples;
            audioFrame.bytesPerSample = bytesPerSample;
            audioFrame.channels = channels;
            audioFrame.samplesPerSec = samplesPerSec;
            audioFrame.buffer = buffer;
            audioFrame.renderTimeMs = renderTimeMs;
            audioFrame.avsync_type = avsync_type;
            mediaEngine->pushAudioFrame(&audioFrame);
            return 0;
        }
        else
        {
            return -1;
        }
}

int CAgoraSDKObject::enableSoundPositionIndication(bool enabled)
{
	// return irtcEngine->enableSoundPositionIndication(enabled);
    return -1;
}

int CAgoraSDKObject::setupLocalVideo(int view, int renderMode, uid_t uid, void* priv)
{
	VideoCanvas videoCanvas;
	videoCanvas.priv = priv;
	videoCanvas.view = reinterpret_cast<void*>(view);
	videoCanvas.uid = uid;
	videoCanvas.renderMode = renderMode;
	return irtcEngine->setupLocalVideo(videoCanvas);
}

int CAgoraSDKObject::setupRemoteVideo(int view, int renderMode, uid_t uid, void* priv)
{
	VideoCanvas videoCanvas;
	videoCanvas.priv = priv;
	videoCanvas.view = reinterpret_cast<void*>(view);;
	videoCanvas.uid = uid;
	videoCanvas.renderMode = renderMode;
	return irtcEngine->setupRemoteVideo(videoCanvas);
}