//
//  Space.h
//  DontTouchWhiteSpace
//
//  Created by dell on 15/8/22.
//
//

#ifndef __DontTouchWhiteSpace__Space__
#define __DontTouchWhiteSpace__Space__

#include <cocos2d.h>

class Space:public cocos2d::LayerColor {
//private:
//    bool _isBlack;
public:
    /**初始化方法*/
    virtual bool init();
    /**创造方法*/
    CREATE_FUNC(Space);
    /**改变颜色*/
    void turnColor();
};


#endif /* defined(__DontTouchWhiteSpace__Space__) */
