//
//  Container.hpp
//  Musa
//
//  Created by Ian Wilson on 2/4/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__Container__
#define __Musa__Container__

#include "Component.hpp"

#include <vector>
#include <memory>


namespace GUI
{
    
    class Container : public Component
    {
    public:
        typedef std::shared_ptr<Container> Ptr;
        
        
    public:
        Container();
        
        void				pack(Component::Ptr component);
        
        virtual bool		isSelectable() const;
        virtual void		handleEvent(const sf::Event& event);
        
        
    private:
        virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
        bool				hasSelection() const;
        void				select(std::size_t index);
        void				selectNext();
        void				selectPrevious();
        
        
    private:
        std::vector<Component::Ptr>		mChildren;
        int								mSelectedChild;
    };
    
}


#endif /* defined(__Musa__Container__) */
