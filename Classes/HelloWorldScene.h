#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::LayerColor
{
private:
    cocos2d::Vector<cocos2d::LayerColor *> _spaces;
    int _score;
    float _spaceWidth;
    float _spaceHeight;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    /**创建方块*/
    void createSpaces(int count);
    /**判断是否踩到白块*/
    bool isTouchWhiteSpace(cocos2d::Point p);
    /**移动*/
    void moveSpaces();
};

#endif // __HELLOWORLD_SCENE_H__
