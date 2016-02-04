//
//  Button.hpp
//  Musa
//
//  Created by Ian Wilson on 2/4/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Button__
#define __Musa__Button__

#include "Component.hpp"
#include "ResourceIdentifiers.hpp"
#include "State.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


class SoundPlayer;

namespace GUI
{
    
    class Button : public Component
    {
    public:
        typedef std::shared_ptr<Button>		Ptr;
        typedef std::function<void()>		Callback;
        
        enum Type
        {
            Normal,
            Selected,
            Pressed,
            ButtonCount
        };
        
    public:
        Button(State::Context context);
        
        void					setCallback(Callback callback);
        void					setText(const std::string& text);
        void					setToggle(bool flag);
        
        virtual bool			isSelectable() const;
        virtual void			select();
        virtual void			deselect();
        
        virtual void			activate();
        virtual void			deactivate();
        
        virtual void			handleEvent(const sf::Event& event);
        
        
    private:
        virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void					changeTexture(Type buttonType);
        
        
        
    private:
        Callback				mCallback;
        sf::Sprite				mSprite;
        sf::Text				mText;
        bool					mIsToggle;
    };
    
}



#endif /* defined(__Musa__Button__) */
