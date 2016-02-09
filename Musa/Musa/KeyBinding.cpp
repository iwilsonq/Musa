//
//  KeyBinding.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "KeyBinding.hpp"

#include <string>
#include <algorithm>


KeyBinding::KeyBinding()
: mKeyMap()
{

    mKeyMap[sf::Keyboard::Left]	 = PlayerAction::MoveLeft;
    mKeyMap[sf::Keyboard::Right] = PlayerAction::MoveRight;
    mKeyMap[sf::Keyboard::Up]    = PlayerAction::MoveUp;
    mKeyMap[sf::Keyboard::Down]  = PlayerAction::MoveDown;

}

void KeyBinding::assignKey(Action action, sf::Keyboard::Key key)
{
    // Remove all keys that already map to action
    for (auto itr = mKeyMap.begin(); itr != mKeyMap.end(); )
    {
        if (itr->second == action)
            mKeyMap.erase(itr++);
        else
            ++itr;
    }
    
    // Insert new binding
    mKeyMap[key] = action;
}

sf::Keyboard::Key KeyBinding::getAssignedKey(Action action) const
{
    for (auto pair : mKeyMap)
    {
        if (pair.second == action)
            return pair.first;
    }
    
    return sf::Keyboard::Unknown;
}

bool KeyBinding::checkAction(sf::Keyboard::Key key, Action& out) const
{
    auto found = mKeyMap.find(key);
    if (found == mKeyMap.end())
    {
        return false;
    }
    else
    {
        out = found->second;
        return true;
    }
}

std::vector<KeyBinding::Action> KeyBinding::getRealtimeActions() const
{
    // Return all realtime actions that are currently active.
    std::vector<Action> actions;
    
    for(auto pair : mKeyMap)
    {
        // If key is pressed and an action is a realtime action, store it
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            actions.push_back(pair.second);
    }
    
    return actions;
}

bool isRealtimeAction(PlayerAction::Type action)
{
    switch (action)
    {
        case PlayerAction::MoveLeft:
        case PlayerAction::MoveRight:
        case PlayerAction::MoveDown:
        case PlayerAction::MoveUp:
            return true;
            
        default:
            return false;
    }
}

