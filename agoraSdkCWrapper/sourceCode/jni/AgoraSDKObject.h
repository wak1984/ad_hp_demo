#ifndef AGORA_WRAPPER_SDK_Object
#define AGORA_WRAPPER_SDK_Object
#include "CWrapperRtcEngineEventHandler.h"
#include "AgoraWrapperVideoFrameObserver.h"

class CAgoraSDKObject : public agora::media::IVideoFrameObserver
{
private:
  CAgoraSDKObject();
  static CAgoraSDKObject *cAgoraSDKObjectInstance;
  IRtcEngine *irtcEngine = nullptr;
  CWrapperRtcEngineEventHandler *cWrapperRtcEngineEventHandler = nullptr;
  const char *TAG = "AgoraSDKObject";
  AgoraWrapperVideoFrameObserver videoFrameObserver;

public:
  ~CAgoraSDKObject();
  static CAgoraSDKObject *getCAgoraSDKInstance();
  static void releaseCAgoraSDKInstance();
  CWrapperRtcEngineEventHandler *getCWrapperRtcEngineEventHandler();
  IRtcEngine *getCWrapperIRtcEngine();
  virtual bool createEngine(const char *appId);
  virtual void deleteEngine();
  virtual const char *getSdkVersion();
  virtual const char *getMediaEngineVersion();
  virtual int joinChannel(const char *channelKey, const char *channelName, const char *info, uid_t uid);
  virtual int renewToken(const char *token);
  virtual int leaveChannel();
  virtual int enableLastmileTest();
  virtual int disableLastmileTest();
  virtual int enableVideo();
  virtual int disableVideo();
  virtual int enableLocalVideo(bool enabled);
  virtual int startPreview();
  virtual int stopPreview();
  virtual int enableAudio();
  virtual int enableLocalAudio(bool enabled);
  virtual int disableAudio();
  virtual int setParameters(const char *options);
  virtual char *getParameter(const char *parameter, const char *args);
  virtual std::string getCallId();
  virtual int rate(const char *callId, int rating, const char *desc);
  virtual int complain(const char *callId, const char *desc);
  virtual int setEnableSpeakerphone(int enabled);
  virtual int isSpeakerphoneEnabled();
  virtual int setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker);
  virtual int setSpeakerphoneVolume(int volume);
  virtual int enableAudioVolumeIndication(int interval, int smooth);
  virtual int startAudioRecording(const char *filePath, int quality);
  virtual int stopAudioRecording();
  virtual int startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle);
  virtual int stopAudioMixing();
  virtual int pauseAudioMixing();
  virtual int resumeAudioMixing();
  virtual int adjustAudioMixingVolume(int volume);
  virtual int getAudioMixingDuration();
  virtual int getAudioMixingCurrentPosition();
  virtual int setAudioMixingPosition(int pos);
  virtual int startEchoTest();
  virtual int stopEchoTest();
  virtual int muteLocalAudioStream(bool muted);
  virtual int muteAllRemoteAudioStreams(bool muted);
  virtual int muteRemoteAudioStream(uid_t uid, bool muted);
  virtual int switchCamera();
  virtual int setVideoProfile(int profile, bool swapWidthAndHeight);
  virtual int muteLocalVideoStream(bool muted);
  virtual int muteAllRemoteVideoStreams(bool muted);
  virtual int muteRemoteVideoStream(uid_t uid, bool muted);
  virtual int setLogFile(const char *filePath);
  virtual int setLogFilter(unsigned int filter);
  virtual int setChannelProfile(int profile);
  virtual int setClientRole(int role);
  virtual int enableDualStreamMode(bool enabled);
  virtual int setEncryptionMode(const char *encryptionMode);
  virtual int setEncryptionSecret(const char *secret);
  virtual int setRemoteVideoStreamType(uid_t uid, int streamType);
  virtual int startRecordingService(const char *recordingKey);
  virtual int stopRecordingService(const char *recordingKey);
  virtual int refreshRecordingServiceStatus();
  virtual int createDataStream(int *streamId, bool reliable, bool ordered);
  virtual int sendStreamMessage(int streamId, const char *data, size_t length);
  virtual int setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
  virtual int setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
  virtual int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);
  virtual int adjustRecordingSignalVolume(int volume);
  virtual int adjustPlaybackSignalVolume(int volume);
  virtual int setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate);
  virtual int enableInEarMonitoring(bool enabled);
  virtual int enableWebSdkInteroperability(bool enabled);
  virtual int setVideoQualityParameters(bool preferFrameRateOverImageQuality);
  virtual int setLocalVoicePitch(double pitch);
  virtual int setRemoteVoicePosition(uid_t uid, double pan, double gain);
  virtual int setVoiceOnlyMode(bool enabled);
  virtual int setPlaybackDeviceVolume(int volume);
  virtual int getEffectsVolume();
  virtual int setEffectsVolume(int volume);
  virtual int playEffect(int soundId, const char *filePath, int loopCount, double pitch, double pan, int gain, bool publish = false);
  virtual int stopEffect(int soundId);
  virtual int stopAllEffects();
  virtual int preloadEffect(int soundId, const char *filePath);
  virtual int unloadEffect(int soundId);
  virtual int pauseEffect(int soundId);
  virtual int pauseAllEffects();
  virtual int resumeEffect(int soundId);
  virtual int resumeAllEffects();
  virtual int setDefaultMuteAllRemoteAudioStreams(bool mute);
  virtual int setDefaultMuteAllRemoteVideoStreams(bool mute);
  virtual int setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, unsigned int transcodingUserUid, int transcodingUsersX, int transcodingUsersY, int transcodingUsersWidth, int transcodingUsersHeight, int transcodingUsersZorder, double transcodingUsersAlpha, int transcodingUsersAudioChannel, const char *transcodingExtraInfo, const char * metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile);
  virtual int addPublishStreamUrl(const char *url, bool transcodingEnabled);
  virtual int removePublishStreamUrl(const char *url);
  virtual int configPublisher(int width, int height, int framerate, int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char* injectStreamUrl, const char* publishUrl, const char* rawStreamUrl, const char* extraInfo);
  virtual int setVideoCompositingLayout(int canvasWidth, int canvasHeight, const char* backgroundColor, uid_t regionUid, double regionX, double regionY, double regionWidth, double regionHeight, int regionZOrder, double regionAlpha, int regionRenderMode, int regionCount, const char* appData, int appDataLength);
  virtual int clearVideoCompositingLayout();
  virtual int addVideoWatermark(const char* url, int x, int y, int width, int height);
  virtual int clearVideoWatermarks();
  virtual int setBeautyEffectOptions(bool enabled, int beatyOptionsLighteningContrastLevel, float beatyOptionsLighteningLevel, float beatyOptionsSmoothnessLevel, float beatyOptionsRednessLevel);
  virtual int addInjectStreamUrl(const char* url, int injectStreamWidth, int injectStreamHeight, int injectStreamVideoGop, int injectStreamVideoFramerate, int injectStreamVideoBitrate, int injectStreamAudioSampleRate, int injectStreamAudioBitrate, int injectStreamAudioChannels);
  virtual int removeInjectStreamUrl(const char* url);
  virtual int setExternalAudioSource(bool enabled, int sampleRate, int channels);
  virtual int setExternalAudioSink(bool enabled, int sampleRate, int channels);
  virtual int pushAudioFrame(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
  virtual int enableSoundPositionIndication(bool enabled);
  virtual int setupLocalVideo(int view, int renderMode, uid_t uid, void* priv);
  virtual int setupRemoteVideo(int view, int renderMode, uid_t uid, void* priv);

  //video api
  virtual int enableVideoObserver();
  virtual int disableVideoObserver();
  virtual int generateNativeTexture();
  virtual int updateTexture(int texId, unsigned char *data, unsigned int uid);
  virtual void deleteTexture(int tex);
  virtual int pushExternVideoFrame(int type, int format, void* buffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, long timestamp);
  virtual int setExternalVideoSource(bool enable, bool useTexture);

  virtual int startScreenCapture(int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate, DWORD processID);
  virtual int stopScreenCapture();

  virtual int startScreenCaptureEx(HWND windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate);
  virtual int stopScreenCaptureEx();

  /// IVideoFrameObserver
  bool onCaptureVideoFrame(VideoFrame& videoFrame);
  bool onRenderVideoFrame(unsigned int uid, VideoFrame& videoFrame);
};
#endif