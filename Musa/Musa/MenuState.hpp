//
//  MenuState.hpp
//  Musa
//
//  Created by Ian Wilson on 2/4/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__MenuState__
#define __Musa__MenuState__

#include "State.hpp"
#include "Container.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);
    
    virtual void			draw();
    virtual bool			update(sf::Time dt);
    virtual bool			handleEvent(const sf::Event& event);
    
private:
    sf::Sprite				mBackgroundSprite;
    GUI::Container          mGUIContainer;
};

#endif /* defined(__Musa__MenuState__) */
