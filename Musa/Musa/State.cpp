//
//  State.cpp
//  Musa
//
//  Created by Ian Wilson on 2/3/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "State.hpp"
#include "StateStack.hpp"


State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts/*, MusicPlayer& music, SoundPlayer& sounds*/, KeyBinding& keys)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, keys(&keys)
//, music(&music)
//, sounds(&sounds)
{
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
    mStack->pushState(stateID);
}

void State::requestStackPop()
{
    mStack->popState();
}

void State::requestStateClear()
{
    mStack->clearStates();
}

State::Context State::getContext() const
{
    return mContext;
}

void State::onActivate()
{
    
}

void State::onDestroy()
{
    
}
