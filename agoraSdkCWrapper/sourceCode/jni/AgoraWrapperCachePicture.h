#ifndef AGORA_WRAPPER_CACHE_PICTURE
#define AGORA_WRAPPER_CACHE_PICTURE
#include "CPlatformDifference.h"

class AgoraWrapperCachePicture
{
public:
  AgoraWrapperCachePicture();
  AgoraWrapperCachePicture(int w, int h);
  ~AgoraWrapperCachePicture();

  void *pic;
  int width;
  int height;
};
#endif