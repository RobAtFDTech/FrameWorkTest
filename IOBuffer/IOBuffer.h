///
/// \file IOBuffer.h
/// \brief I/O Buffer class file for handling a single buffer.
/// \details    This buffer class handles a queue of buffer elements.
///             There is one IOBuffer instance per data type and signal ID.
///             This template file is not affiliated with a .cpp file.
///
/// \author A. Weiser, FDTech GmbH
/// \author FDTech GmbH, by order of VW AG, A. Weiser
/// \date 15/01/2020
///

#ifndef IOBUFFER_H
#define IOBUFFER_H

#include "IOElement.h"

#include <queue>
#include <mutex>
#include <typeinfo>

namespace BaseService
{
namespace IOBuffer
{

/// Class    :   IIOBuffer
/// Info     :   Interface class for CIOBuffer
///
class IIOBuffer
{
public:
    virtual ~IIOBuffer(){}
    virtual int GetBufferID()=0;
    virtual const char* GetBufferType()=0;
    virtual int NumberOfEntries()=0;
};

/// Class    :   CIOBuffer
/// Info     :   Behaviour class for the buffer. This handles the queue of raw data.
///              This class must be instantiated with a data type.
///
template<class C>
class CIOBuffer : public IIOBuffer
{
public:
    CIOBuffer(int bufferID, const C& c)                            // constructor
    : m_bufferID(bufferID)
    {
        WriteToBuffer(c);
    }
    CIOBuffer(const CIOBuffer& other) = default;                // copy constructor
    CIOBuffer(CIOBuffer&& other) noexcept  = default;           // move constructor
    CIOBuffer& operator=(const CIOBuffer& other) =default;      // copy assignment
    CIOBuffer& operator=(CIOBuffer&& other) noexcept =default;  // move assignment
    ~CIOBuffer()=default;                                       // destructor

    ///
    /// \brief          GetBufferID
    ///
    /// \details        Returns the ID of this buffer
    ///
    /// \return         m_bufferID
    ///
    int GetBufferID() override
    {
        return m_bufferID;
    }

    ///
    /// \brief          GetBufferType
    ///
    /// \details        Returns the stored data type in text format
    ///
    /// \return         name of the data type.
    ///
    const char* GetBufferType() override
    {
        return typeid(C).name();
    }

    ///
    /// \brief          NumberOfEntries
    ///
    /// \details        Returns the current number of elements / entries in this buffer
    ///
    /// \return         number of elements.
    ///                 if N > 0 then the buffer has elements
    ///                 if N == 0 then the buffer is empty
    ///
    int NumberOfEntries() override
    {
        return m_IOBuffer.size();
    }

    ///
    /// \brief          WriteToBuffer
    ///
    /// \details        Writes the actual data to a new element on the buffer
    ///                 This new element is added to the end of the queue.
    ///
    /// \param[in]      actual data. Type C is determined on class instantiation.
    ///
    void WriteToBuffer(const C& c)
    {        
        CIOElement<C> element(c);
        m_IOBuffer.push(std::move(element)); // the copy constructor of element is disabled, so we move instead.
    }

    ///
    /// \brief          ReadFromBuffer
    ///
    /// \details        Reads the element from the front of the queue.
    ///                 Once the data is read the element is removed.
    ///
    /// \return         element of type C
    ///
    C ReadFromBuffer()
    {
        C element = m_IOBuffer.front().Read();
        m_IOBuffer.pop();
        return element;
    }

private:
    int m_bufferID;                         /// Buffer ID.
    std::queue<CIOElement<C>> m_IOBuffer;   /// The queue of elements, of template class C.
};

} // end of IOBuffer
} // end of BaseService

#endif // IOBUFFER_H
