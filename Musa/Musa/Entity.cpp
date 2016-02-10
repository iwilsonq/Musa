//
//  Entity.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Entity.hpp"

#include <cassert>
#include <iostream>

Entity::Entity(int hitpoints)
: mVelocity()
, mHitpoints(hitpoints)
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}

void Entity::accelerate(sf::Vector2f velocity)
{
    mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
    mVelocity.x += vx;
    mVelocity.y += vy;
}

int Entity::getHitpoints() const
{
    return mHitpoints;
}

void Entity::setHitpoints(int points)
{
    assert(points > 0);
    mHitpoints = points;
}

void Entity::damage(int points)
{
    assert(points > 0);
    
    mHitpoints -= points;
}

void Entity::destroy()
{
    mHitpoints = 0;
}

void Entity::remove()
{
    destroy();
}

bool Entity::isDestroyed() const
{
    return mHitpoints <= 0;
}
/***************************************************************************
 This function uses the time step multiplied by the current velocity to determine how
 far to move the entity
 ***************************************************************************/

void Entity::updateCurrent(sf::Time dt, CommandQueue&)
{
    move(mVelocity * dt.asSeconds());
}

