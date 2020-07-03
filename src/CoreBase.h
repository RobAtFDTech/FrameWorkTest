/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef COREBASE_H
#define COREBASE_H

struct SCoreStartUpParameter {
    int argc;
    char **argv;
};

class CFactoryBase;

class CCoreBase final
{
public:
    CCoreBase(SCoreStartUpParameter parm);                      // constructor
    CCoreBase(const CCoreBase& other)=delete;                   // copy constructor
    CCoreBase(CCoreBase&& other) noexcept =delete;              // move constructor
    CCoreBase& operator=(const CCoreBase& other)=default;       // copy assignment
    CCoreBase& operator=(CCoreBase&& other) noexcept =default;  // move assignment
    ~CCoreBase() =default;                                      // destructor

    void CoreInit();
    void CoreRun();
    void CoreStop();

private:
    CFactoryBase& m_factory;
    SCoreStartUpParameter m_startUpParms;

};

#endif // COREBASE_H
