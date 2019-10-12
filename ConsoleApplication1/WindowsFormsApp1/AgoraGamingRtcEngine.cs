using System;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Collections;
using System.Collections.Generic;
using agora_gaming_rtc;
/* class IRtcEngine provides c# API for Unity 3D
 * app. Use IRtcEngine to access underlying Agora
 * sdk.
 * 
 * Agora sdk only supports single instance by now. So here
 * provides GetEngine() and Destroy() to create/delete the
 * only instance.
 */

namespace agora_gaming_rtc
{

    public class IRtcEngine : IRtcEngineBase
    {
        #region set callback here for user
        public delegate void JoinChannelSuccessHandler(string channelName, uint uid, int elapsed);
        public JoinChannelSuccessHandler OnJoinChannelSuccess;

        public delegate void ReJoinChannelSuccessHandler(string channelName, uint uid, int elapsed);
        public ReJoinChannelSuccessHandler OnReJoinChannelSuccess;

        public delegate void ConnectionLostHandler();
        public ConnectionLostHandler OnConnectionLost;

        public delegate void ConnectionInterruptedHandler();
        public ConnectionInterruptedHandler OnConnectionInterrupted;

        public delegate void RequestTokenHandler();
        public RequestTokenHandler OnRequestToken;

        public delegate void UserJoinedHandler(uint uid, int elapsed);
        public UserJoinedHandler OnUserJoined;

        public delegate void UserOfflineHandler(uint uid, USER_OFFLINE_REASON reason);
        public UserOfflineHandler OnUserOffline;

        public delegate void LeaveChannelHandler(RtcStats stats);
        public LeaveChannelHandler OnLeaveChannel;

        public delegate void VolumeIndicationHandler(AudioVolumeInfo[] speakers, int speakerNumber, int totalVolume);
        public VolumeIndicationHandler OnVolumeIndication;

        public delegate void UserMutedHandler(uint uid, bool muted);
        public UserMutedHandler OnUserMuted;

        public delegate void SDKWarningHandler(int warn, string msg);
        public SDKWarningHandler OnWarning;

        public delegate void SDKErrorHandler(int error, string msg);
        public SDKErrorHandler OnError;

        public delegate void RtcStatsHandler(RtcStats stats);
        public RtcStatsHandler OnRtcStats;

        public delegate void AudioMixingFinishedHandler();
        public AudioMixingFinishedHandler OnAudioMixingFinished;

        public delegate void AudioRouteChangedHandler(AUDIO_ROUTE route);
        public AudioRouteChangedHandler OnAudioRouteChanged;

        public delegate void OnFirstRemoteVideoDecodedHandler(uint uid, int width, int height, int elapsed);
        public OnFirstRemoteVideoDecodedHandler OnFirstRemoteVideoDecoded;

        public delegate void OnVideoSizeChangedHandler(uint uid, int width, int height, int elapsed);
        public OnVideoSizeChangedHandler OnVideoSizeChanged;

        public delegate void OnClientRoleChangedHandler(int oldRole, int newRole);
        public OnClientRoleChangedHandler OnClientRoleChanged;

        public delegate void OnUserMuteVideoHandler(uint uid, bool muted);
        public OnUserMuteVideoHandler OnUserMuteVideo;

        public delegate void OnMicrophoneEnabledHandler(bool isEnabled);
        public OnMicrophoneEnabledHandler OnMicrophoneEnabled;

        public delegate void OnFirstRemoteAudioFrameHandler(uint userId, int elapsed);
        public OnFirstRemoteAudioFrameHandler OnFirstRemoteAudioFrame;

        public delegate void OnFirstLocalAudioFrameHandler(int elapsed);
        public OnFirstLocalAudioFrameHandler OnFirstLocalAudioFrame;

        public delegate void OnApiExecutedHandler(int err, string api, string result);
        public OnApiExecutedHandler OnApiExecuted;

        public delegate void OnLastmileQualityHandler(int quality);
        public OnLastmileQualityHandler OnLastmileQuality;

        public delegate void OnAudioQualityHandler(uint userId, int quality, ushort delay, ushort lost);
        public OnAudioQualityHandler OnAudioQuality;

        public delegate void OnStreamInjectedStatusHandler(string url, uint userId, int status);
        public OnStreamInjectedStatusHandler OnStreamInjectedStatus;

        public delegate void OnStreamUnpublishedHandler(string url);
        public OnStreamUnpublishedHandler OnStreamUnpublished;

        public delegate void OnStreamPublishedHandler(string url, int error);
        public OnStreamPublishedHandler OnStreamPublished;

        public delegate void OnStreamMessageErrorHandler(uint userId, int streamId, int code, int missed, int cached);
        public OnStreamMessageErrorHandler OnStreamMessageError;

        public delegate void OnStreamMessageHandler(uint userId, int streamId, string data, int length);
        public OnStreamMessageHandler OnStreamMessage;

        public delegate void OnConnectionBannedHandler();
        public OnConnectionBannedHandler OnConnectionBanned;

        public delegate void OnNetworkQualityHandler(uint uid, int txQuality, int rxQuality);
        public OnNetworkQualityHandler OnNetworkQuality;

        public delegate void OnCaptureVideoFrameRawHandler(int width, int height, byte[] yBuffer, int rotation);
        public OnCaptureVideoFrameRawHandler onCaptureVideoFrameRaw;

        public delegate void OnRenderVideoFrameRawHandler(uint userId, int width, int height, byte[] yBuffer, int rotation);
        public OnRenderVideoFrameRawHandler onRenderVideoFrameRaw;
        #endregion  set callback here for user

        // private readonly AudioEffectManagerImpl mAudioEffectM;


        private static void OnJoinChannelSuccessCallBack(string channel, uint uid, int elapsed)
        {
            if (instance != null && instance.OnJoinChannelSuccess != null)
            {
                instance.OnJoinChannelSuccess(channel, uid, elapsed);
            }
        }


