//
//  AlbumTest.h
//  albumDemo
//
//  Created by liuhui on 16/4/6.
//
//

#ifndef __albumDemo__AlbumTest__
#define __albumDemo__AlbumTest__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <platform/android/jni/JniHelper.h>
#include <string>

class AlbumTestDelegate{
public:
    virtual void finishGetAlbum() = 0;
    virtual ~AlbumTestDelegate(){};
};

class AlbumTest{
public:
    static void getAlbum(AlbumTestDelegate*);
};

#endif

#endif /* defined(__albumDemo__AlbumTest__) */
