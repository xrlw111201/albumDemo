//
//  AlbumTest.cpp
//  albumDemo
//
//  Created by liuhui on 16/4/6.
//
//


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <cocos2d.h>
#include "AlbumTest.h"
#include "Global.h"

USING_NS_CC;


void AlbumTest::getAlbum(AlbumTestDelegate* _delegate){

    jobject obj;
    jobjectArray strArray;
    JniMethodInfo minfo;
    bool b = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/cpp/AppActivity", "getImages", "()[Ljava/lang/String;");
    
    if(b){
        obj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
        
        minfo.env->DeleteLocalRef(minfo.classID);   //务必释放
        
        strArray = (jobjectArray)obj;
        int len = minfo.env->GetArrayLength(strArray);

        std::string strPath;

        for(int i=0; i<len; i++){
            
            jstring jstr = (jstring)(minfo.env->GetObjectArrayElement(strArray, i));
            
            strPath = JniHelper::jstring2string(jstr);
            
            minfo.env->DeleteLocalRef(jstr);    //务必释放
            
            if("error" != strPath){
                Global::g_vector.push_back(strPath);
            }
        }
        minfo.env->DeleteLocalRef(obj); //务必释放

        _delegate->finishGetAlbum();
    }
}

//multiMethod.env->DeleteLocalRef(multiMethod.classID);


#endif