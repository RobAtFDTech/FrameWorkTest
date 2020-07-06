/*****************************************************************
 * Copyright (C) 2017-2020 Robert Valler - All rights reserved.
 *
 * This file is part of the project: DevPlatformAppCMake.
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef DFW_SM_LOGGER_H
#define DFW_SM_LOGGER_H

//#define C_STYLE
#define CPP_STD_STYLE

#include <string>
#ifdef CPP_STD_STYLE
#include <iostream>
#endif
#ifdef C_STYLE
#include <printf.h>
#endif

#define LOGLEV_NONE             1
#define LOGLEV_RUN              2
#define LOGLEV_DEBUG            3

#define LOGTYPE_NONE            1
#define LOGTYPE_CONSOLE         2
#define LOGTYPE_FILE            3
#define LOGTYPE_CONSOLEANDFILE  3


static unsigned int m_LogLevel;
static unsigned int m_LogType;

class CLogger
{
public:
    static CLogger& GetInstance(){
        m_LogLevel = LOGLEV_RUN;
        m_LogType = LOGTYPE_CONSOLE;
        static CLogger instance;
        return instance;
    }

    static void SetLoggingLevel(unsigned int loglevel) {
        m_LogLevel = loglevel;
    }

    static void SetLoggingType(unsigned int loglevel) {
        m_LogLevel = loglevel;
    }

    static void Print(unsigned int loglevel, std::string str) {

        if(!validate(loglevel))
            return;

#ifdef CPP_STD_STYLE
        std::cout << str << "\n";
#endif
#ifdef C_STYLE
        printf("%s\n", str.c_str());
#endif
    }

    static void Print(unsigned int loglevel, std::string str, std::string str2) {

        if(!validate(loglevel))
            return;

#ifdef CPP_STD_STYLE
        std::cout << str << str2 << "\n";
#endif
#ifdef C_STYLE
        printf("%s%s\n", str.c_str(), str2.c_str());
#endif
    }

    static void Print(unsigned int loglevel, std::string str, const char* str2) {

        if(!validate(loglevel))
            return;

#ifdef CPP_STD_STYLE
        std::cout << str << str2 << "\n";
#endif
#ifdef C_STYLE
        printf("%s%s\n", str.c_str(), str2);
#endif
    }

    template<typename T>
    static void Print(unsigned int loglevel, std::string str, T t) {

        if(!validate(loglevel))
            return;

#ifdef CPP_STD_STYLE
        std::cout << str << std::to_string(t) << "\n";
#endif
#ifdef C_STYLE
        printf("%s", str.c_str());
#endif
    }

    template <class T>
    static void Print(unsigned int loglevel, T t)
    {
        if(!validate(loglevel))
            return;

#ifdef CPP_STD_STYLE
        std::cout << t << "\n";
#endif
#ifdef C_STYLE
        printf("%s", str.c_str(), ...);
#endif

    }

    template <class T, class... Args>
    static void Print(unsigned int loglevel, T t, Args... args)
    {
        if(!validate(loglevel))
            return;

#ifdef CPP_STD_STYLE
        std::cout << t;
#endif
#ifdef C_STYLE
        printf("%s", str.c_str(), ...);
#endif
        Print(loglevel, args...);
    }

private:
    static inline bool validate(unsigned int loglevel)
    {
        if(LOGLEV_NONE == m_LogType)
            return false;
        if(LOGLEV_NONE == m_LogLevel)
            return false;
        if(m_LogLevel >= loglevel)
            return false;
        return true;
    }

    CLogger(){}
    CLogger(CLogger const&)          = delete;
    void operator=(CLogger const&)  = delete;
};

#endif // DFW_SM_LOGGER_H
