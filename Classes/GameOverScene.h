//
//  GameOverScene.h
//  NoOneDies
//
//  Created by dell on 15/8/21.
//
//

#ifndef __NoOneDies__GameOverScene__
#define __NoOneDies__GameOverScene__

#include <cocos2d.h>

class GameOver:cocos2d::Layer {
private:
    std::string *_scoreInfo;
public:
    /**设置得分信息*/
    void setScoreInfo(const std::string & scoreInfo);
    /**初始化方法*/
    virtual bool init();
    /**创造方法*/
    CREATE_FUNC(GameOver);
    /**创造场景*/
    static cocos2d::Scene * createScene(const std::string &scoreInfo);
};

#endif /* defined(__NoOneDies__GameOverScene__) */