        private static void OnLeaveChannelCallBack(uint duration, uint txBytes, uint rxBytes,
                                    ushort txKBitRate, ushort rxKBitRate, ushort rxAudioKBitRate,
                                    ushort txAudioKBitRate, ushort rxVideoKBitRate,
                                    ushort txVideoKBitRate, ushort lastmileQuality, uint userCount, double cpuAppUsage,
                                    double cpuTotalUsage)
        {
            if (instance != null && instance.OnLeaveChannel != null)
            {
                RtcStats rtcStats = new RtcStats();
                rtcStats.duration = duration;
                rtcStats.txBytes = txBytes;
                rtcStats.rxBytes = rxBytes;
                rtcStats.txKBitRate = txKBitRate;
                rtcStats.rxKBitRate = rxKBitRate;
                rtcStats.rxAudioKBitRate = rxAudioKBitRate;
                rtcStats.txAudioKBitRate = txAudioKBitRate;
                rtcStats.rxVideoKBitRate = rxVideoKBitRate;
                rtcStats.txVideoKBitRate = txVideoKBitRate;
                rtcStats.lastmileQuality = lastmileQuality;
                rtcStats.users = userCount;
                rtcStats.cpuAppUsage = cpuAppUsage;
                rtcStats.cpuTotalUsage = cpuTotalUsage;
                instance.OnLeaveChannel(rtcStats);
            }
        }


        private static void OnReJoinChannelSuccessCallBack(string channelName, uint uid, int elapsed)
        {
            if (instance != null && instance.OnReJoinChannelSuccess != null)
                instance.OnReJoinChannelSuccess(channelName, uid, elapsed);
        }


        private static void OnConnectionLostCallBack()
        {
            if (instance != null && instance.OnConnectionLost != null)
                instance.OnConnectionLost();
        }


        private static void OnConnectionInterruptedCallBack()
        {
            if (instance != null && instance.OnConnectionInterrupted != null)
                instance.OnConnectionInterrupted();
        }


        private static void OnRequestTokenCallBack()
        {
            if (instance != null && instance.OnRequestToken != null)
                instance.OnRequestToken();
        }


        private static void OnUserJoinedCallBack(uint uid, int elapsed)
        {
            if (instance != null && instance.OnUserJoined != null)
                instance.OnUserJoined(uid, elapsed);
        }


        private static void OnUserOfflineCallBack(uint uid, int reason)
        {
            if (instance != null && instance.OnUserOffline != null)
            {
                instance.OnUserOffline(uid, (USER_OFFLINE_REASON)reason);
            }
        }


        private static void OnAudioVolumeIndicationCallBack(string volumeInfo, int speakerNumber, int totalVolume)
        {
            if (instance != null && instance.OnVolumeIndication != null)
            {
                string[] sArray = volumeInfo.Split('\t');
                int j = 1;
                AudioVolumeInfo[] infos = new AudioVolumeInfo[speakerNumber];
                if (speakerNumber > 0)
                {
                    for (int i = 0; i < speakerNumber; i++)
                    {
                        uint uids = (uint)int.Parse(sArray[j++]);
                        uint vol = (uint)int.Parse(sArray[j++]);
                        infos[i].uid = uids;
                        infos[i].volume = vol;
                    }
                }
                instance.OnVolumeIndication(infos, speakerNumber, totalVolume);
            }
                
        }


        private static void OnUserMuteAudioCallBack(uint uid, bool muted)
        {
            if (instance != null && instance.OnUserMuted != null)
                instance.OnUserMuted(uid, muted);
        }


        private static void OnSDKWarningCallBack(int warn, string msg)
        {
            if (instance != null && instance.OnWarning != null)
                instance.OnWarning(warn, msg);
        }


        private static void OnSDKErrorCallBack(int error, string msg)
        {
            if (instance != null && instance.OnError != null)
                instance.OnError(error, msg);
        }


        private static void OnRtcStatsCallBack(uint duration, uint txBytes, uint rxBytes,
                                    ushort txKBitRate, ushort rxKBitRate, ushort rxAudioKBitRate,
                                    ushort txAudioKBitRate, ushort rxVideoKBitRate,
                                    ushort txVideoKBitRate, ushort lastmileQuality, uint userCount, double cpuAppUsage,
                                    double cpuTotalUsage)
        {
            if (instance != null && instance.OnRtcStats != null)
            {

                RtcStats rtcStats = new RtcStats();
                rtcStats.duration = duration;
                rtcStats.txBytes = txBytes;
                rtcStats.rxBytes = rxBytes;
                rtcStats.txKBitRate = txKBitRate;
                rtcStats.rxKBitRate = rxKBitRate;
                rtcStats.rxAudioKBitRate = rxAudioKBitRate;
                rtcStats.txAudioKBitRate = txAudioKBitRate;
                rtcStats.rxVideoKBitRate = rxVideoKBitRate;
                rtcStats.txVideoKBitRate = txVideoKBitRate;
                rtcStats.lastmileQuality = lastmileQuality;
                rtcStats.users = userCount;
                rtcStats.cpuAppUsage = cpuAppUsage;
                rtcStats.cpuTotalUsage = cpuTotalUsage;
                instance.OnRtcStats(rtcStats);
            }
        }


        private static void OnAudioMixingFinishedCallBack()
        {
            if (instance != null && instance.OnAudioMixingFinished != null)
                instance.OnAudioMixingFinished();
        }


        private static void OnAudioRouteChangedCallBack(int route)
        {
            if (instance != null && instance.OnAudioRouteChanged != null)
                instance.OnAudioRouteChanged((AUDIO_ROUTE)route);
        }


        private static void OnFirstRemoteVideoDecodedCallBack(uint uid, int width, int height, int elapsed)
        {
            if (instance != null && instance.OnFirstRemoteVideoDecoded != null)
            {

                instance.OnFirstRemoteVideoDecoded(uid, width, height, elapsed);
            }
        }


        private static void OnVideoSizeChangedCallBack(uint uid, int width, int height, int elapsed)
        {
            if (instance != null && instance.OnVideoSizeChanged != null)
            {
                // instance.OnVideoSizeChangedCallBack(uid, width, height, elapsed);
            }
        }

        private static void OnClientRoleChangedCallBack(int oldRole, int newRole)
        {
            if (instance != null && instance.OnClientRoleChanged != null)
                instance.OnClientRoleChanged(oldRole, newRole);
        }


        private static void OnUserMuteVideoCallBack(uint uid, bool muted)
        {
            if (instance != null && instance.OnUserMuteVideo != null)
                instance.OnUserMuteVideo(uid, muted);
        }


