#include "AgoraWrapperVideoFrameObserver.h"
#include "CWrapperRtcEngineEventHandler.h"

static long long OS_GetTickCount()
{
#if defined(WIN32)
    return GetTickCount();
#else
    int64_t t0;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    t0 = ((int64_t)tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return t0;
#endif
}

AgoraWrapperVideoFrameObserver::AgoraWrapperVideoFrameObserver()
{
    mllLastZombieCheck = 0;
}

AgoraWrapperVideoFrameObserver::~AgoraWrapperVideoFrameObserver()
{
    reset();
}

void AgoraWrapperVideoFrameObserver::reset()
{
    mMapMutex.lock();
    std::map<unsigned int, AgoraWrapperCachePicture *>::iterator it;
    for (it = mCachedPictures.begin(); it != mCachedPictures.end(); it++)
    {
        AgoraWrapperCachePicture *cached = it->second;
        delete cached;
    }
    mCachedPictures.clear();
    mUserActive.clear();
    mMapMutex.unlock();
    mTextures.clear();
    mllLastZombieCheck = 0;
}

AgoraWrapperCachePicture *AgoraWrapperVideoFrameObserver::LockPicture(unsigned int uid)
{
    mMapMutex.lock();
    AgoraWrapperCachePicture *ret = NULL;
    std::map<unsigned int, AgoraWrapperCachePicture *>::iterator it = mCachedPictures.find(uid);
    if (it != mCachedPictures.end())
    {
        ret = it->second;
    }

    if (ret == NULL)
        mMapMutex.unlock();
    return ret;
}

void AgoraWrapperVideoFrameObserver::UnlockPicture(unsigned int uid)
{
    mMapMutex.unlock();
}

unsigned int AgoraWrapperVideoFrameObserver::createTexture()
{
#if defined(WRAPPER_WINDOWS)
    
    return 0;
#else
#if defined(WRAPPER_MAC)

    return 0;
#else
#if defined(WRAPPER_ANDROID)

    return 0;
#else
#if defined(WRAPPER_IOS)

    return 0;
#else
    unsigned int tex;
    glGenTextures(1, &tex);
    // TODO: query current active texture unit and bound texture and restore later
    //glActiveTexture(GL_TEXTURE0);
    int oldTex = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &oldTex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, oldTex);
    mTextures.push_back(tex);
    return tex;
#endif //
#endif
#endif
#endif
}

int AgoraWrapperVideoFrameObserver::updateTexture(unsigned int texId, unsigned char *data, unsigned int uid)
{

#if defined(WRAPPER_WINDOWS)
    AgoraWrapperCachePicture *cached = LockPicture(uid);
    if (cached == NULL)
    {
        return -1;
    }
    memcpy(data, cached->pic, cached->width * cached->height * 4);
    UnlockPicture(uid);
    return (cached->width << 16 | cached->height);

#else
#if defined(WRAPPER_MAC)
    AgoraWrapperCachePicture *cached = LockPicture(uid);
    if (cached == NULL)
    {
        return -1;
    }
    memcpy(data, cached->pic, cached->width * cached->height * 4);
    UnlockPicture(uid);
    return (cached->width << 16 | cached->height);
#else
#if defined(WRAPPER_ANDROID)
    AgoraWrapperCachePicture *cached = LockPicture(uid);
    if (cached == NULL)
    {
        return -1;
    }
    memcpy(data, cached->pic, cached->width * cached->height * 4);
    UnlockPicture(uid);
    return (cached->width << 16 | cached->height);
#else
#if defined(WRAPPER_IOS)
    AgoraWrapperCachePicture *cached = LockPicture(uid);
    if (cached == NULL)
    {
        return -1;
    }
    memcpy(data, cached->pic, cached->width * cached->height * 4);
    UnlockPicture(uid);
    return (cached->width << 16 | cached->height);
#else
    AgoraWrapperCachePicture *cached = LockPicture(uid);
    if (cached == NULL)
    {
        return -1;
    }
    //  glActiveTexture(GL_TEXTURE0);
    int oldTex = 0;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &oldTex);
    glBindTexture(GL_TEXTURE_2D, texId);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    //    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, cached->width, cached->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, cached->pic);
    glBindTexture(GL_TEXTURE_2D, oldTex);
    UnlockPicture(uid);
    return (cached->width << 16 | cached->height);
