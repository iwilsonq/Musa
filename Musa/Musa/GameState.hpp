//
//  GameState.hpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__GameState__
#define __Musa__GameState__

#include "State.hpp"
#include "World.hpp"
#include "Player.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


// The gamestate is in charge of managing the game world
// and the player after it is pushed from the menu interface

class GameState : public State
{
public:
    GameState(StateStack& stack, Context context);
    
    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
    
    
private:
    World				mWorld;
    Player				mPlayer;
};


#endif /* defined(__Musa__GameState__) */
