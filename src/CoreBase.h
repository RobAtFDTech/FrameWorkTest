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

class CFactory;
struct SFactoryComponentList;

class CCoreBase final
{
public:
    CCoreBase();                                                 // constructor
    CCoreBase(const CCoreBase& other)=delete;                   // copy constructor
    CCoreBase(CCoreBase&& other) noexcept =delete;              // move constructor
    CCoreBase& operator=(const CCoreBase& other)=default;       // copy assignment
    CCoreBase& operator=(CCoreBase&& other) noexcept =default;  // move assignment
    ~CCoreBase() =default;                                      // destructor

    void CoreInit();
    bool CoreRun();

    bool CoreSetData(int data);

    void CoreStop();

private:
    CFactory& m_factory;
    SFactoryComponentList *m_List;

};

#endif // COREBASE_H
