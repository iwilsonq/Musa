//
//  NPC.hpp
//  Musa
//
//  Created by Ian Wilson on 2/13/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__NPC__
#define __Musa__NPC__

#include "Entity.hpp"
#include "Command.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

#include <SFML/Graphics/Sprite.hpp>

class NPC : public Entity
{
public:
    enum Type
    {
        Samurai2,
        Samurai3,
        TypeCount,
    };
    
public:
    NPC(Type type, sf::Texture texture, const FontHolder& fonts);
    
    virtual unsigned int	getCategory() const;
    virtual sf::FloatRect	getBoundingRect() const;
    virtual void			remove();
    virtual bool 			isMarkedForRemoval() const;
    
private:
    virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
    void					updateMovementPattern(sf::Time dt);
    void                    updateMoveAnimation(sf::Time dt);
    
private:
    Type                    mType;
    AnimatedSprite          mAnimatedSprite;
    Animation*              mCurrentAnimation;
    sf::Texture             mTexture;
    
    float					mTravelledDistance;
    std::size_t				mDirectionIndex;
    unsigned int            mCategory;
    
    
};

#endif /* defined(__Musa__NPC__) */
