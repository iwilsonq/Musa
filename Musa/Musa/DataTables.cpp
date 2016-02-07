//
//  DataTables.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "DataTables.hpp"
#include "Hero.hpp"

using namespace std::placeholders;

std::vector<HeroData> initializeHeroData()  // Creating basic stats
{
    std::vector<HeroData> data(Hero::TypeCount);
    
    data[Hero::Musa].hitpoints = 100;
    data[Hero::Musa].speed = 200.f;
    data[Hero::Musa].texture = Textures::Auron;
    data[Hero::Musa].textureRect = sf::IntRect(0, 0, 32, 48);

    
    return data;
}