        private static void OnMicrophoneEnabledCallBack(bool isEnabled)
        {
            if (instance != null && instance.OnMicrophoneEnabled != null)
                instance.OnMicrophoneEnabled(isEnabled);
        }


        private static void OnApiExecutedCallBack(int err, string api, string result)
        {
            if (instance != null && instance.OnApiExecuted != null)
                instance.OnApiExecuted(err, api, result);
        }


        private static void OnFirstLocalAudioFrameCallBack(int elapsed)
        {
            if (instance != null && instance.OnFirstLocalAudioFrame != null)
                instance.OnFirstLocalAudioFrame(elapsed);
        }


        private static void OnFirstRemoteAudioFrameCallBack(uint userId, int elapsed)
        {
            if (instance != null && instance.OnFirstRemoteAudioFrame != null)
                instance.OnFirstRemoteAudioFrame(userId, elapsed);
        }


        private static void OnLastmileQualityCallBack(int quality)
        {
            if (instance != null && instance.OnLastmileQuality != null)
                instance.OnLastmileQuality(quality);
        }


        private static void OnAudioQualityCallBack(uint userId, int quality, ushort delay, ushort lost)
        {
            if (instance != null && instance.OnAudioQuality != null)
                instance.OnAudioQuality(userId, quality, delay, lost);
        }


        private static void OnStreamInjectedStatusCallBack(string url, uint userId, int status)
        {
            if (instance != null && instance.OnStreamInjectedStatus != null)
                instance.OnStreamInjectedStatus(url, userId, status);
        }


        private static void OnStreamUnpublishedCallBack(string url)
        {
            if (instance != null && instance.OnStreamUnpublished != null)
                instance.OnStreamUnpublished(url);
        }


        private static void OnStreamPublishedCallBack(string url, int error)
        {
            if (instance != null && instance.OnStreamPublished != null)
                instance.OnStreamPublished(url, error);
        }


        private static void OnStreamMessageErrorCallBack(uint userId, int streamId, int code, int missed, int cached)
        {
            if (instance != null && instance.OnStreamMessageError != null)
                instance.OnStreamMessageError(userId, streamId, code, missed, cached);
        }


        private static void OnStreamMessageCallBack(uint userId, int streamId, string data, int length)
        {
            if (instance != null && instance.OnStreamMessage != null)
                instance.OnStreamMessage(userId, streamId, data, length);
        }


        private static void OnConnectionBannedCallBack()
        {
            if (instance != null && instance.OnConnectionBanned != null)
                instance.OnConnectionBanned();
        }


        private static void OnNetworkQualityCallBack(uint uid, int txQuality, int rxQuality)
        {
            if (instance != null && instance.OnNetworkQuality != null)
                instance.OnNetworkQuality(uid, txQuality, rxQuality);
        }

        static byte[] bufArray = null;
        static int lastBufArraySize = 0;
        private static void OnCaptureVideoFrameRawCallBack(int width, int height, IntPtr yBuffer, int rotation)
        {
            if (instance != null && instance.onCaptureVideoFrameRaw != null)
            {
                if (!instanceReference.IsAlive)
                {
                    System.Diagnostics.Trace.WriteLine("OnCaptureVideoFrameRawCallBack callback isn't alive.");
                }
                int nSize = width * height * 3 / 2; // YUV420 data size
                if (nSize > 0)
                {
                    if (lastBufArraySize != nSize)
                    {
                        bufArray = new byte[nSize];
                        lastBufArraySize = nSize;
                    }

                    Marshal.Copy(yBuffer, bufArray, 0, nSize);
                    instance.onCaptureVideoFrameRaw(width, height, bufArray, rotation);
                }

            }
        }

        static byte[] bufArray2 = null;
        static int lastBufArraySize2 = 0;
        private static void OnRenderVideoFrameRawCallBack(uint userId, int width, int height, IntPtr yBuffer, int rotation)
        {
            if (instance != null && instance.onRenderVideoFrameRaw != null)
            {
                int nSize = width * height * 3 / 2; // YUV420 data size
                if (nSize > 0)
                {
                    if (lastBufArraySize2 != nSize)
                    {
                        bufArray2 = new byte[nSize];
                        lastBufArraySize2 = nSize;
                    }

                    Marshal.Copy(yBuffer, bufArray2, 0, nSize);
                    instance.onRenderVideoFrameRaw(userId, width, height, bufArray2, rotation);
                }

            }
        }


        private IRtcEngine(string appId)
        {
            //AgoraLoom.Initialize();
            InitGameObject();
            initCallBackObject();
            InitEngineCallBack();
            bool initSuccess = createEngine(appId);
            // mAudioEffectM = new AudioEffectManagerImpl(this);
        }

        ~IRtcEngine()
        {
            System.Diagnostics.Trace.WriteLine("IRtcEngine's destructor is called.");
            Console.WriteLine("~IRtcEngine");
        }

        private void InitGameObject()
        {
            //agoraGameObject = new GameObject(agoraGameObjectName);
            //agoraGameObject.AddComponent<AgoraCallBackQueue>();
            //GameObject.DontDestroyOnLoad(agoraGameObject);
            //agoraGameObject.hideFlags = HideFlags.HideInHierarchy;
        }

        private static void DeInitGameObject()
        {
            //GameObject agoraGameObject = GameObject.Find(agoraGameObjectName);
            //if (!ReferenceEquals(agoraGameObject, null))
            //{
            //    AgoraCallBackQueue.Current.ClearQueue();
            //    GameObject.Destroy(agoraGameObject);
            //    agoraGameObject = null;
            //}
        }

