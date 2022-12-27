/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init())
    {
        return false;
    }
    sprite1 = Sprite::create("images/fondo.png");
    sprite1->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite1, 0);

    auto direction = Director::getInstance();
    auto toman = direction->getWinSize();

    sprite = Sprite::create("images/conejo.png");
    sprite->setPosition(Vec2(toman.width/ 2, toman.height*0.15));
    this->addChild(sprite, 1);
    this->intial();
    //this->scheduleUpdate();
    return true;
}
void HelloWorld::mover(Touch* toque, Event* evento)
{
    auto positionTo = toque -> getLocation();
    if (sprite->getBoundingBox().containsPoint(positionTo))
    {
        sprite->setPosition(positionTo.x,positionTo.y);
    }
}
void HelloWorld::intial() 
{
    auto list = EventListenerTouchOneByOne::create();
    list->onTouchBegan = [](Touch* touch, Event* event) { return true; };
    list->onTouchMoved = CC_CALLBACK_2(HelloWorld::mover, this);
    list->onTouchEnded = [=](Touch* touch, Event* event) {};
    _eventDispatcher->addEventListenerWithSceneGraphPriority(list, this);
}
/*void HelloWorld::update(float delta) {
    auto position = sprite->getPosition();
    position.x += 75 * delta;
    if (position.x < 0 + (sprite->getBoundingBox().size.width / 2)) {
        position.x = this->getBoundingBox().getMinX() + sprite->getBoundingBox().size.width / 2;
    }
    sprite->setPosition(position);
}*/
