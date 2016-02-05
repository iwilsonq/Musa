//
//  Category.hpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef Musa_Category_hpp
#define Musa_Category_hpp

// Entity/scene node category, used to dispatch commands
namespace Category
{
    enum Type
    {
        None				= 0,
        SceneAirLayer       = 1 << 0,
        PlayerAircraft		= 1 << 1,
        AlliedAircraft		= 1 << 2,
        EnemyAircraft		= 1 << 3,
        Pickup				= 1 << 4,
        AlliedProjectile	= 1 << 5,
        EnemyProjectile		= 1 << 6,
        ParticleSystem      = 1 << 7,
        SoundEffect			= 1 << 8,
        Network				= 1 << 9,
        
        Aircraft = PlayerAircraft | AlliedAircraft | EnemyAircraft,
        Projectile = AlliedProjectile | EnemyProjectile,
        
    };
}

#endif
