/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "CoreBase.h"

#include "Logger.h"

#include "FactoryBase.h"
#include "StateMachine.h"

static CFactoryBase factory;

CCoreBase::CCoreBase(SCoreStartUpParameter parm)
    : m_factory(factory)
    , m_startUpParms(parm)
{

}

void CCoreBase::CoreInit()
{
    m_factory.FactoryInit(m_startUpParms.argc, m_startUpParms.argv);
    m_factory.InitAll();
}

void CCoreBase::CoreRun()
{
    CLogger::Print(LOGLEV_RUN, "Running");
    m_factory.FetchList().p_stateMachine->Process();
}

void CCoreBase::CoreStop()
{
    m_factory.FetchList().p_stateMachine->Finalise();
}
