//
//  Application.hpp
//  Musa
//
//  Created by Ian Wilson on 2/3/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Application__
#define __Musa__Application__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "StateStack.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class Application
{
    
public:
    Application();
    void					run();
    
    
private:
    void					processInput();
    void					update(sf::Time dt);
    void					render();
    
    void					updateStatistics(sf::Time dt);
    void					registerStates();

private:
    static const sf::Time	TimePerFrame;
    
    sf::RenderWindow        mWindow;
    StateStack              mStateStack;
    TextureHolder           mTextures;
    FontHolder              mFonts;
    
    sf::Text				mStatisticsText;
    sf::Time				mStatisticsUpdateTime;
    std::size_t				mStatisticsNumFrames;


    
};


#endif /* defined(__Musa__Application__) */