#endif
#endif
#endif
#endif
}

void AgoraWrapperVideoFrameObserver::deleteTexture(unsigned int texId)
{

#if defined(WRAPPER_WINDOWS)

#else
#if defined(WRAPPER_MAC)

#else
    std::list<unsigned int /*texture*/>::iterator it;
    for (it = mTextures.begin(); it != mTextures.end(); it++)
    {
        if (*it == texId)
        {
            glDeleteTextures(1, &texId);
            mTextures.erase(it);
            break;
        }
    }
#endif //
#endif
}

bool AgoraWrapperVideoFrameObserver::onCaptureVideoFrame(VideoFrame &videoFrame)
{
    if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_YUV420)
    {
        return false;
    }
    mMapMutex.lock();
    std::map<unsigned int, AgoraWrapperCachePicture *>::iterator it;
    it = mCachedPictures.find(0);
    if (it == mCachedPictures.end())
    {
        // create
        AgoraWrapperCachePicture *cached = new AgoraWrapperCachePicture(videoFrame.width, videoFrame.height);
        memcpy(cached->pic, videoFrame.yBuffer, videoFrame.yStride * videoFrame.height); // assert videoFrame.yStride == videoFrame.width * 4
        mCachedPictures[0] = cached;
    }
    else
    {
        AgoraWrapperCachePicture *cached = mCachedPictures[0];
        if (cached->width != videoFrame.width || cached->height != videoFrame.height)
        {

            // resize is needed
            delete cached;
            cached = new AgoraWrapperCachePicture(videoFrame.width, videoFrame.height);
            mCachedPictures[0] = cached;
        }
        memcpy(cached->pic, videoFrame.yBuffer, videoFrame.yStride * videoFrame.height); // assert videoFrame.yStride == videoFrame.width * 4
    }

    mUserActive[0] = OS_GetTickCount();
    mMapMutex.unlock();
    checkZombie();
    return true;
}

bool AgoraWrapperVideoFrameObserver::onRenderVideoFrame(unsigned int uid, VideoFrame &videoFrame)
{
    if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_YUV420)
    {
        return false;
    }
    mMapMutex.lock();
    std::map<unsigned int, AgoraWrapperCachePicture *>::iterator it;
    it = mCachedPictures.find(uid);
    if (it == mCachedPictures.end())
    {
        // create
        AgoraWrapperCachePicture *cached = new AgoraWrapperCachePicture(videoFrame.width, videoFrame.height);
        memcpy(cached->pic, videoFrame.yBuffer, videoFrame.yStride * videoFrame.height); // assert videoFrame.yStride == videoFrame.width * 4
        mCachedPictures[uid] = cached;
    }
    else
    {
        AgoraWrapperCachePicture *cached = mCachedPictures[uid];
        if (cached->width != videoFrame.width || cached->height != videoFrame.height)
        {
            // resize is needed
            delete cached;
            cached = new AgoraWrapperCachePicture(videoFrame.width, videoFrame.height);
            mCachedPictures[uid] = cached;
        }
        memcpy(cached->pic, videoFrame.yBuffer, videoFrame.yStride * videoFrame.height); // assert videoFrame.yStride == videoFrame.width * 4
    }

    mUserActive[uid] = OS_GetTickCount();
    mMapMutex.unlock();
    checkZombie();
    return true;
}

void AgoraWrapperVideoFrameObserver::checkZombie()
{
    long long now = OS_GetTickCount();
    if (now - mllLastZombieCheck < 500)
        return;
    mMapMutex.lock();
    std::map<unsigned int, long long>::iterator it1;
    for (it1 = mUserActive.begin(); it1 != mUserActive.end();)
    {
        long long last = it1->second;
        if (now - last > 4000)
        {
            // zombie found!
            unsigned int usr = it1->first;
            std::map<unsigned int, long long>::iterator it2 = it1;
            it1++;
            mUserActive.erase(it2);
            std::map<unsigned int, AgoraWrapperCachePicture *>::iterator itPic = mCachedPictures.find(usr);
            if (itPic != mCachedPictures.end())
            {
                AgoraWrapperCachePicture *cached = itPic->second;
                if (cached != NULL)
                    delete cached;
                mCachedPictures.erase(itPic);
            }
        }
        else
        {
            it1++;
        }
    }
    mMapMutex.unlock();
    mllLastZombieCheck = now;
}