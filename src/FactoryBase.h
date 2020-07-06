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

class CFactory
{
public:
    CFactory()=default;
    CFactory(const CFactory& other)=delete;
    CFactory(CFactory&& other) noexcept =delete;
    CFactory& operator=(const CFactory& other)=default;
    CFactory& operator=(CFactory&& other) noexcept =default;
    ~CFactory() =default;

    void FactoryInit();
    void StateInit();
    SFactoryComponentList& FetchList();

private:
    SFactoryComponentList m_List;
};

#endif // FACTORYBASE_H
