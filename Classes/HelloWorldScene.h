#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#define HOMEBG  1000
#define OPENIMG 1001
#define SENDIMG 1002
#define EXIT    1003
#define LBL     1004

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "AlbumTest.h"
#endif

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
, public AlbumTestDelegate
#endif
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

private:
    float m_width;
    float m_height;
    
    void getImgs();
    void sendImg();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
public:
    void finishGetAlbum();
#endif

};

#endif // __HELLOWORLD_SCENE_H__
