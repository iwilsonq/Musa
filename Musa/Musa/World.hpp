//
//  World.hpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__World__
#define __Musa__World__

#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "CommandQueue.hpp"
#include "Command.hpp"
#include "Hero.hpp"
#include "Animation.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
    class RenderWindow;
}


class World : private sf::NonCopyable
{
public:
    World(sf::RenderTarget& outputTarget, FontHolder& fonts);
    
    void								update(sf::Time dt);
    void								draw();
    
    Hero*                               addHero();
    
    sf::FloatRect						getViewBounds() const;
    CommandQueue&						getCommandQueue();
    void								setWorldHeight(float height);
    sf::FloatRect						getBattlefieldBounds() const;
    void								setCurrentBattleFieldPosition(float lineY);
    
private:
    void								loadTextures();
    void								adaptPlayerPosition();
    void								adaptPlayerVelocity();
    void								handleCollisions();
    
    void								buildScene();

    
    
private:
    enum Layer
    {
        Background,
        Ground,
        Air,
        LayerCount
    };
    
    struct SpawnPoint
    {
        SpawnPoint(Hero::Type type, float x, float y)
        : type(type)
        , x(x)
        , y(y)
        {
        }
    
        Hero::Type type;
        float x;
        float y;
    };
    
    
private:
    sf::RenderTarget&					mTarget;
    sf::RenderTexture					mSceneTexture;
    sf::View							mWorldView;
    TextureHolder						mTextures;
    FontHolder&							mFonts;
    
    SceneNode							mSceneGraph;
    std::array<SceneNode*, LayerCount>	mSceneLayers;
    CommandQueue						mCommandQueue;
    
    sf::FloatRect						mWorldBounds;
    sf::Vector2f						mSpawnPosition;
    std::vector<Hero*>                  mPlayerHeros;
    
    SpriteNode*							mFinishSprite;
    
};

#endif // BOOK_WORLD_HPP


#endif /* defined(__Musa__World__) */
