/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "CoreBase.h"

#include "FactoryBase.h"
#include "FactoryList.h"
#include "Logger.h"


#include "StateMachine.h"
#include "IODispatcher.h"

static CFactory factory;

CCoreBase::CCoreBase()
    : m_factory(factory)
{

}

void CCoreBase::CoreInit()
{
    m_factory.FactoryInit();
    m_factory.StateInit();
    m_List = &m_factory.FetchList();
}

bool CCoreBase::CoreRun()
{
    CLogger::Print(LOGLEV_RUN, "Running");
    return m_List->p_stateMachine->task();
}

bool CCoreBase::CoreSetData(int data)
{
    return m_List->p_iobuffer->Write(1, data);
}

void CCoreBase::CoreStop()
{
    m_List->p_stateMachine->Finalise();
}
