//
//  Hero.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Hero.hpp"
#include "ResourceHolder.hpp"
#include "Utility.hpp"
#include "CommandQueue.hpp"
#include "DataTables.hpp"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#include <cmath>
#include <iostream>

const sf::Time TimePerSprite = sf::seconds(1.f/4.f);
sf::Time timeSinceLastUpdate;


using namespace std::placeholders;


namespace
{
    const std::vector<HeroData> Table = initializeHeroData();
}

Hero::Hero(Type type, const TextureHolder& textures, const FontHolder& fonts)
: Entity(Table[type].hitpoints)
, mType(type)
, mSprite(textures.get(Table[type].texture), Table[type].textureRect)
, mTravelledDistance(0.f)
, mDirectionIndex(0)
, mCategory(2)
{
    //ADDING SPRITE FRAMES
    Animation walkDown(textures.get(Table[type].texture));
    walkDown.addFramesLine(4, 4, 0);
    Animation walkLeft(textures.get(Table[type].texture));
    walkLeft.addFramesLine(4, 4, 1);
    Animation walkRight(textures.get(Table[type].texture));
    walkRight.addFramesLine(4, 4, 2);
    Animation walkUp(textures.get(Table[type].texture));
    walkUp.addFramesLine(4, 4, 3);
    
    AnimatedSprite sprite(&walkDown, AnimatedSprite::Playing , sf::seconds(0.1));
}

/******************************************************************************************************
 drawCurrent only draws the sprite. We call sf::RenderTarget::draw(), and pass const sf::Drawable& (our sprite) as first argument and the render states as second argument.
 ******************************************************************************************************/
void Hero::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
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
    return getWorldTransform().transformRect(mSprite.getGlobalBounds());
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
    timeSinceLastUpdate += dt;
    
    sf::IntRect textureRect = Table[mType].textureRect;
    
    if (getVelocity().y > 0.f && timeSinceLastUpdate > TimePerSprite)
    {
        textureRect.left += textureRect.width;
        mSprite.setTextureRect(textureRect);
    }
    else if (getVelocity().x < 0.f && timeSinceLastUpdate > TimePerSprite)
    {
        textureRect.top = textureRect.height;
        textureRect.left += textureRect.width;
        mSprite.setTextureRect(textureRect);
    }
    else if (getVelocity().x > 0.f && timeSinceLastUpdate > TimePerSprite)
    {
        textureRect.top = 2 * textureRect.height;
        textureRect.left += textureRect.width;
        mSprite.setTextureRect(textureRect);
    }
    else if (getVelocity().y < 0.f && timeSinceLastUpdate > TimePerSprite)
    {
        textureRect.top = 3 * textureRect.height;
        textureRect.left += textureRect.width;
        mSprite.setTextureRect(textureRect);
    }

    
}


