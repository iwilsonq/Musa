//
//  SceneNode.hpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__SceneNode__
#define __Musa__SceneNode__

#include "Category.hpp"
#include "CommandQueue.hpp"

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <set>
#include <Utility.hpp>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    typedef std::pair<SceneNode*, SceneNode*> Pair;
    
public:
    explicit                SceneNode(Category::Type category = Category::None);
    void                    attachChild(Ptr child);
    Ptr                     detachChild(const SceneNode& node);
    
    void					update(sf::Time dt, CommandQueue& commands);
    
    sf::Vector2f            getWorldPosition() const;
    sf::Transform           getWorldTransform() const;
    
    void					onCommand(const Command& command, sf::Time dt);
    virtual unsigned int	getCategory() const;
    
    void					checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
    void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
    void					removeWrecks();
    virtual sf::FloatRect	getBoundingRect() const;
    virtual bool			isMarkedForRemoval() const;
    virtual bool			isDestroyed() const;

    
private:
    virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
    void					updateChildren(sf::Time dt, CommandQueue& commands);
    
    virtual void            draw(sf::RenderTarget& target,sf::RenderStates states) const;
    virtual void            drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
    void                    drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
    std::vector<Ptr>    mChildren;
    SceneNode*          mParent;
    unsigned int        mDefaultCategory;
    
};

bool	collision(const SceneNode& lhs, const SceneNode& rhs);
float	distance(const SceneNode& lhs, const SceneNode& rhs);

#endif /* defined(__Musa__SceneNode__) */
