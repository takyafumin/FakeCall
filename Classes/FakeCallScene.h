/*
 * CalcScene.h
 *
 *  Created on: 2014/08/28
 *      Author: takyafumin
 */

#ifndef CALCSCENE_H_
#define CALCSCENE_H_

#include "cocos2d.h"


class FakeCallScene: public cocos2d::Layer {

public:

	// コンストラクタ／デストラクタ
	FakeCallScene();
	virtual ~FakeCallScene();

	// 初期化処理
    virtual bool init();

    // TODO
    static cocos2d::Scene* createScene();


    // メニューコールバック
    void menuCloseCallback(cocos2d::Ref* pSender);

    // スケジュール実行処理
    void doScheduleOnceEvent(float frame);

    // Create()
    CREATE_FUNC(FakeCallScene);


protected:

    /** 画面サイズ  */

    /** Tag */
    enum kTag
    {
        kTagBackground = 1,
        kTagGetACall = 2,
        kTagMenuClose = 3,
    };

    /** ZOrder */
    enum kZOrder
    {
        kZOrderBackground,
        kZOrderGetACall,
        kzOrderMenuClose,
    };
};

#endif /* CALCSCENE_H_ */
