//
//  ResourseIdentifiers.hpp
//  Musa
//
//  Created by Ian Wilson on 2/3/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef Musa_ResourceIdentifiers_hpp
#define Musa_ResourceIdentifiers_hpp

namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {
        Desert,
        TitleScreen,
        Buttons,
        Auron,
        Guy,
        Samurai2,
        Samurai3,
    };
}


namespace Fonts
{
    enum ID
    {
        Main,
    };
}


// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>   TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>         FontHolder;



#endif
