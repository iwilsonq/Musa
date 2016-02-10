//
//  Hero.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Hero__
#define __Musa__Hero__

#include "Entity.hpp"
#include "Command.hpp"
#include "ResourceIdentifiers.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

#include <SFML/Graphics/Sprite.hpp>


class Hero : public Entity
{
public:
    enum Type
    {
        Musa,
        TypeCount,
    };
    
public:
    Hero(Type type, const TextureHolder& textures, const FontHolder& fonts);
    
    virtual unsigned int	getCategory() const;
    virtual sf::FloatRect	getBoundingRect() const;
    virtual void			remove();
    virtual bool 			isMarkedForRemoval() const;
    float					getMaxSpeed() const;

    
private:
    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
    void					updateMovementPattern(sf::Time dt);
    void                    updateMoveAnimation(sf::Time dt);
    
    
private:
    Type                    mType;
    sf::Sprite				mSprite;
    
    float					mTravelledDistance;
    std::size_t				mDirectionIndex;
    unsigned int            mCategory;
    
};


#endif /* defined(__Musa__Hero__) */
