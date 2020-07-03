/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "level_test.h"

#include "FactoryList.h"
#include "module_test.h"

#include "Logger.h"


IStateClassBase::StateReturnCode CLevelTest::StateEntry(SFactoryComponentList& list)
{
    p_list = &list;

    CLogger::Print(LOGLEV_RUN, "StateEntry");
    p_list->p_moduleTest->Initialise();
    return StateCodeEntryOK;
}

IStateClassBase::StateReturnCode CLevelTest::StateRun()
{
    CLogger::Print(LOGLEV_RUN, "StateRun ", ++m_runCount);
    p_list->p_moduleTest->Process();

    if(m_runCount > 5)
        return StateCodeRunExitOK;
    else
        return StateCodeRunOK;
}

IStateClassBase::StateReturnCode CLevelTest::StateExit()
{
    CLogger::Print(LOGLEV_RUN, "StateExit");
    p_list->p_moduleTest->Terminate();
    return StateCodeExitOK;
}
