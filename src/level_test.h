/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef LEVELTEST_H
#define LEVELTEST_H

#include "IStateClassBase.h"
#include "IStateMachineBase.h"

#include <memory>

struct SFactoryComponentList;

class CLevelTest: public IStateClassBase
{
public:
    CLevelTest()
        : m_runCount(0)
    {}
    ~CLevelTest() override =default;
    StateReturnCode StateEntry(SFactoryComponentList& list) override;
    StateReturnCode StateRun() override;
    StateReturnCode StateExit() override;

private:
    SFactoryComponentList* p_list;
    int m_runCount;
};

#endif // LEVELTEST_H
