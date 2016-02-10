//
//  AnimatedSprite.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "AnimatedSprite.hpp"
#include "Animation.hpp"

#include <cassert>
AnimatedSprite::FuncType AnimatedSprite::defaultFunc = []()->void{};

AnimatedSprite::AnimatedSprite(Animation* animation,Status status,const sf::Time& deltaTime,bool loop,int repeat) :
on_finished(defaultFunc),
mAnimation(nullptr),
mDelta(deltaTime),
mLoop(loop),
mRepeat(repeat),
mStatus(status)
{
    setAnimation(animation);
}

void AnimatedSprite::setAnimation(Animation* animation)
{
    if(mAnimation != animation)
    {
        mAnimation = animation;
        mElapsed = sf::Time::Zero;
        mCurrentFrame = 0;
        setFrame(0,true);
        setTexture(mAnimation->getTexture());
    }
}

Animation* AnimatedSprite::getAnimation()const
{
    return mAnimation;
}

void AnimatedSprite::setFrameTime(sf::Time deltaTime)
{
    mDelta = deltaTime;
}

sf::Time AnimatedSprite::getFrameTime()const
{
    return mDelta;
}

void AnimatedSprite::setLoop(bool loop)
{
    mLoop = loop;
}

bool AnimatedSprite::getLoop()const
{
    return mLoop;
}
void AnimatedSprite::setRepeate(int nb)
{
    mRepeat = nb;
}

int AnimatedSprite::getRepeate()const
{
    return mRepeat;
}

void AnimatedSprite::play()
{
    mStatus = Playing;
}
void AnimatedSprite::pause()
{
    mStatus = Paused;
}

void AnimatedSprite::stop()
{
    mStatus = Stopped;
    mCurrentFrame = 0;
    setFrame(0,true);
}

AnimatedSprite::Status AnimatedSprite::getStatus()const
{
    return mStatus;
}

void AnimatedSprite::setFrame(size_t index)
{
    assert(mAnimation);
    mCurrentFrame = index % mAnimation->size();
    setFrame(mCurrentFrame,true);
}

void AnimatedSprite::update(const sf::Time& deltaTime)
{
    if(mStatus == Playing and mAnimation)
    {
        mElapsed += deltaTime;
        if(mElapsed > mDelta)
        {
            mElapsed -= mDelta;
            if(mCurrentFrame + 1 < mAnimation->size())
                ++mCurrentFrame;
            else
            {
                mCurrentFrame = 0;
                if(not mLoop)
                {
                    --mRepeat;
                    if(mRepeat<=0)
                    {
                        mStatus = Stopped;
                        on_finished();
                    }
                }
            }
        }
        setFrame(mCurrentFrame,false);
    }
}

void AnimatedSprite::setFrame(size_t index,bool resetTime)
{
    if(mAnimation)
    {
        sf::IntRect rect = mAnimation->getRect(index);
        setTextureRect(rect);
    }
    
    if(resetTime)
        mElapsed = sf::Time::Zero;
}
