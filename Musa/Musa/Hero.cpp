//
//  Hero.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Hero.hpp"
#include "Utility.hpp"
#include "CommandQueue.hpp"
#include "DataTables.hpp"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#include <cmath>
#include <iostream>

using namespace std::placeholders;


namespace
{
    const std::vector<HeroData> Table = initializeHeroData();
}

Hero::Hero(Type type, const TextureHolder& textures, const FontHolder& fonts)
: Entity(Table[type].hitpoints)
, mType(type)
, mAnimatedSprite(sf::seconds(0.2), true, false)
, mCurrentAnimation(nullptr)
, mTexture(textures.get(Textures::Auron))
, mTravelledDistance(0.f)
, mDirectionIndex(0)
, mCategory(2)
{
    
}

/******************************************************************************************************
 drawCurrent only draws the sprite. We call sf::RenderTarget::draw(), and pass const sf::Drawable& (our sprite) as first argument and the render states as second argument.
 ******************************************************************************************************/
void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mAnimatedSprite, states);
}

unsigned int Hero::getCategory() const
{
    return mCategory;
}

void Hero::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    updateMoveAnimation(dt);
    Entity::updateCurrent(dt, commands);
}

sf::FloatRect Hero::getBoundingRect() const
{
    return getWorldTransform().transformRect(mAnimatedSprite.getGlobalBounds());
}

bool Hero::isMarkedForRemoval() const
{
    
}

void Hero::remove()
{
    Entity::remove();
}


float Hero::getMaxSpeed() const
{
    return Table[mType].speed;
}


void Hero::updateMoveAnimation(sf::Time dt)
{
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(mTexture);
    walkingAnimationDown.addFrameLine(4, 4, 0);
    
    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(mTexture);
    walkingAnimationLeft.addFrameLine(4, 4, 1);
    
    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(mTexture);
    walkingAnimationRight.addFrameLine(4, 4, 2);
    
    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(mTexture);
    walkingAnimationUp.addFrameLine(4, 4, 3);
    
    mCurrentAnimation = &walkingAnimationDown;
    
    bool noKeyWasPressed = true;
    
    
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        mCurrentAnimation = &walkingAnimationUp;
        movement.y -= Table[mType].speed;
        noKeyWasPressed = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        mCurrentAnimation = &walkingAnimationDown;
        movement.y += Table[mType].speed;
        noKeyWasPressed = false;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        mCurrentAnimation = &walkingAnimationLeft;
        movement.x -= Table[mType].speed;
        noKeyWasPressed = false;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mCurrentAnimation = &walkingAnimationRight;
        movement.x += Table[mType].speed;
        noKeyWasPressed = false;
    }
    
    mAnimatedSprite.play(*mCurrentAnimation);
    mAnimatedSprite.move(movement * dt.asSeconds());
    
    // if no key was pressed stop the animation
    if (noKeyWasPressed)
    {
        mAnimatedSprite.stop();
    }
    noKeyWasPressed = true;
    
    mAnimatedSprite.update(dt);
    
}
