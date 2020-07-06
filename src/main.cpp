/*****************************************************************
 * Copyright (C) 2017-2019 Robert Valler - All rights reserved.
 *
 * This file is part of the project: StarterApp
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "CoreBase.h"

int main(int argc, char *argv[])
{
    CCoreBase core({argc, argv});

    core.CoreInit();

    while(true)
    {
        bool result = core.CoreRun();
        if(!result)
            break;
    }

    core.CoreStop();
}
