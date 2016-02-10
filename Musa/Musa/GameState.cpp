//
//  GameState.cpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "GameState.hpp"
//#include "MusicPlayer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mWorld(*context.window, *context.fonts)
, mPlayer(context.keys)
{
    mWorld.addHero();

}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleRealTimeInput(commands);
    mWorld.update(dt);
    
 
    
    
    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    // Game input handling
    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleEvent(event, commands);
    
    // Escape pressed, trigger the pause screen
//    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//        requestStackPush(States::Pause);
    
    return true;
}