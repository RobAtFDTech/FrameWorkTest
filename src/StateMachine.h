/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <thread>

struct SFactoryComponentList;

class CStateMachine
{
public:
    CStateMachine()
        : m_requestShutdown(false)
    {}

    ~CStateMachine();

    void Initialise(SFactoryComponentList& list);
    void Process();
    void Finalise();

private:
    bool m_requestShutdown;
    SFactoryComponentList* p_List;
};

#endif // STATEMACHINE_H