        private static EngineEventOnJoinChannelSuccessHandler OnJoinChannelSuccessHandler_ = OnJoinChannelSuccessCallBack;
        private static EngineEventOnLeaveChannelHandler OnLeaveChannelHandler_ = OnLeaveChannelCallBack;
        private static EngineEventOnReJoinChannelSuccessHandler OnReJoinChannelSuccessHandler_ = OnReJoinChannelSuccessCallBack;
        private static EngineEventOnConnectionLostHandler OnConnectionLostHandler_ = OnConnectionLostCallBack;
        private static EngineEventOnConnectionInterruptedHandler OnConnectionInterruptedHandler_ = OnConnectionInterruptedCallBack;
        private static EngineEventOnRequestTokenHandler OnRequestTokenHandler_ = OnRequestTokenCallBack;
        private static EngineEventOnUserJoinedHandler OnUserJoinedHandler_ = OnUserJoinedCallBack;
        private static EngineEventOnUserOfflineHandler OnUserOfflineHandler_ = OnUserOfflineCallBack;
        private static EngineEventOnAudioVolumeIndicationHandler OnAudioVolumeIndicationHandler_ = OnAudioVolumeIndicationCallBack;
        private static EngineEventOnUserMuteAudioHandler OnUserMuteAudioHandler_ = OnUserMuteAudioCallBack;
        private static EngineEventOnSDKWarningHandler OnSDKWarningHandler_ = OnSDKWarningCallBack;
        private static EngineEventOnSDKErrorHandler OnSDKErrorHandler_ = OnSDKErrorCallBack;
        private static EngineEventOnRtcStatsHandler OnRtcStatsHandler_ = OnRtcStatsCallBack;
        private static EngineEventOnAudioMixingFinishedHandler OnAudioMixingFinishedHandler_ = OnAudioMixingFinishedCallBack;
        private static EngineEventOnAudioRouteChangedHandler OnAudioRouteChangedHandler_ = OnAudioRouteChangedCallBack;
        private static EngineEventOnFirstRemoteVideoDecodedHandler OnFirstRemoteVideoDecodedHandler_ = OnFirstRemoteVideoDecodedCallBack;
        private static EngineEventOnVideoSizeChangedHandler OnVideoSizeChangedHandler_ = OnVideoSizeChangedCallBack;
        private static EngineEventOnClientRoleChangedHandler OnClientRoleChangedHandler_ = OnClientRoleChangedCallBack;
        private static EngineEventOnUserMuteVideoHandler OnUserMuteVideoHandler_ = OnUserMuteVideoCallBack;
        private static EngineEventOnMicrophoneEnabledHandler OnMicrophoneEnabledHandler_ = OnMicrophoneEnabledCallBack;
        private static EngineEventOnApiExecutedHandler OnApiExecutedHandler_ = OnApiExecutedCallBack;
        private static EngineEventOnFirstLocalAudioFrameHandler OnFirstLocalAudioFrameHandler_ = OnFirstLocalAudioFrameCallBack;
        private static EngineEventOnFirstRemoteAudioFrameHandler OnFirstRemoteAudioFrameHandler_ = OnFirstRemoteAudioFrameCallBack;
        private static EngineEventOnLastmileQualityHandler OnLastmileQualityHandler_ = OnLastmileQualityCallBack;
        private static EngineEventOnAudioQualityHandler OnAudioQualityHandler_ = OnAudioQualityCallBack;
        private static EngineEventOnStreamInjectedStatusHandler OnStreamInjectedStatusHandler_ = OnStreamInjectedStatusCallBack;
        private static EngineEventOnStreamUnpublishedHandler OnStreamUnpublishedHandler_ = OnStreamUnpublishedCallBack;
        private static EngineEventOnStreamPublishedHandler OnStreamPublishedHandler_ = OnStreamPublishedCallBack;
        private static EngineEventOnStreamMessageErrorHandler OnStreamMessageErrorHandler_ = OnStreamMessageErrorCallBack;
        private static EngineEventOnStreamMessageHandler OnStreamMessageHandler_ = OnStreamMessageCallBack;
        private static EngineEventOnConnectionBannedHandler OnConnectionBannedHandler_ = OnConnectionBannedCallBack;
        private static EngineEventOnNetworkQualityHandler OnNetworkQualityHandler_ = OnNetworkQualityCallBack;
        private static EngineEventOnCaptureVideoFrameRawHandler OnCaptureVideoFrameRawHandler_ = OnCaptureVideoFrameRawCallBack;
        private static EngineEventOnRenderVideoFrameRawHandler OnRenderVideoFrameRawHandler_ = OnRenderVideoFrameRawCallBack;

        /**
		 */
        private static void InitEngineCallBack()
        {
            initEventOnJoinChannelSuccess(OnJoinChannelSuccessHandler_);
            initEventOnLeaveChannel(OnLeaveChannelHandler_);
            initEventOnReJoinChannelSuccess(OnReJoinChannelSuccessHandler_);
            initEventOnConnectionLost(OnConnectionLostHandler_);
            initEventOnConnectionInterrupted(OnConnectionInterruptedHandler_);
            initEventOnRequestToken(OnRequestTokenHandler_);
            initEventOnUserJoined(OnUserJoinedHandler_);
            initEventOnUserOffline(OnUserOfflineHandler_);
            initEventOnAudioVolumeIndication(OnAudioVolumeIndicationHandler_);
            initEventOnUserMuteAudio(OnUserMuteAudioHandler_);
            initEventOnSDKWarning(OnSDKWarningHandler_);
            initEventOnSDKError(OnSDKErrorHandler_);
            initEventOnRtcStats(OnRtcStatsHandler_);
            initEventOnAudioMixingFinished(OnAudioMixingFinishedHandler_);
            initEventOnAudioRouteChanged(OnAudioRouteChangedHandler_);
            initEventOnFirstRemoteVideoDecoded(OnFirstRemoteVideoDecodedHandler_);
            initEventOnVideoSizeChanged(OnVideoSizeChangedHandler_);
            initEventOnClientRoleChanged(OnClientRoleChangedHandler_);
            initEventOnUserMuteVideo(OnUserMuteVideoHandler_);
            initEventOnMicrophoneEnabled(OnMicrophoneEnabledHandler_);
            initEventOnApiExecuted(OnApiExecutedHandler_);
            initEventOnFirstLocalAudioFrame(OnFirstLocalAudioFrameHandler_);
            initEventOnFirstRemoteAudioFrame(OnFirstRemoteAudioFrameHandler_);
            initEventOnLastmileQuality(OnLastmileQualityHandler_);
            initEventOnAudioQuality(OnAudioQualityHandler_);
            initEventOnStreamInjectedStatus(OnStreamInjectedStatusHandler_);
            initEventOnStreamUnpublished(OnStreamUnpublishedHandler_);
            initEventOnStreamPublished(OnStreamPublishedHandler_);
            initEventOnStreamMessageError(OnStreamMessageErrorHandler_);
            initEventOnStreamMessage(OnStreamMessageHandler_);
            initEventOnConnectionBanned(OnConnectionBannedHandler_);
            initEventOnNetworkQuality(OnNetworkQualityHandler_);
            initEventOnCaptureVideoFrameRaw(OnCaptureVideoFrameRawHandler_);
            initEventOnRenderVideoFrameRaw(OnRenderVideoFrameRawHandler_);
        }

