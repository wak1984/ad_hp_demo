#ifndef AGORA_WRAPPER_VIDEOFRAME_OBSERVER
#define AGORA_WRAPPER_VIDEOFRAME_OBSERVER

#include "CPlatformDifference.h"
#include "AgoraWrapperCachePicture.h"

static long long OS_GetTickCount();

class AgoraWrapperVideoFrameObserver : public agora::media::IVideoFrameObserver
{
public:
  AgoraWrapperVideoFrameObserver();
  ~AgoraWrapperVideoFrameObserver();

  void reset();
  AgoraWrapperCachePicture *LockPicture(unsigned int uid);
  void UnlockPicture(unsigned int uid);
  bool onCaptureVideoFrame(VideoFrame &videoFrame);
  bool onRenderVideoFrame(unsigned int uid, VideoFrame &videoFrame);
  unsigned int createTexture();
  int updateTexture(unsigned int texId, unsigned char *data, unsigned int uid);
  void deleteTexture(unsigned int texId);
  void checkZombie();

private:
  std::map<unsigned int /*uid*/, AgoraWrapperCachePicture *> mCachedPictures;
  std::mutex mMapMutex;
  std::list<unsigned int /*texture*/> mTextures;
  std::map<unsigned int /*uid*/, long long /*time stamp*/> mUserActive;
  long long mllLastZombieCheck; // time when last zombie check
};

#endif