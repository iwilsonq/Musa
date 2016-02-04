//
//  TitleState.hpp
//  Musa
//
//  Created by Ian Wilson on 2/4/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__TitleState__
#define __Musa__TitleState__

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class TitleState : public State
{
public:
    TitleState(StateStack& stack, Context context);
    
    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
    
    
private:
    sf::Sprite			mBackgroundSprite;
    sf::Text			mText;
    
    bool				mShowText;
    sf::Time			mTextEffectTime;
};

#endif /* defined(__Musa__TitleState__) */
