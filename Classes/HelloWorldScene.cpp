#include "HelloWorldScene.h"
#include "Global.h"
#include "time.h"
#include "stdlib.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    srand(time(NULL));
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    m_width = visibleSize.width;
    m_height = visibleSize.height;
    
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true); // not need
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    Sprite* bg = Sprite::create("home_bg.png");
    bg->setPosition(visibleSize/2);
    bg->setTag(HOMEBG);
    addChild(bg);

    Sprite* openImg = Sprite::create("openImg.png");
    openImg->setPosition(m_width*0.2531, m_height*0.3468);
    openImg->setTag(OPENIMG);
    addChild(openImg);
    
    Sprite* sendImg = Sprite::create("sendImg.png");
    sendImg->setPosition(m_width*0.7484, m_height*0.3468);
    sendImg->setTag(SENDIMG);
    addChild(sendImg);
    
    Label* lbl = Label::create();
    lbl->setTextColor(Color4B::WHITE);
    lbl->setSystemFontSize(50.00);
    lbl->setHorizontalAlignment(TextHAlignment::CENTER);
    lbl->setString("0");
    lbl->setPosition(m_width*0.5000, m_height*0.1800);
    lbl->setTag(LBL);
    addChild(lbl);
    
    Sprite* pExit = Sprite::create("exits_b.png");
    pExit->setPosition(m_width*0.5000, m_height*0.1000);
    pExit->setTag(EXIT);
    addChild(pExit);
    
    return true;
}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    Vec2 touchLocation = convertTouchToNodeSpace(touch);
    
    if(getChildByTag(EXIT)->getBoundingBox().containsPoint(touchLocation)){
        Director::getInstance()->stopAnimation();
        Director::getInstance()->end();
        exit(0);
    }
    if(getChildByTag(OPENIMG)->getBoundingBox().containsPoint(touchLocation)){
        getImgs();
    }
    if(getChildByTag(SENDIMG)->getBoundingBox().containsPoint(touchLocation)){
        sendImg();
    }
    return false;
}

void HelloWorld::getImgs(){
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    log("Use android api: Get Album.");
    Global::cleanVector();
    AlbumTest::getAlbum(this);
#endif
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void HelloWorld::finishGetAlbum(){

    int count = Global::g_vector.size();
    
    Label* lbl = (Label*)getChildByTag(LBL);
    char ch[30] = {0};
    sprintf(ch, "%d", count);
    std::string strCount = ch;
    lbl->setString(strCount);
}
#endif

void HelloWorld::sendImg(){
    int count = Global::g_vector.size();
    if(count > 0){
        int index = rand()%count;
        std::string str = Global::g_vector.at(index);
    
        Sprite* bg = (Sprite*)getChildByTag(HOMEBG);
        bg->getTexture()->releaseGLTexture();
        bg->setTexture(str);
    }
}

