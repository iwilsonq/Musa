//
//  DataTables.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__DataTables__
#define __Musa__DataTables__

#include "ResourceIdentifiers.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <functional>

struct Direction
{
    Direction(float angle, float distance)
    : angle(angle)
    , distance(distance)
    {
    }
    
    float angle;
    float distance;
};


struct HeroData
{
    int								hitpoints;
    float							speed;
    Textures::ID					texture;
    sf::IntRect						textureRect;
};

struct NPCData
{
    int                             hitpoints;
    float                           speed;
    Textures::ID                    texture;
    sf::IntRect                     textureRect;
};

std::vector<HeroData>	initializeHeroData();
std::vector<NPCData>    initializeNPCData();

#endif /* defined(__Musa__DataTables__) */
