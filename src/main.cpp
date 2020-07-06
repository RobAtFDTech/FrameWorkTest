/*****************************************************************
 * Copyright (C) 2017-2019 Robert Valler - All rights reserved.
 *
 * This file is part of the project: StarterApp
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "CoreBase.h"

int main(int, char *[])
{
    CCoreBase core;

    core.CoreInit();

    int data=0;
    while(true)
    {
        core.CoreSetData(data+=10);

        bool result = core.CoreRun();
        if(!result)
            break;
    }

    core.CoreStop();
}
