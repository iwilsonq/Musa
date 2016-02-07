//
//  Animation.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation(sf::Texture* texture)
: mTexture(texture)
{
}

Animation::~Animation()
{
}

void Animation::setTexture(sf::Texture* texture)
{
    mTexture = texture;
}

sf::Texture* Animation::getTexture() const
{
    return mTexture;
}

Animation& Animation::addFrame(const sf::IntRect& rect)
{
    mFrames.emplace_back(rect);
    return *this;
}

Animation& Animation::addFramesLine(int number_x,int number_y,int line)
{
    const sf::Vector2u size = mTexture->getSize();
    const float delta_x = size.x / float(number_x);
    const float delta_y = size.y / float(number_y);
    
    for(int i = 0;i<number_x;++i)
        addFrame(sf::IntRect(i*delta_x,
                             line*delta_y,
                             delta_x,
                             delta_y));
    return *this;
}

Animation& Animation::addFramesColumn(int number_x,int number_y,int column)
{
    const sf::Vector2u size = mTexture->getSize();
    const float delta_x = size.x / float(number_x);
    const float delta_y = size.y / float(number_y);
    
    for(int i = 0;i<number_y;++i)
        addFrame(sf::IntRect(column*delta_x,
                             i*delta_y,
                             delta_x,
                             delta_y));
    return *this;
}

size_t Animation::size() const
{
    return mFrames.size();
}

const sf::IntRect& Animation::getRect(size_t index)const
{
    return mFrames[index];
}
