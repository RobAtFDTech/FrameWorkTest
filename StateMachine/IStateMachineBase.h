/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef DFW_SM_ISTATEMACHINEBASE_H
#define DFW_SM_ISTATEMACHINEBASE_H

class IStateMachineBase
{
public:
    virtual ~IStateMachineBase(){}
    virtual bool SetNextState(unsigned int)=0;
};

#endif // DFW_SM_ISTATEMACHINEBASE_H
