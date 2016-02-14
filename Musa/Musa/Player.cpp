//
//  Player.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Player.hpp"
#include "CommandQueue.hpp"
#include "Hero.hpp"

#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std::placeholders;

struct HeroMover
{
    HeroMover(float vx, float vy)
    : velocity(vx, vy)
    {
    }
    
    void operator() (Hero& hero, sf::Time) const
    {
        hero.accelerate(velocity);
    }
    
    sf::Vector2f velocity;
};

//struct AircraftFireTrigger
//{
//    AircraftFireTrigger(int identifier)
//    : aircraftID(identifier)
//    {
//    }
//    
//    void operator() (Aircraft& aircraft, sf::Time) const
//    {
//        if (aircraft.getIdentifier() == aircraftID)
//            aircraft.fire();
//    }
//    
//    int aircraftID;
//};


Player::Player(const KeyBinding* binding)
: mKeyBinding(binding)
{
    // Set initial action bindings
    initializeActions();
    
    // Assign all categories to player's character
    for(auto& pair : mActionBinding)
    {
        pair.second.category = Category::PlayerHero;
    }
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
    // Event
    if (event.type == sf::Event::KeyPressed)
    {
        Action action;
        if (mKeyBinding && mKeyBinding->checkAction(event.key.code, action) && isRealtimeAction(action))
        {
            commands.push(mActionBinding[action]);
        }
    }
}

void Player::handleRealTimeInput(CommandQueue& commands)
{
    for(auto pair : mActionProxies)
    {
        if (pair.second && isRealtimeAction(pair.first))
            commands.push(mActionBinding[pair.first]);
    }
}

void Player::initializeActions()
{
    mActionBinding[PlayerAction::MoveLeft].action      = derivedAction<Hero>(HeroMover(-1,  0));
    mActionBinding[PlayerAction::MoveRight].action     = derivedAction<Hero>(HeroMover(+1,  0));
    mActionBinding[PlayerAction::MoveUp].action        = derivedAction<Hero>(HeroMover( 0, -1));
    mActionBinding[PlayerAction::MoveDown].action      = derivedAction<Hero>(HeroMover( 0, +1));

}