        public string doFormat(string format, params object[] args)
        {
            return string.Format(CultureInfo.InvariantCulture, format, args);
        }

        /**
		 * get the version information of the SDK
		 *
		 * @return return the version string
		 */
        public static string GetSdkVersion()
        {
            return Marshal.PtrToStringAnsi(getSdkVersion());
        }

        /**
		 * get the error description from SDK (deprecated)
		 * @param [in] code
		 *        the error code
		 * @return return the error description string
		 */
        public static string GetErrorDescription(int code)
        {
            return "Unknown";
        }

        /**
		 * Set the channel profile: such as game free mode, game command mode
		 *
		 * @param profile the channel profile
		 * @return return 0 if success or an error code
		 */
        public int SetChannelProfile(CHANNEL_PROFILE profile)
        {
            return setChannelProfile((int)profile);
        }

        /**
		 * Set the role of user: such as broadcaster, audience
		 *
		 * @param role the role of client
		 * @param permissionKey the permission key to apply the role
		 * @return return 0 if success or an error code
		 */
        public int SetClientRole(CLIENT_ROLE role)
        {
            return setClientRole((int)role);
        }

        /**
		 * set the log information filter level
		 *
		 * @param [in] filter
		 *        the filter level
		 * @return return 0 if success or an error code
		 */
        public int SetLogFilter(LOG_FILTER filter)
        {
            return setLogFilter((uint)filter);
        }

        // about audio effects: use c interface instead of interface IAudioEffectManager
        /**
		 * set path to save the log file
		 *
		 * @param [in] filePath
		 *        the .log file path you want to saved
		 * @return return 0 if success or an error code
		 */
        public int SetLogFile(string filePath)
        {
            return setLogFile(filePath);
        }

        /**
		 * join the channel, if the channel have not been created, it will been created automatically
		 *
		 * @param [in] channelName
		 *        the channel name
		 * @param [in] info
		 *        the additional information, it can be null here
		 * @param [in] uid
		 *        the uid of you, if 0 the system will automatically allocate one for you
		 * @return return 0 if success or an error code
		 */
        public int JoinChannel(string channelName, string info, uint uid)
        {
            return JoinChannelByKey(null, channelName, info, uid);
        }

        public int JoinChannelByKey(string channelKey, string channelName, string info, uint uid)
        {
            int r = joinChannel(channelKey, channelName, info, uid);
            return r;
        }

        public int RenewToken(string token)
        {
            // save parameters
            return renewToken(token);
        }

        /**
		 * leave the current channel
		 *
		 * @return return 0 if success or an error code
		 */
        public int LeaveChannel()
        {
            int r = leaveChannel(); // leave uncondionally
            return r;
        }

        /**
		 * Pause only control audio,you can use DisableAudio replace this api
		 */
        public void Pause()
        {
            // Debug.Log("Pause engine");
            DisableAudio();
        }

        /**
		 * Resume only control audio,you can use EnableAudio replace this api
		 */
        public void Resume()
        {
            // Debug.Log("Resume engine");
            EnableAudio();
        }

        /**
		 * set parameters of the SDK
		 *
		 * @param [in] parameters
		 *        the parameters(in json format)
		 * @return return 0 if success or an error code
		 */
        public int SetParameters(string parameters)
        {
            return setParameters(parameters);
        }

        public int SetParameter(string parameter, int value)
        {
            string parameters = doFormat("{{\"{0}\": {1}}}", parameter, value);
            return setParameters(parameters);
        }

        public int SetParameter(string parameter, double value)
        {
            string parameters = doFormat("{{\"{0}\": {1}}}", parameter, value);
            return setParameters(parameters);
        }

        public int SetParameter(string parameter, bool value)
        {
            string boolValue = value ? "true" : "false";
            string parameters = doFormat("{{\"{0}\": {1}}}", parameter, boolValue);
            return setParameters(parameters);
        }

        public string GetCallId()
        {
            string s = null;
            IntPtr res = getCallId();
            if (res != IntPtr.Zero)
            {
                s = Marshal.PtrToStringAnsi(res);
                freeObject(res);
            }
            return s;
        }

        public int Rate(string callId, int rating, string desc)
        {
            return rate(callId, rating, desc);
        }

        public int Complain(string callId, string desc)
        {
            return complain(callId, desc);
        }


        /**
		 * enable audio function, which is enabled by deault.
		 *
		 * @return return 0 if success or an error code
		 */
        public int EnableAudio()
        {
            return enableAudio();
        }

        /**
		 * disable audio function
		 *
		 * @return return 0 if success or an error code
		 */
        public int DisableAudio()
        {
            return disableAudio();
        }

        /**
		 * mute/unmute the local audio stream capturing
		 *
		 * @param [in] mute
		 *       true: mute
		 *       false: unmute
		 * @return return 0 if success or an error code
		 */
        public int MuteLocalAudioStream(bool mute)
        {
            return muteLocalAudioStream(mute);
        }

        /**
		 * mute/unmute all the remote audio stream receiving
		 *
		 * @param [in] mute
		 *       true: mute
		 *       false: unmute
		 * @return return 0 if success or an error code
		 */
        public int MuteAllRemoteAudioStreams(bool mute)
        {
            return muteAllRemoteAudioStreams(mute);
        }

        /**
		 * mute/unmute specified remote audio stream receiving
		 *
		 * @param [in] uid
		 *        the uid of the remote user you want to mute/unmute
		 * @param [in] mute
		 *       true: mute
		 *       false: unmute
		 * @return return 0 if success or an error code
		 */
        public int MuteRemoteAudioStream(uint uid, bool mute)
        {
            return muteRemoteAudioStream(uid, mute);
        }

