//
//  Random.hpp
//  Musa
//
//  Created by Ian Wilson on 2/14/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef Musa_Random_hpp
#define Musa_Random_hpp

#include <cstdlib>
#include <ctime>
#include <random>

extern std::default_random_engine generator;

inline void rand_init()
{
    srand(time(NULL));
    
};

inline float random(float min,float max)
{
    return (rand()/float(RAND_MAX))*(max-min) + min;
}

inline int random(int min,int max)
{
    return rand()%(max-min+1) + min;
}


#endif
