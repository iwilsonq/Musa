//
//  Animation.hpp
//  Musa
//
//  Created by Ian Wilson on 2/6/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Animation__
#define __Musa__Animation__

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Noncopyable.hpp>


#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
public:
    Animation();
    
    void addFrame(sf::IntRect rect);
    void addFrameLine(int numFrames_x, int numFrames_y, int line);
    void setSpriteSheet(const sf::Texture& texture);
    const sf::Texture* getSpriteSheet() const;
    std::size_t getSize() const;
    const sf::IntRect& getFrame(std::size_t n) const;
    
private:
    std::vector<sf::IntRect> mFrames;
    const sf::Texture* mTexture;
};


#endif /* defined(__Musa__Animation__) */
