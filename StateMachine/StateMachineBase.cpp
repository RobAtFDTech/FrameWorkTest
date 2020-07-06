/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "StateMachineBase.h"

#include "Logger.h"

CStateMachineBase::CStateMachineBase()
    : m_RequestedState(0)
    , m_CurrentState(0)
    , m_PreviousState(0)
    , m_CurrentMode(StateEntry)
    , b_isInitCalled(false)
{

}

IStateClassBase::StateReturnCode CStateMachineBase::Process()
{
    IStateClassBase::StateReturnCode returnCode = IStateClassBase::StateCodeNone;

    switch(m_CurrentMode)
    {
        case StateEntry:
        {
            if(m_iLevel) {
                CLogger::Print(LOGLEV_RUN, "StateMachine Entry: State ", m_CurrentState, " OK");
                returnCode = m_iLevel->StateEntry();
                m_CurrentMode = StateRun;
            } else {
                CLogger::Print(LOGLEV_RUN, "StateMachine Entry: State ", m_CurrentState, " ERROR");
                returnCode = IStateClassBase::StateCodeEntryError;
            }
            break;
        }
        case StateRun:
        {
            if(m_iLevel) {
                CLogger::Print(LOGLEV_RUN, "StateMachine Run: State ", m_CurrentState, " OK");
                returnCode = m_iLevel->StateRun();
                if( IStateClassBase::StateCodeRunExitOK == returnCode )
                    m_CurrentMode = StateExit;
            } else {
                CLogger::Print(LOGLEV_RUN, "StateMachine Run: State ", m_CurrentState, " ERROR");
                returnCode = IStateClassBase::StateCodeRunExitError;
            }
            break;
        }
        case StateExit:
        {
            if(m_iLevel) {
                CLogger::Print(LOGLEV_RUN, "StateMachine Exit: State ", m_CurrentState, " OK");
                returnCode = m_iLevel->StateExit();
                m_iLevel = p_RequestedLevel;
                m_PreviousState = m_CurrentState;
                m_CurrentState = m_RequestedState;
                m_CurrentMode = StateEntry;

            } else {
                CLogger::Print(LOGLEV_RUN, "StateMachine Exit: State ", m_CurrentState, " ERROR");
                returnCode = IStateClassBase::StateCodeExitError;
            }
            break;
        }
    }
    return returnCode;
}

void CStateMachineBase::AddNewState(unsigned int stateID, std::string name, std::shared_ptr<IStateClassBase> stateClass)
{
    for(const auto& it: m_StateClassList)
    {
        if(m_CurrentState == it.StateID)
        {
            return;
        }
    }

    SStateList s;
    s.StateID = stateID;
    s.StateName = name;
    s.stateClass = stateClass;
    m_StateClassListLock.lock();
    m_StateClassList.emplace_back(std::move(s));
    m_StateClassListLock.unlock();
}

void CStateMachineBase::RemoveCurrentState(unsigned int stateID)
{
    for( auto it = m_StateClassList.begin(); it != m_StateClassList.end(); /*no inc*/ )
    {
        if( stateID == it->StateID ) {

            m_StateClassListLock.lock();
            it = m_StateClassList.erase(it);
            m_StateClassListLock.unlock();

            break;
        } else {
            ++it;
        }
    }
}

bool CStateMachineBase::SetInitState(unsigned int stateID)
{
    bool result = false;
    for(const auto& it: m_StateClassList)
    {
        if(stateID == it.StateID)
        {
            m_iLevel = it.stateClass;
            m_CurrentState = it.StateID;
            result = true;
            break;
        }
    }
    return result;
}

bool CStateMachineBase::SetNextState(unsigned int stateID)
{
    bool result = false;
    for(const auto& it: m_StateClassList)
    {
        if(stateID == it.StateID)
        {
            p_RequestedLevel = it.stateClass;
            m_RequestedState = stateID;
            result = true;
            break;
        }
    }
    return result;
}
