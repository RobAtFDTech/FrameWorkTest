/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef FACTORYLIST_H
#define FACTORYLIST_H

class CStateMachine;
class CLevelTest;
class CLevelExit;
class CModuleTest;

namespace BaseService{
    namespace IOBuffer{
        class CIODispatcher;
    };
};

#include <memory>

struct SFactoryComponentList
{
    std::shared_ptr<CStateMachine> p_stateMachine;
    std::shared_ptr<BaseService::IOBuffer::CIODispatcher> p_iobuffer;
    std::shared_ptr<CLevelTest> p_levelTest;
    std::shared_ptr<CLevelExit> p_levelExit;
    std::shared_ptr<CModuleTest> p_moduleTest;
};

#endif // FACTORYLIST_H
