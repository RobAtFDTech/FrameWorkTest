/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "FactoryBase.h"

#include "StateMachine.h"
#include "Logger.h"
#include "IODispatcher.h"

// state classes
#include "level_test.h"
#include "level_exit.h"

//sub-modules
#include "module_test.h"

void CFactory::FactoryInit()
{
    // output / logger
    CLogger::GetInstance();

    m_List.p_stateMachine = std::make_shared<CStateMachine>();
    m_List.p_iobuffer = std::make_shared<BaseService::IOBuffer::CIODispatcher>();
    m_List.p_levelTest = std::make_shared<CLevelTest>();
    m_List.p_levelExit = std::make_shared<CLevelExit>();
    m_List.p_moduleTest =std::make_shared<CModuleTest>();

}

void CFactory::StateInit()
{
    m_List.p_levelTest->Initialise(m_List);
    m_List.p_levelExit->Initialise(m_List);
    m_List.p_stateMachine->Initialise(m_List);
}

SFactoryComponentList& CFactory::FetchList()
{
    return m_List;
}
