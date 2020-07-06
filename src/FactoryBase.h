/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef FACTORYBASE_H
#define FACTORYBASE_H

#include "FactoryList.h"

class CFactoryBase final
{
public:
    CFactoryBase();
    CFactoryBase(const CFactoryBase& other)=delete;
    CFactoryBase(CFactoryBase&& other) noexcept =delete;
    CFactoryBase& operator=(const CFactoryBase& other)=default;
    CFactoryBase& operator=(CFactoryBase&& other) noexcept =default;
    ~CFactoryBase() =default;

    void FactoryInit(int argc, char **argv);
    void StateInit();
    SFactoryComponentList& FetchList();
    void DestroyAll();

private:
    int m_argc;
    char **m_argv;
    SFactoryComponentList m_List;
};

#endif // FACTORYBASE_H
