/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef DFW_SM_STATEMACHINEBASE_H
#define DFW_SM_STATEMACHINEBASE_H

#include "IStateClassBase.h"

#include <memory>
#include <vector>
#include <string>
#include <mutex>


// Helper macros
#define ADDNEWSTATE(x, y) AddNewState(x, std::make_shared<y>())


// todo: define the moores and mealy state machine

enum StateMachineMode
{
    StateEntry = 0,
    StateRun,
    StateExit
};

struct SStateList
{
    unsigned int StateID;
    std::string StateName;
    std::shared_ptr<IStateClassBase> stateClass;
};

struct SS
{
    unsigned int CurrentState;
    unsigned int NextState;
    unsigned int ErrorState;
};

class CStateMachineBase
{
public:
    CStateMachineBase();
    ~CStateMachineBase() =default;

    void AddNewState(unsigned int stateID, std::string name, std::shared_ptr<IStateClassBase> stateClass);
    void RemoveCurrentState(unsigned int stateID);
    bool SetInitState(unsigned int stateID);
    bool SetNextState(unsigned int stateID);
    unsigned int GetCurrentState() {return m_CurrentState; }
    IStateClassBase::StateReturnCode Process();

protected:
    std::mutex m_StateClassListLock;
    std::vector<SStateList> m_StateClassList;
    std::shared_ptr<IStateClassBase> m_iLevel;
    std::shared_ptr<IStateClassBase> p_RequestedLevel;

    unsigned int m_RequestedState;
    unsigned int m_CurrentState;
    unsigned int m_PreviousState;
    StateMachineMode m_CurrentMode;

    bool b_isInitCalled;
};

#endif // DFW_SM_STATEMACHINEBASE_H
