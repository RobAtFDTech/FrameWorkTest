cmake_minimum_required(VERSION 3.5.0)
project (FrameworkTest)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread -fno-stack-protector")
set (CMAKE_CXX_STANDARD 14)
set (Wall)
set (W1)
set (Wfloat-conversion)




#function(AddBaseComponent arg)
#    set(BaseComponent ${CMAKE_SOURCE_DIR}/../DevFramework/${arg})
#    message("Including base component ${BaseComponent}")
#    include_directories(${BaseComponent})
#    file(GLOB_RECURSE BASESOURCES ${BaseComponent}/*.cpp)
#    file(GLOB_RECURSE BASEHEADERS ${BaseComponent}/*.h)
#    message("project name " ${PROJECT_NAME})
#endfunction()

#AddBaseComponent(StateMachine)
#AddBaseComponent(Logger)

set(BaseStateMachine ${CMAKE_SOURCE_DIR}/StateMachine)
set(BaseLogger ${CMAKE_SOURCE_DIR}/Logger)
set(BaseIOBuffer ${CMAKE_SOURCE_DIR}/IOBuffer)

include_directories(${CMAKE_SOURCE_DIR}/src})
include_directories(${BaseStateMachine})
include_directories(${BaseLogger})
include_directories(${BaseIOBuffer})

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${BaseStateMachine}/*.cpp
    ${BaseIOBuffer}/*.cpp
    )

file(GLOB_RECURSE HEADERS
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${BaseStateMachine}/*.h
    ${BaseIOBuffer}/*.h
    ${BaseLogger}/*.h
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

