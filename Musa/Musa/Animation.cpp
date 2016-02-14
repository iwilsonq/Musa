//
//  Animation.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation()
: mTexture(nullptr)
{
    
}

void Animation::addFrame(sf::IntRect rect)
{
    mFrames.push_back(rect);
}

void Animation::addFrameLine(int numFrames_x, int numFrames_y, int line)
{
    const sf::Vector2u size = mTexture->getSize();
    const float delta_x = size.x / float(numFrames_x);
    const float delta_y = size.y / float(numFrames_y);
    
    for(int i = 0; i< numFrames_x; ++i)
        addFrame(sf::IntRect(i*delta_x, line*delta_y, delta_x, delta_y));
}

void Animation::setSpriteSheet(const sf::Texture& texture)
{
    mTexture = &texture;
}

const sf::Texture* Animation::getSpriteSheet() const
{
    return mTexture;
}

std::size_t Animation::getSize() const
{
    return mFrames.size();
}

const sf::IntRect& Animation::getFrame(std::size_t n) const
{
    return mFrames[n];
}