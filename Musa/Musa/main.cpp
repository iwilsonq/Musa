//
//  main.cpp
//  Musa
//
//  Created by Ian Wilson on 2/3/16.
//  Copyright (c) 2016 APM. All rights reserved.
//

#include "Application.hpp"

#include <stdexcept>
#include <iostream>


int main()
{
    try
    {
        Application app;
        app.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}