        public int SetEnableSpeakerphone(bool speakerphone)
        {
            return setEnableSpeakerphone(speakerphone);
        }

        public int SetDefaultAudioRouteToSpeakerphone(bool speakerphone)
        {
            return setDefaultAudioRoutetoSpeakerphone(speakerphone);
        }

        public bool IsSpeakerphoneEnabled()
        {
            return isSpeakerphoneEnabled() != 0;
        }

        public int SwitchCamera()
        {
            return switchCamera();
        }

        public int SetVideoProfile(int profile, bool swapWidthAndHeight)
        {
            return setVideoProfile(profile, swapWidthAndHeight);
        }

        public int MuteLocalVideoStream(bool mute)
        {
            return muteLocalVideoStream(mute);
        }

        public int MuteAllRemoteVideoStreams(bool mute)
        {
            return muteAllRemoteVideoStreams(mute);
        }

        public int MuteRemoteVideoStream(uint uid, bool mute)
        {
            return muteRemoteVideoStream(uid, mute);
        }

        public int EnableDualStreamMode(bool enabled)
        {
            return enableDualStreamMode(enabled);
        }

        public int SetEncryptionMode(string encryptionMode)
        {
            return setEncryptionMode(encryptionMode);
        }

        public int SetEncryptionSecret(string secret)
        {
            return setEncryptionSecret(secret);
        }

        public int StartRecordingService(string recordingKey)
        {
            return startRecordingService(recordingKey);
        }

        public int StopRecordingService(string recordingKey)
        {
            return stopRecordingService(recordingKey);
        }

        public int RefreshRecordingServiceStatus()
        {
            return refreshRecordingServiceStatus();
        }


        public int CreateDataStream(bool reliable, bool ordered)
        {
            return createDataStream(reliable, ordered);
        }

        public int SendStreamMessage(int streamId, string data)
        {
            return sendStreamMessage(streamId, data, data.Length);
        }


        public int SetRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
        {
            return setRecordingAudioFrameParametersWithSampleRate(sampleRate, channel, mode, samplesPerCall);
        }

        public int SetPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
        {
            return setPlaybackAudioFrameParametersWithSampleRate(sampleRate, channel, mode, samplesPerCall);
        }

        public int SetSpeakerphoneVolume(int volume)
        {
            return setSpeakerphoneVolume(volume);
        }

        public int SetVideoQualityParameters(bool preferFrameRateOverImageQuality)
        {
            return setVideoQualityParameters(preferFrameRateOverImageQuality);
        }

        public int StartEchoTest()
        {
            return startEchoTest();
        }

        public int StopEchoTest()
        {
            return stopEchoTest();
        }

        public int SetRemoteVideoStreamType(uint uid, int streamType)
        {
            return setRemoteVideoStreamType(uid, streamType);
        }

        public int SetMixedAudioFrameParameters(int sampleRate, int samplesPerCall)
        {
            return setMixedAudioFrameParameters(sampleRate, samplesPerCall);
        }

        public int SetAudioMixingPosition(int pos)
        {
            return setAudioMixingPosition(pos);
        }

        /**
		 * enable or disable the audio volume indication
		 *
		 * @param [in] interval
		 *        the period of the callback cycle, in ms
		 *        interval <= 0: disable
		 *        interval >  0: enable
		 * @param [in] smooth
		 *        the smooth parameter
		 * @return return 0 if success or an error code
		 */
        public int EnableAudioVolumeIndication(int interval, int smooth)
        {
            return enableAudioVolumeIndication(interval, smooth);
        }

        /**
		 * adjust recording signal volume
		 *
		 * @param [in] volume range from 0 to 400
		 * @return return 0 if success or an error code
		 */
        public int AdjustRecordingSignalVolume(int volume)
        {
            return adjustRecordingSignalVolume(volume);
        }

        /**
		 * adjust playback signal volume
		 *
		 * @param [in] volume range from 0 to 400
		 * @return return 0 if success or an error code
		 */
        public int AdjustPlaybackSignalVolume(int volume)
        {
            return adjustPlaybackSignalVolume(volume);
        }

        /**
		 * mix microphone and local audio file into the audio stream
		 *
		 * @param [in] filePath
		 *        specify the path and file name of the audio file to be played
		 * @param [in] loopback
		 *        specify if local and remote participant can hear the audio file.
		 *        false (default): both local and remote party can hear the the audio file
		 *        true: only the local party can hear the audio file
		 * @param [in] replace
		 *        false (default): mix the local microphone captured voice with the audio file
		 *        true: replace the microphone captured voice with the audio file
		 * @param [in] cycle
		 *        specify the number of cycles to play
		 *        -1, infinite loop playback
		 * @param [in] playTime (not support)
		 *        specify the start time(ms) of the audio file to play
		 *        0, from the start
		 * @return return 0 if success or an error code
		 */
        public int StartAudioMixing(string filePath, bool loopback, bool replace, int cycle, int playTime = 0)
        {
            return startAudioMixing(filePath, loopback, replace, cycle, playTime);
        }

        /**
		 * stop mixing the local audio stream
		 *
		 * @return return 0 if success or an error code
		 */
        public int StopAudioMixing()
        {
            return stopAudioMixing();
        }

        /**
		 * pause mixing the local audio stream
		 *
		 * @return return 0 if success or an error code
		 */
        public int PauseAudioMixing()
        {
            return pauseAudioMixing();
        }

        /**
		 * resume mixing the local audio stream
		 *
		 * @return return 0 if success or an error code
		 */
        public int ResumeAudioMixing()
        {
            return resumeAudioMixing();
        }

        /**
		 * adjust mixing audio file volume
		 *
		 * @param [in] volume range from 0 to 100
		 * @return return 0 if success or an error code
		 */
        public int AdjustAudioMixingVolume(int volume)
        {
            return adjustAudioMixingVolume(volume);
        }

        /**
		 * get the duration of the specified mixing audio file
		 *
		 * @return return duration(ms)
		 */
        public int GetAudioMixingDuration()
        {
            return getAudioMixingDuration();
        }

        /**
		 * get the current playing position of the specified mixing audio file
		 *
		 * @return return the current playing(ms)
		 */
        public int GetAudioMixingCurrentPosition()
        {
            return getAudioMixingCurrentPosition();
        }

