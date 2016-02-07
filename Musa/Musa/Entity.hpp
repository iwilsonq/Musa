//
//  Entity.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Entity__
#define __Musa__Entity__

#include "SceneNode.hpp"


class Entity : public SceneNode
{
public:
    explicit            Entity(int hitpoints);
    
    void                damage(int points);
    void                destroy();
    virtual void		remove();
    int                 getHitpoints() const;
    void				setHitpoints(int points);
    virtual bool        isDestroyed() const;
    
    
    void				setVelocity(sf::Vector2f velocity);
    void				setVelocity(float vx, float vy);
    void				accelerate(sf::Vector2f velocity);
    void				accelerate(float vx, float vy);
    sf::Vector2f		getVelocity() const;
    
    
protected:
    virtual void		updateCurrent(sf::Time dt, CommandQueue& commands);
    
private:
    int                 mHitpoints;
    sf::Vector2f		mVelocity;
};


#endif /* defined(__Musa__Entity__) */
