/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef DFW_SM_ISTATECLASS_H
#define DFW_SM_ISTATECLASS_H

struct SFactoryComponentList;

class IStateClassBase
{
public:
    enum StateReturnCode{
        StateCodeNone =0,
// Entry
        StateCodeEntryOK,
        StateCodeEntryError,
// Run
        StateCodeRunOK,
        StateCodeRunExitOK,
        StateCodeRunExitError,
// Exit
        StateCodeExitOK,
        StateCodeExitError,
    };

    virtual ~IStateClassBase(){}
    virtual void Initialise(SFactoryComponentList&) = 0;
    virtual StateReturnCode StateEntry()=0;
    virtual StateReturnCode StateRun()=0;
    virtual StateReturnCode StateExit()=0;
};

#endif // DFW_SM_ISTATECLASS_H
