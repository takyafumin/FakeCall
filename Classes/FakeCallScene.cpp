/*
 * FakeCallScene.cpp
 *
 *  Created on: 2014/08/28
 *      Author: takyafumin
 */

#include "SimpleAudioEngine.h"
#include "FakeCallScene.h"


/** 画像：背景 */
#define PNG_HOME "home-s.png"
#define PNG_CALL "call-s.png"

/** サウンド */
#define MP3_GET_A_CALL "GetACall.mp3"


// 着信画面表示までの秒数
#define CALL_WAIT_SECOND 5.0f


USING_NS_CC;
using namespace CocosDenshion;


FakeCallScene::FakeCallScene() {
}

FakeCallScene::~FakeCallScene() {
}



/**
 *
 * Scene作成処理
 *
 */
Scene* FakeCallScene::createScene()
{
    auto* scene = Scene::create();
    auto* layer = FakeCallScene::create();
    scene->addChild(layer);
    return scene;
}

/**
 *
 * 初期化処理
 *
 */
bool FakeCallScene::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

    // ------------------------------------------
    // 初期画像表示
    // ------------------------------------------

    // 画面サイズ取得
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    // ホーム画面表示
    auto* pBackground = CCSprite::create(PNG_HOME);
    pBackground->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pBackground, kTagBackground, kZOrderBackground);


    // 終了ボタン表示
    auto closeItem = MenuItemImage::create(
					   "CloseNormal.png",
					   "CloseSelected.png",
					   CC_CALLBACK_1(FakeCallScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, kTagMenuClose, kzOrderMenuClose);


    // コール音プリロード
    SimpleAudioEngine::getInstance()->setEffectsVolume(0.5);
    SimpleAudioEngine::getInstance()->preloadEffect(MP3_GET_A_CALL);


    // タイマーイベントセット
    scheduleOnce(schedule_selector(FakeCallScene::doScheduleOnceEvent), CALL_WAIT_SECOND);


    return true;
}

/**
 * スケジュールイベント（一回のみ）
 */
void FakeCallScene::doScheduleOnceEvent(float frame) {

    // 画面サイズ取得
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 着信画面表示
    auto* calledScene = Sprite::create(PNG_CALL);
    calledScene->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(calledScene, kTagGetACall, kZOrderGetACall);

    // 着信音
    SimpleAudioEngine::getInstance()->playEffect(MP3_GET_A_CALL, false, 1.0f, 0.0f, 1.0f);
}


/**
 * 終了処理
 */
void FakeCallScene::menuCloseCallback(cocos2d::Ref* pSender)
{

	// 着信音停止
	SimpleAudioEngine::getInstance()->stopAllEffects();


	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
		MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	#else
		Director::sharedDirector()->end();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
	#endif
	#endif
}
