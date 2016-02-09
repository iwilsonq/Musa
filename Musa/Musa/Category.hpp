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
        PlayerHero          = 1 << 1,
        AlliedNPC           = 1 << 2,
        EnemyNPC            = 1 << 3,
        Pickup				= 1 << 4,
        
        Hero = PlayerHero | AlliedNPC | EnemyNPC,
        
    };
}

#endif
