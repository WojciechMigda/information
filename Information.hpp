/*****************************************************************************
*
*  FILE NAME:   Information.hpp
*
*  PROGRAMMERS:
*               name surname (awm018)
*
*  DESCRIPTION:
*    File description.
*
*  CAUTIONS:
*    None.
*
******************************************************************************
*
*  FILE MODIFICATION HISTORY:
*
*  DATE         VERSION    WHO     DESCRIPTION
*  ---------    ---------  ------  -----------
*  27 wrz 2013              awm018  Initial version
*
******************************************************************************
*/

#ifndef INFORMATION_HPP_
#define INFORMATION_HPP_

#include <cstdint>
#include <climits>

class Information
{
public:
constexpr Information() : m_amount(0){}
constexpr Information(const Information & rhs) : m_amount(rhs.m_amount) {}
constexpr std::size_t value(void) const {return m_amount;}
constexpr std::size_t operator()(void) const {return value();}

Information & operator+=(const Information &rhs)
{
    m_amount += rhs.m_amount;
    return *this;
}
Information & operator-=(const Information &rhs)
{
    m_amount -= rhs.m_amount;
    return *this;
}
constexpr Information to(const Information & rhs) const {return Information(m_amount / rhs.m_amount);}

friend constexpr Information operator"" _bit(unsigned long long x);
friend constexpr Information operator"" _byte(unsigned long long x);
friend constexpr Information operator"" _octet(unsigned long long x);

private:
std::size_t  m_amount;
constexpr Information(std::size_t amount) : m_amount(amount) {}
};

constexpr Information operator"" _bit(unsigned long long x){return Information(x);}
constexpr Information operator"" _byte(unsigned long long x){ return Information(x * CHAR_BIT);}
constexpr Information operator"" _octet(unsigned long long x){ return Information(x * CHAR_BIT);}

constexpr Information bit(1_bit);
constexpr Information byte(1_byte);
constexpr Information octet(1_octet);

#endif /* INFORMATION_HPP_ */
