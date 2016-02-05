//
//  SpriteNode.hpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__SpriteNode__
#define __Musa__SpriteNode__

#include "SceneNode.hpp"

#include <SFML/Graphics/Sprite.hpp>


class SpriteNode : public SceneNode
{
public:
    explicit			SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
    
    
private:
    virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    
    
private:
    sf::Sprite			mSprite;
};


#endif /* defined(__Musa__SpriteNode__) */
