/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef MODULETEST_H
#define MODULETEST_H

#include "Logger.h"

class CModuleTest
{
public:
    CModuleTest() =default;
    ~CModuleTest() =default;

    void Initialise(){
        CLogger::Print(LOGLEV_RUN, "--------> CModuleTest Init");
    }
    void Process(int data){
        CLogger::Print(LOGLEV_RUN, "--------> CModuleTest Process: ", data);
    }
    void Terminate(){
        CLogger::Print(LOGLEV_RUN, "--------> CModuleTest Terminate");
    }

private:

};

#endif // MODULETEST_H
