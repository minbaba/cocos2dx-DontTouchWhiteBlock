//
//  Space.cpp
//  DontTouchWhiteSpace
//
//  Created by dell on 15/8/22.
//
//

#include "Space.h"

USING_NS_CC;

bool Space::init() {
    
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) {
        return false;
    }
    //周期检测是否需要将自己移除父视图
    schedule([this](float t){
        if (this->getPositionY() < -this->getContentSize().height) {
            this->unschedule("delete");
            this->removeFromParent();
        }
    }, 2, "delete");
    
    return true;
}
#pragma mark - 改变颜色
void Space::turnColor() {
    LayerColor::setColor(Color3B::BLACK);
}
