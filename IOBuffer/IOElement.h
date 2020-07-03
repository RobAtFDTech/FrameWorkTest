///
/// \file IOElement.h
/// \brief Single element class for IOBuffer
/// \details
///
/// \author A. Weiser, FDTech GmbH
/// \author FDTech GmbH, by order of VW AG, A. Weiser
/// \date 15/01/2020
///

#ifndef ELEMENT_H
#define ELEMENT_H

#include <mutex>
#include <memory>

namespace BaseService
{
namespace IOBuffer
{

///
/// \brief      Class CIOElement
/// \details    Single element class for the IOBuffer
///             Template class C needs to be passed during initialisation
///             C is the type of data to be stored (e.g. int, std::string, class, etc.)
///
template<class C>
class CIOElement
{
public:
    CIOElement(const C& c) :m_elementData(c) {}                   // constructor
    CIOElement(const CIOElement& other) = delete;                 // copy constructor. Removed because mutex does not like being copied.
    CIOElement(CIOElement&& other) noexcept  = default;           // move constructor
    CIOElement& operator=(const CIOElement& other) =default;      // copy assignment
    CIOElement& operator=(CIOElement&& other) noexcept =default;  // move assignment
    ~CIOElement()=default;                                        // destructor

    ///
    /// \brief          Read
    ///
    /// \details        Returns the actual data.
    ///                 Template function.
    ///
    /// \return         current value of m_elementData. Template type C
    ///
    C Read(){
        std::lock_guard<std::mutex> lock(*m_elementLock);
        return m_elementData;
    }

    ///
    /// \brief          Write
    ///
    /// \details        Write the actual data to the class.
    ///
    /// \param[in]      element     actual data to be written. Template type C
    ///
    void Write(const C& element){
        std::lock_guard<std::mutex> lock(*m_elementLock);
        m_elementData = element;
    }

private:
    std::unique_ptr<std::mutex> m_elementLock = std::make_unique<std::mutex>(); /// unique mutex. prevent copying of mutex
    C m_elementData;                                                            /// actual data type, containing the buffered data
};

} // end of IOBuffer
} // end of BaseService

#endif // ELEMENT_H
