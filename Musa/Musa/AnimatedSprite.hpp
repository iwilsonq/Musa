//
//  AnimatedSprite.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__AnimatedSprite__
#define __Musa__AnimatedSprite__

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <functional>

class Animation;
class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite(const AnimatedSprite&) = default;
    AnimatedSprite& operator=(const AnimatedSprite&) = default;
    
    AnimatedSprite(AnimatedSprite&&) = default;
    AnimatedSprite& operator=(AnimatedSprite&&) = default;
    
    using FuncType = std::function<void()>;
    static FuncType     defaultFunc;
    
    enum Status
    {
        Stopped,
        Paused,
        Playing
    };
    
    AnimatedSprite(Animation* animation = nullptr,Status status= Playing,const sf::Time& deltaTime = sf::seconds(0.15),bool loop = true,int repeat=0);
    
    void                setAnimation(Animation* animation);
    Animation*          getAnimation()const;
    
    void                setFrameTime(sf::Time deltaTime);
    sf::Time            getFrameTime()const;
    
    void                setLoop(bool loop);
    bool                getLoop()const;
    
    void                setRepeate(int nb);
    int                 getRepeate()const;
    
    void                play();
    void                pause();
    void                stop();
    
    FuncType            on_finished;
    
    Status              getStatus()const;
    
    void                setFrame(size_t index);
    
    void                update(const sf::Time& deltaTime);
    
private:
    Animation*          mAnimation;
    sf::Time            mDelta;
    sf::Time            mElapsed;
    bool                mLoop;
    int                 mRepeat;
    Status              mStatus;
    size_t              mCurrentFrame;
    
    void                setFrame(size_t index,bool resetTime);
};


#endif /* defined(__Musa__AnimatedSprite__) */
