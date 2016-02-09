//
//  KeyBinding.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__KeyBinding__
#define __Musa__KeyBinding__

#include <SFML/Window/Keyboard.hpp>

#include <map>
#include <vector>


namespace PlayerAction
{
    enum Type
    {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        Count
    };
}

class KeyBinding
{
public:
    typedef PlayerAction::Type Action;
    
    
public:
    explicit				KeyBinding();
    
    void					assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key		getAssignedKey(Action action) const;
    
    bool					checkAction(sf::Keyboard::Key key, Action& out) const;
    std::vector<Action>		getRealtimeActions() const;
    
    
private:
    void					initializeActions();
    
    
private:
    std::map<sf::Keyboard::Key, Action>		mKeyMap;
};

bool					isRealtimeAction(PlayerAction::Type action);

#endif /* defined(__Musa__KeyBinding__) */