        /**
		 * start recording audio streaming to file specified by the file path
		 *
		 * @param filePath file path to save recorded audio streaming
		 * @return return 0 if success or an error code
		 * Deprecated. Use int StartAudioRecording(string filePath, AUDIO_RECORDING_QUALITY_TYPE quality)
		 */
        public int StartAudioRecording(string filePath)
        {
            return StartAudioRecording(filePath, AUDIO_RECORDING_QUALITY_TYPE.AUDIO_RECORDING_QUALITY_MEDIUM);
        }

        public int StartAudioRecording(string filePath, AUDIO_RECORDING_QUALITY_TYPE quality)
        {
            return startAudioRecording(filePath, (int)quality);
        }

        /**
		 * stop audio streaming recording
		 *
		 * @return return 0 if success or an error code
		 */
        public int StopAudioRecording()
        {
            return stopAudioRecording();
        }

        public IAudioEffectManager GetAudioEffectManager()
        {
            return null;
        }

        /**
		 * start video engine and start record video data
		 * 
		 * @return return 0 if success or an error code
		 */
        public int EnableVideo()
        {
            return enableVideo();
        }

        /**
		 * stop video engine and stop record video data
		 *
		 * @return return 0 if success or an error code
		 */
        public int DisableVideo()
        {
            return disableVideo();
        }

        /**
		 * open/close your local video ,don't affect remote video.
		 * 
		 * @return return 0 if success or an error code
		 */
        public int EnableLocalVideo(bool enabled)
        {
            return enableLocalVideo(enabled);
        }

        /**
		 * open/close your local microphone, don't affect remote audio.
		 * 
		 * @return return 0 if success or an error code
		 */
        public int EnableLocalAudio(bool enabled)
        {
            return enableLocalAudio(enabled);
        }

        public int StartPreview()
        {
            return startPreview();
        }

        public int StopPreview()
        {
            return stopPreview();
        }

        public int GetEffectsVolume()
        {
            return getEffectsVolume();
        }

        public int SetEffectsVolume(int volume)
        {
            return setEffectsVolume(volume);
        }

        public int PlayEffect(int soundId, string filePath, int loopCount, double pitch, double pan, int gain, bool publish)
        {
            return playEffect(soundId, filePath, loopCount, pitch, pan, gain, publish);
        }

        public int StopEffect(int soundId)
        {
            return stopEffect(soundId);
        }

        public int StopAllEffects()
        {
            return stopAllEffects();
        }

        public int PreloadEffect(int soundId, string filePath)
        {
            return preloadEffect(soundId, filePath);
        }

        public int UnloadEffect(int soundId)
        {
            return unloadEffect(soundId);
        }

        public int PauseEffect(int soundId)
        {
            return pauseEffect(soundId);
        }

        public int PauseAllEffects()
        {
            return pauseAllEffects();
        }

        public int ResumeEffect(int soundId)
        {
            return resumeEffect(soundId);
        }

        public int ResumeAllEffects()
        {
            return resumeAllEffects();
        }

        /**
		 * If you want to video work in unity, you need to call both enableVideo and enableVideoObserver, 
		 * this api is used to get data from agora raw data which can produce texture by openGl.
		 *
		 * @return return 0 if success or error code.
		 */
        public int EnableVideoObserver()
        {
            return enableVideoObserver();
        }

        /**
		 * this api is only used to stop get video raw data from agora engine, it won't stop video engine.
		 * If you want to stop video engine ,you can call disableVideo.
		 *
		 * @return return 0 if success or error code.
		 */
        public int DisableVideoObserver()
        {
            return disableVideoObserver();
        }

        // load data to texture
        public int UpdateTexture(int tex, uint uid, IntPtr data, ref int width, ref int height)
        {
            int rc = updateTexture(tex, data, uid);
            if (rc == -1)
                return -1;
            width = (int)rc >> 16;
            height = (int)(rc & 0xffff);
            return 0;
        }

        public int GenerateNativeTexture()
        {
            return generateNativeTexture();
        }

        public void DeleteTexture(int tex)
        {
            deleteTexture(tex);
        }

        public int SetLocalVoicePitch(double pitch)
        {
            return setLocalVoicePitch(pitch);
        }

        public int SetRemoteVoicePosition(uint uid, double pan, double gain)
        {
            return setRemoteVoicePosition(uid, pan, gain);
        }

        public int SetVoiceOnlyMode(bool enable)
        {
            return setVoiceOnlyMode(enable);
        }

        public int SetDefaultMuteAllRemoteAudioStreams(bool mute)
        {
            return setDefaultMuteAllRemoteAudioStreams(mute);
        }

        public int SetDefaultMuteAllRemoteVideoStreams(bool mute)
        {
            return setDefaultMuteAllRemoteVideoStreams(mute);
        }

        public int EnableLastmileTest()
        {
            return enableLastmileTest();
        }

        public int DisableLastmileTest()
        {
            return disableLastmileTest();
        }

        public int EnableWebSdkInteroperability(bool enabled)
        {
            return enableWebSdkInteroperability(enabled);
        }

        public int PushExternVideoFrame(ExternalVideoFrame externalVideoFrame)
        {
            return pushExternVideoFrame((int)externalVideoFrame.type, (int)externalVideoFrame.format, externalVideoFrame.buffer, externalVideoFrame.stride, externalVideoFrame.height, externalVideoFrame.cropLeft, externalVideoFrame.cropTop, externalVideoFrame.cropRight, externalVideoFrame.cropBottom, externalVideoFrame.rotation, externalVideoFrame.timestamp);
        }

        public int SetExternalVideoSource(bool enable, bool useTexture)
        {
            return setExternalVideoSource(enable, useTexture);
        }

