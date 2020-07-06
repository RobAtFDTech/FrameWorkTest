/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "StateMachine.h"

#include "FactoryList.h"
#include "Logger.h"


#include "level_test.h"
#include "level_exit.h"


enum States
{
    SM_State_TEST = 1,
    SM_State_EXIT,
};

CStateMachine::~CStateMachine()
{
    Finalise();
}

void CStateMachine::Initialise(SFactoryComponentList& list)
{
    p_List = &list;
    AddNewState(SM_State_TEST, "TEST", p_List->p_levelTest);
    AddNewState(SM_State_EXIT, "EXIT", p_List->p_levelExit);

    SetInitState(SM_State_TEST);
}

bool CStateMachine::task()
{
    bool result = true;

    IStateClassBase::StateReturnCode status = Process();
    unsigned int currentState = GetCurrentState();

    switch(currentState)
    {
        case SM_State_TEST:
            if(status == IStateClassBase::StateReturnCode::StateCodeRunExitOK)
                SetNextState(SM_State_EXIT);
            break;
        case SM_State_EXIT:
            if(status == IStateClassBase::StateReturnCode::StateCodeRunExitOK)
            {
                Finalise();
                result = false;
            }
            break;
    }

    return result;
}

void CStateMachine::Finalise()
{
    m_requestShutdown = true;
}

