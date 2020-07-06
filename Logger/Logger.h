/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

#define LOGLEV_RUN 1

class CLogger
{
public:
    static CLogger& GetInstance(){
        static CLogger instance;
        return instance;
    }

    static void Print(unsigned int loglevel, std::string str) {
        std::cout << str << "\n";
    }

    static void Print(unsigned int loglevel, std::string str, std::string str2) {
        std::cout << str << str2 << "\n";
    }

    static void Print(unsigned int loglevel, std::string str, const char* str2) {
        std::cout << str << str2 << "\n";
    }

    template<typename T>
    static void Print(unsigned int loglevel, std::string str, T t) {
        std::cout << str << std::to_string(t) << "\n";
    }

    template <class T>
    static void Print(unsigned int loglevel, T t)
    {
        std::cout << t << "\n";
    }

    template <class T, class... Args>
    static void Print(unsigned int loglevel, T t, Args... args)
    {
        std::cout << t;
        Print(loglevel, args...);
    }

private:
    CLogger(){}
    CLogger(CLogger const&)          = delete;
    void operator=(CLogger const&)  = delete;
};

#endif // LOGGER_H
