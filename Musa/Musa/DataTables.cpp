//
//  DataTables.cpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "DataTables.hpp"
#include "Hero.hpp"
#include "NPC.hpp"

using namespace std::placeholders;

std::vector<HeroData> initializeHeroData()  // Creating basic stats
{
    std::vector<HeroData> data(Hero::TypeCount);
    
    data[Hero::Musa].hitpoints = 100;
    data[Hero::Musa].speed = 80.f;
    data[Hero::Musa].texture = Textures::Auron;
    data[Hero::Musa].textureRect = sf::IntRect(0, 0, 24, 32);

    
    return data;
}

std::vector<NPCData> initializeNPCData()
{
    std::vector<NPCData> data(NPC::TypeCount);
    
    data[NPC::Samurai2].hitpoints = 10;
    data[NPC::Samurai2].speed = 60.f;
    data[NPC::Samurai2].texture = Textures::Samurai2;
    data[NPC::Samurai2].textureRect = sf::IntRect(0, 0, 24, 32);
    
    data[NPC::Samurai3].hitpoints = 10;
    data[NPC::Samurai3].speed = 60.f;
    data[NPC::Samurai3].texture = Textures::Samurai3;
    data[NPC::Samurai3].textureRect = sf::IntRect(0, 0, 24, 32);
    
    return data;

}