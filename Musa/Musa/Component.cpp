//
//  Component.cpp
//  Musa
//
//  Created by Ian Wilson on 2/4/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Component.hpp"

namespace GUI
{
    
    Component::Component()
    : mIsSelected(false)
    , mIsActive(false)
    {
    }
    
    Component::~Component()
    {
    }
    
    bool Component::isSelected() const
    {
        return mIsSelected;
    }
    
    void Component::select()
    {
        mIsSelected = true;
    }
    
    void Component::deselect()
    {
        mIsSelected = false;
    }
    
    bool Component::isActive() const
    {
        return mIsActive;
    }
    
    void Component::activate()
    {
        mIsActive = true;
    }
    
    void Component::deactivate()
    {
        mIsActive = false;
    }
    
}