#include "AgoraWrapperCachePicture.h"

AgoraWrapperCachePicture::AgoraWrapperCachePicture()
{
    pic = NULL;
    height = 0;
    width = 0;
}

AgoraWrapperCachePicture::AgoraWrapperCachePicture(int w, int h)
{
    height = h;
    width = w;
    pic = malloc(w * h * 4);
}

AgoraWrapperCachePicture::~AgoraWrapperCachePicture()
{
    if (pic != NULL)
    {
        free(pic);
    }
}
