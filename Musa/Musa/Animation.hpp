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


class Animation : private sf::NonCopyable
{
public:
    Animation(const sf::Texture& texture);
    ~Animation();
    
    void                     setTexture(sf::Texture* texture);
    sf::Texture              getTexture()const;
    
    Animation&               addFrame(const sf::IntRect& rect);
    Animation&               addFramesLine(int number_x,int number_y,int line);
    Animation&               addFramesColumn(int number_x,int number_y,int column);
    
    size_t                   size()const;
    const sf::IntRect&       getRect(size_t index)const;
    
private:
    friend class             AnimatedSprite;
    std::vector<sf::IntRect> mFrames;
    sf::Texture              mTexture;
    
};

#endif /* defined(__Musa__Animation__) */
