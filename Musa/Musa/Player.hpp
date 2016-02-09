//
//  Player.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Player__
#define __Musa__Player__

#include "KeyBinding.hpp"
#include "Command.hpp"
#include "Hero.hpp"

#include <SFML/System.hpp>

class CommandQueue;
class Player : private sf::NonCopyable
{
public:
    typedef PlayerAction::Type Action;
    
public:
    Player(const KeyBinding* binding);
    void handleEvent(const sf::Event& event, CommandQueue& command);
    void handleRealTimeInput(CommandQueue& command);
    
private:
    void initializeActions();
    
private:
    const KeyBinding*           mKeyBinding;
    std::map<Action, Command>   mActionBinding;
    std::map<Action, bool>      mActionProxies;
    
    
};



#endif /* defined(__Musa__Player__) */