        public int SetLiveTranscoding(LiveTranscoding transcoding)
        {
            return setLiveTranscoding(transcoding.width, transcoding.height, transcoding.videoBitrate, transcoding.videoFramerate, transcoding.lowLatency, transcoding.videoGop, (int)transcoding.videoCodecProfile, transcoding.backgroundColor, transcoding.userCount, transcoding.transcodingUsers.uid, transcoding.transcodingUsers.x, transcoding.transcodingUsers.y, transcoding.transcodingUsers.width, transcoding.transcodingUsers.height, transcoding.transcodingUsers.zOrder, transcoding.transcodingUsers.alpha, transcoding.transcodingUsers.audioChannel, transcoding.transcodingExtraInfo, transcoding.metadata, transcoding.watermark.url, transcoding.watermark.x, transcoding.watermark.y, transcoding.watermark.width, transcoding.watermark.height, transcoding.backgroundImage.url, transcoding.backgroundImage.x, transcoding.backgroundImage.y, transcoding.backgroundImage.width, transcoding.backgroundImage.height, (int)transcoding.audioSampleRate, transcoding.audioBitrate, transcoding.audioChannels, (int)transcoding.audioCodecProfile);
        }

        public int AddPublishStreamUrl(string url, bool transcodingEnabled)
        {
            return addPublishStreamUrl(url, transcodingEnabled);
        }

        public int RemovePublishStreamUrl(string url)
        {
            return removePublishStreamUrl(url);
        }

        public int ConfigPublisher(PublisherConfiguration publisherConfiguration)
        {
            return configPublisher(publisherConfiguration.width, publisherConfiguration.height, publisherConfiguration.framerate, publisherConfiguration.bitrate, publisherConfiguration.defaultLayout, publisherConfiguration.lifecycle, publisherConfiguration.owner, publisherConfiguration.injectStreamWidth, publisherConfiguration.injectStreamHeight, publisherConfiguration.injectStreamUrl, publisherConfiguration.publishUrl, publisherConfiguration.rawStreamUrl, publisherConfiguration.extraInfo);
        }

        public int SetVideoCompositingLayout(VideoCompositingLayout videoCompositing)
        {
            return setVideoCompositingLayout(videoCompositing.canvasWidth, videoCompositing.canvasHeight, videoCompositing.backgroundColor, videoCompositing.regions.uid, videoCompositing.regions.x, videoCompositing.regions.y, videoCompositing.regions.width, videoCompositing.regions.height, videoCompositing.regions.zOrder, videoCompositing.regions.alpha, (int)videoCompositing.regions.renderMode, videoCompositing.regionCount, videoCompositing.appData, videoCompositing.appDataLength);
        }

        public int ClearVideoCompositingLayout()
        {
            return clearVideoCompositingLayout();
        }

        public int AddVideoWatermark(RtcImage rtcImage)
        {
            return addVideoWatermark(rtcImage.url, rtcImage.x, rtcImage.y, rtcImage.width, rtcImage.height);
        }

        public int ClearVideoWatermarks()
        {
            return clearVideoWatermarks();
        }

        public int SetBeautyEffectOptions(bool enabled, BeautyOptions beautyOptions)
        {
            return setBeautyEffectOptions(enabled, (int)beautyOptions.lighteningContrastLevel, beautyOptions.lighteningLevel, beautyOptions.smoothnessLevel, beautyOptions.rednessLevel);
        }

        public int AddInjectStreamUrl(string url, InjectStreamConfig injectStreamConfig)
        {
            return addInjectStreamUrl(url, injectStreamConfig.width, injectStreamConfig.height, injectStreamConfig.videoGop, injectStreamConfig.videoFramerate, injectStreamConfig.videoBitrate, (int)injectStreamConfig.audioSampleRate, injectStreamConfig.audioBitrate, injectStreamConfig.audioChannels);
        }

        public int RemoveInjectStreamUrl(string url)
        {
            return removeInjectStreamUrl(url);
        }

        public int SetExternalAudioSource(bool enabled, int sampleRate, int channels)
        {
            return setExternalAudioSource(enabled, sampleRate, channels);
        }

        public int StartScreenCapture(IntPtr windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate, String gameName)
        {
            return startScreenCapture(windowId, captureFreq, rc_left, rc_top, rc_width, rc_height, bitrate, gameName);
        }

        public int StopScreenCapture()
        {
            return stopScreenCapture();
        }

        public int StartScreenCaptureEx(IntPtr windowId, int captureFreq, int rc_left, int rc_top, int rc_width, int rc_height, int bitrate)
        {
            return startScreenCaptureEx(windowId, captureFreq, rc_left, rc_top, rc_width, rc_height, bitrate);
        }

        public int StopScreenCaptureEx()
        {
            return stopScreenCaptureEx();
        }

        public int SetExternalAudioSink(bool enabled, int sampleRate, int channels)
        {
            return setExternalAudioSink(enabled, sampleRate, channels);
        }

        public int PushAudioFrame(AudioFrame audioFrame)
        {
            return pushExternalAudioFrame((int)audioFrame.type, audioFrame.samples, audioFrame.bytesPerSample, audioFrame.channels, audioFrame.samplesPerSec, audioFrame.buffer, audioFrame.renderTimeMs, audioFrame.avsync_type);
        }

        public int EnableSoundPositionIndication(bool enabled)
        {
            return enableSoundPositionIndication(enabled);
        }

        public int SetupLocalVideo(int view, int renderMode, UInt32 uid, IntPtr priv)
        {
            return setupLocalVideo(view, renderMode, uid, priv);
        }

        public int SetupRemoteVideo(int view, int renderMode, UInt32 uid, IntPtr priv)
        {
            return setupRemoteVideo(view, renderMode, uid, priv);
        }

        public static IRtcEngine GetEngine(string appId)
        {
            if (instance == null)
            {
                instance = new IRtcEngine(appId);
                instanceReference = new WeakReference(instance);

            }
            return instance;
        }

        // depricated. use GetEngine instead
        public static IRtcEngine getEngine(string appId)
        {
            return GetEngine(appId);
        }

        public static void Destroy()
        {
            // break the connection with mAudioEffectM
            AudioEffectManagerImpl am;
            if (instance != null)
            {
                am = (AudioEffectManagerImpl)instance.GetAudioEffectManager();
                if (am != null)
                {
                    am.SetEngine(null);
                }
            }
            deleteEngine();
            instance = null;
            DeInitGameObject();
        }

        // only query, do not create
        public static IRtcEngine QueryEngine()
        {
            return instance;
        }
        private static IRtcEngine instance = null;
        private static WeakReference instanceReference = null;
    }
};

