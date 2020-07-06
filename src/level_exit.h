/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef LEVELEXIT_H
#define LEVELEXIT_H

#include "IStateClassBase.h"
#include "IStateMachineBase.h"


class CLevelExit: public IStateClassBase
{
public:
    CLevelExit()=default;
    ~CLevelExit() override =default;
    void Initialise(SFactoryComponentList&) override {}
    IStateClassBase::StateReturnCode StateEntry() override { return StateCodeEntryOK; }
    IStateClassBase::StateReturnCode StateRun() override { return StateCodeRunExitOK; }
    IStateClassBase::StateReturnCode StateExit() override { return StateCodeExitOK; }

private:

};

#endif // LEVELEXIT_H
