///
/// \file IODispatcher.cpp
/// \brief source file for the buffer handler
/// \details
///
/// \author A. Weiser, FDTech GmbH
/// \author FDTech GmbH, by order of VW AG, A. Weiser
/// \date 15/01/2020
///

#include "IODispatcher.h"

namespace BaseService
{
namespace IOBuffer
{

const int MaxDispatcherBuffer = 500;

CIODispatcher::CIODispatcher()
    : m_IODispatcherMaxSignal(MaxDispatcherBuffer)
{

}

int CIODispatcher::NumberOfBuffers()
{
    return m_List.size();
}

int CIODispatcher::NumberOfEntriesPerBuffer(int bufferID)
{
    int result = 0;
    for(const auto& it : m_List)
    {
        if(it->GetBufferID() == bufferID){
            result = it->NumberOfEntries();
            break;
        }
    }
    return result;
}

} // end of IOBuffer
} // end of BaseService
