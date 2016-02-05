//
//  CommandQueue.hpp
//  Musa
//
//  Created by Ian Wilson on 2/5/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#ifndef __Musa__CommandQueue__
#define __Musa__CommandQueue__

#include "Command.hpp"

#include <queue>


class CommandQueue
{
public:
    void						push(const Command& command);
    Command						pop();
    bool						isEmpty() const;
    
    
private:
    std::queue<Command>			mQueue;
};


#endif /* defined(__Musa__CommandQueue__) */
