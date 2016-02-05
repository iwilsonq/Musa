//
//  SpriteNode.cpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "SpriteNode.hpp"

#include <SFML/Graphics/RenderTarget.hpp>


SpriteNode::SpriteNode(const sf::Texture& texture)
: mSprite(texture)
{
}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect)
: mSprite(texture, textureRect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}