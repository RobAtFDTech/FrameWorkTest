/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "StateMachine.h"

#include "level_test.h"
#include "FactoryList.h"
#include "Logger.h"

enum States
{
    SM_State_TEST,
    SM_State_EXIT,
};

CStateMachine::~CStateMachine()
{
    Finalise();
}

void CStateMachine::Initialise(SFactoryComponentList& list)
{
    p_List = &list;
}

void CStateMachine::Process()
{
    p_List->p_levelTest->StateEntry(*p_List);
    p_List->p_levelTest->StateRun();
    p_List->p_levelTest->StateExit();
}

void CStateMachine::Finalise()
{
    m_requestShutdown = true;
}

