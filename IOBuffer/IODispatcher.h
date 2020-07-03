///
/// \file IODispatcher.h
/// \brief  handler and main interface for all buffers
/// \details
///
/// \author A. Weiser, FDTech GmbH
/// \author FDTech GmbH, by order of VW AG, A. Weiser
/// \date 15/01/2020
///

#ifndef IODISPATCHER_H
#define IODISPATCHER_H

#include "IOBuffer.h"

#include <list>
#include <memory>
#include <iostream>
#include <typeinfo>

namespace BaseService
{
namespace IOBuffer
{

///
/// \brief      Class CIODispatcher
/// \details    Interface for all buffers.
///             This class the the access points for all buffers from the main application.
///
class CIODispatcher
{
public:
    CIODispatcher();                                                    // constructor
    CIODispatcher(const CIODispatcher& other) = default;                // copy constructor
    CIODispatcher(CIODispatcher&& other) noexcept  = default;           // move constructor
    CIODispatcher& operator=(const CIODispatcher& other) =default;      // copy assignment
    CIODispatcher& operator=(CIODispatcher&& other) noexcept =default;  // move assignment
    ~CIODispatcher()=default;                                           // destructor

    ///
    /// \brief          NumberOfBuffers
    ///
    /// \details        Returns the number of buffers currently handled by the dispatcher.
    ///
    /// \return         int     number of buffers.
    ///
    int NumberOfBuffers();

    ///
    /// \brief          NumberOfEntriesPerBuffer
    ///
    /// \details        Returns the number of elements in the selected buffer
    ///
    /// \param[in]      bufferID - selected buffer
    ///
    /// \return         number of entries
    ///
    int NumberOfEntriesPerBuffer(int bufferID);

    ///
    /// \brief          Write
    ///
    /// \details        Writes the data to the selected buffer
    ///                 Template function. The buffer data type is determined by <T>
    ///
    /// \param[in]      bufferID    selected buffer / signal
    /// \param[in]      t            data to be written
    ///
    /// \return         bool        true    OK
    ///                             false   NOK
    ///
    template<typename T>
    bool Write(const int bufferID, const T& t)
    {
        bool result = true;

        // check for an existing entry
        for(const auto& it : m_List)
        {
            if(it->GetBufferID() == bufferID)
            {
                if(it->GetBufferType() != typeid(T).name())
                {
                    std::cout << "Write: Expected type does not match existing IOBuffer" << std::endl;
                    return false;
                }

                // update this existing record
                CIOBuffer<T> *pBuffer = static_cast< CIOBuffer<T> *>(it.get());
                pBuffer->WriteToBuffer(t);
                return true;
            }
        }

        // record does not exist, create a new one.
        if(m_List.size() >= m_IODispatcherMaxSignal)
        {
            std::cout << "IODispatcher signal count exceeded, new ID not added" << std::endl;
            result = false;
        }
        else
        {
            m_List.emplace_back(std::make_shared<CIOBuffer<T>>(bufferID, t));
            result = true;
        }

        return result;
    }

    ///
    /// \brief          Read
    ///
    /// \details        Reads from the selected buffer
    ///                 Template function. The buffer data type is determined by <T>
    ///
    /// \param[in]      bufferID    requested signal/buffer
    /// \param[in,out]  t           reference, this is updated with the read data.
    ///
    /// \return         bool        true    OK
    ///                             false   NOK
    ///
    template<typename T>
    bool Read(int bufferID, T& t){

        // check if the list is empty
        if(m_List.empty())
        {
            std::cout << "Dispatch list is empty" << std::endl;
            return false;
        }

        // fetch the data from the list
        for(const auto& it : m_List)
        {
            if(it->GetBufferID() == bufferID)
            {
                if(it->GetBufferType() != typeid(T).name())
                {
                    std::cout << "Read: Expected type does not match IOBuffer" << std::endl;
                    return false;
                }
                CIOBuffer<T> *pBuffer = static_cast< CIOBuffer<T> *>(it.get());
                t = pBuffer->ReadFromBuffer();
                return true;
            } // if
        } // for
        return false;
    }

    ///
    /// \brief          RemoveBuffer
    ///
    /// \details        Removes a buffer from the list
    ///
    /// \param[in]      bufferID    requested signal/buffer
    ///
    /// \return         bool        true    OK
    ///                             false   NOK
    ///
    bool RemoveBuffer(int bufferID)
    {
        bool result = false;
        for(auto it = m_List.begin(); it != m_List.end(); /*no increment*/)
        {
            if((*it)->GetBufferID() == bufferID)
            {
                it = m_List.erase(it);
                result = true;
                break;
            } else {
                it++;
            }
        }
        return result;
    }

private:
    int m_IODispatcherMaxSignal;                        /// Maximum number of signals
    std::list<std::shared_ptr<IIOBuffer>> m_List;       /// Buffer list.
};

} // end of IOBuffer
} // end of BaseService

#endif // IODISPATCHER_H
