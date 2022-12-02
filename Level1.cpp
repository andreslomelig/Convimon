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

#include "AudioEngine.h"
#include "HelloWorldScene.h"


USING_NS_CC;

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Level1::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto musicVol = 1.0f;
    auto gameAudioProfile = cocos2d::AudioEngine::INVALID_AUDIO_ID;

    if (gameAudioProfile == cocos2d::AudioEngine::INVALID_AUDIO_ID) {
        gameAudioProfile = cocos2d::AudioEngine::play2d("musica/pokemon-diamond-pearl-platinum-champion-cynthia-battle-music-hq.mp3", true, musicVol);
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto fondo = Sprite::create("20102 (2).png");
    if (fondo == nullptr)
    {
        problemLoading("20102 (2).png'");
    }
    else
    {
        fondo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
        this->addChild(fondo, 0);
    }

    auto esp = Sprite::create("20102.png");
    if (esp == nullptr)
    {
        problemLoading("20102.png'");
    }
    else
    {
        esp->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 10));
        this->addChild(esp, 0);
    }

    auto tex = Sprite::create("6962.png");
    if (tex == nullptr)
    {
        problemLoading("6962.png'");
    }
    else
    {
        tex->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 135));
        this->addChild(tex, 0);
    }

    auto scaleBy = ScaleBy::create(0.0f, 1.6f, 1.0f);
    tex->runAction(scaleBy);


    auto sprite = Sprite::create("68.png");
    if (sprite == nullptr)
    {
        problemLoading("'68.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x + 90, visibleSize.height / 2 + origin.y + 50));

        this->addChild(sprite, 0);
    }
    Vector<SpriteFrame*> animFrames;
    animFrames.reserve(2);
    animFrames.pushBack(SpriteFrame::create("68.png", Rect(0, 0, 160, 160)));
    animFrames.pushBack(SpriteFrame::create("68 (1).png", Rect(0, 0, 160, 160)));

    Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
    Animate* animate = Animate::create(animation);

    sprite->runAction(RepeatForever::create(animate));

    auto pokI = Sprite::create("Charmander_espalda_G4_variocolor.png");
    if (pokI == nullptr)
    {
        problemLoading("'Charmander_espalda_G4_variocolor.png'");
    }
    else
    {
        pokI->setPosition(Vec2(visibleSize.width / 2 + origin.x - 90, visibleSize.height / 2 + origin.y - 50));

        this->addChild(pokI, 0);
    }
    Vector<SpriteFrame*> pokiFrames;
    pokiFrames.reserve(2);
    pokiFrames.pushBack(SpriteFrame::create("Charmander_espalda_G4_variocolor.png", Rect(0, 0, 160, 160)));
    pokiFrames.pushBack(SpriteFrame::create("Charmander_espalda_G4_variocolor_2.png", Rect(0, 0, 160, 160)));

    Animation* animation1 = Animation::createWithSpriteFrames(pokiFrames, 0.6f);
    Animate* animate1 = Animate::create(animation1);

    pokI->runAction(RepeatForever::create(animate1));
    return true;





}



void Level1::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();


}
