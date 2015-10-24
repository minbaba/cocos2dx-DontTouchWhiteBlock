#include "HelloWorldScene.h"
#include "Space.h"
#include "GameOverScene.h"

#define ROW_COUNT 4
#define CUL_COUNT 4

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B::YELLOW) )
    {
        return false;
    }
    _score = 0;
    
    //计算方块尺寸
    Size visibleSize = Director::getInstance()->getVisibleSize();
    _spaceWidth = (visibleSize.width - 12) /4;
    _spaceHeight = (visibleSize.height - 12) /4;
    
    for (int i = 0; i <4; i ++) {
        createSpaces(4);
    }
    //添加触摸监听者
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch *touch, Event *event) {
        //判断是否点击了白块
        if (this->isTouchWhiteSpace(touch->getLocation())) {
            char si[80];
            sprintf(si, "得分：%d", _score);
            auto n_scene = GameOver::createScene(si);
            //切换剧场
            Director::getInstance()->replaceScene(TransitionFadeTR::create(1, n_scene));
        }else {
            this->createSpaces(4);
            this->moveSpaces();
            _score ++;
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

#pragma mark - 创造方块
void HelloWorld::createSpaces(int count) {
    //随机选择一个方块 作为黑色方块
    int x = arc4random() %4;
    for (int i = 0; i < count; i++) {
        auto space = Space::create();
        auto posintionX = (_spaces.size() % CUL_COUNT) *(_spaceWidth +4);
        auto posintionY = (_spaces.size() / ROW_COUNT) *(_spaceHeight +4);
        //设置大小和位置
        space->setContentSize(Size(_spaceWidth, _spaceHeight));
        space->setPosition(posintionX, posintionY);
        
        //改变颜色
        if (i == x) {
            space->turnColor();
        }
        //将方块加入数组
        _spaces.pushBack(space);
        addChild(space);
    }
}
#pragma mark - 移动方块位置
void HelloWorld::moveSpaces() {
    int index = 0;
    for (int i = 0; i < _spaces.size() +4; i++) {
        _spaces.at(index)->runAction(MoveBy::create(0.3, Vec2(0, - (_spaceHeight +4))));
        if(i < 4){
            _spaces.erase(0);
            index --;
        }
        index ++;
    }
}
#pragma mark - 判断是否踩了白块
bool HelloWorld::isTouchWhiteSpace(cocos2d::Point p) {
    int row = p.y /_spaceHeight;
    int cul = p.x /_spaceWidth;
    
    if (row >0 || _spaces.at(row *4 +cul)->getColor() != Color3B::BLACK) {
        return true;
    }
    
    return false;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
