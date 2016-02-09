//
//  Application.cpp
//  Musa
//
//  Created by Ian Wilson on 2/3/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Application.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "TitleState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"


#include <SFML/Window.hpp>

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(1024, 568), "Hello Musa", sf::Style::Close)
, mStateStack(State::Context(mWindow, mTextures, mFonts, mKeyBinding))
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
    mWindow.setVerticalSyncEnabled(true);
    mWindow.setKeyRepeatEnabled(false);
    
    mFonts.load(Fonts::Main, "Media/Fonts/Sansation.ttf");
    
    mTextures.load(Textures::TitleScreen, "Media/Textures/samurai.png");
    
    mTextures.load(Textures::Buttons, "Media/Textures/Buttons.png");
    
    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    mStateStack.pushState(States::Title);
}

void Application::run()     //Game Loop
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    
    while(mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processInput();
            update(TimePerFrame);
            
            if(mStateStack.isEmpty())
                mWindow.close();
        }
        render();
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);                 //State stack updates
}                                           //Stack is integral to procedure of game loop

void Application::processInput()
{
    sf::Event event;
    
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);     //State stack handles the input
        
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::render()
{
    mWindow.clear();
    mStateStack.draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Application::registerStates()
{
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);

}


