/******************************************************************************
 *
 *  FILE NAME:   Information.hpp
 *
 *  PROGRAMMERS:
 *               Wojciech Migda (wmigda)
 *
 *  DESCRIPTION:
 *    Information measurement units.
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
 *  2013-09-27              wmigda  Initial version
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
typedef std::size_t value_t;
constexpr Information() : m_amount(0){}
constexpr Information(const Information & rhs) : m_amount(rhs.m_amount) {}
constexpr value_t value(void) const {return m_amount;}
constexpr value_t operator()(void) const {return value();}

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

Information & operator++(void)
{
    *this += 1;

    return *this;
}

Information operator++(int)
{
    Information retval(*this);

    ++(*this);

    return retval;
}

Information & operator--(void)
{
    *this -= 1;

    return *this;
}

Information operator--(int)
{
    Information retval(*this);

    --(*this);

    return retval;
}

constexpr Information operator+(const Information & rhs) const {return Information(m_amount + rhs.m_amount);}
constexpr Information operator-(const Information & rhs) const {return Information(m_amount - rhs.m_amount);}
constexpr Information operator*(const value_t rhs) const {return Information(m_amount * rhs);}
constexpr Information operator/(const value_t rhs) const {return Information(m_amount / rhs);}
constexpr bool operator==(const Information & rhs) const {return m_amount == rhs.m_amount;}
constexpr bool operator!=(const Information & rhs) const {return m_amount != rhs.m_amount;}
constexpr bool operator<=(const Information & rhs) const {return m_amount <= rhs.m_amount;}
constexpr bool operator>=(const Information & rhs) const {return m_amount >= rhs.m_amount;}
constexpr bool operator<(const Information & rhs) const {return m_amount < rhs.m_amount;}
constexpr bool operator>(const Information & rhs) const {return m_amount > rhs.m_amount;}

constexpr value_t to(const Information & rhs) const {return (m_amount / rhs.m_amount);}

friend constexpr Information operator"" _bit(unsigned long long x);
friend constexpr Information operator"" _nibble(unsigned long long x);
friend constexpr Information operator"" _byte(unsigned long long x);
friend constexpr Information operator"" _octet(unsigned long long x);
friend constexpr Information operator"" _word(unsigned long long x);
friend constexpr Information operator"" _dword(unsigned long long x);
friend constexpr Information operator"" _qword(unsigned long long x);

private:
std::size_t  m_amount;
constexpr Information(value_t amount) : m_amount(amount) {}
};

constexpr Information operator*(const Information::value_t lhs, const Information & rhs) {return rhs * lhs;}

constexpr Information operator"" _bit(unsigned long long x){return Information(x);}
constexpr Information operator"" _nibble(unsigned long long x){return Information(x * 4u);}
constexpr Information operator"" _byte(unsigned long long x){return Information(x * CHAR_BIT);}
constexpr Information operator"" _octet(unsigned long long x){return Information(x * 8u);}
constexpr Information operator"" _word(unsigned long long x){return Information(x * 16u);}
constexpr Information operator"" _dword(unsigned long long x){return Information(x * 32u);}
constexpr Information operator"" _qword(unsigned long long x){return Information(x * 64u);}

constexpr Information bit(1_bit);
constexpr Information nibble(1_nibble);
constexpr Information byte(1_byte);
constexpr Information octet(1_octet);
constexpr Information word(1_word);
constexpr Information dword(1_dword);
constexpr Information qword(1_qword);

// http://www.codeproject.com/Articles/447922/Application-of-Cplusplus11-User-Defined-Literals-t
constexpr unsigned long long ToBinary(const unsigned long long x, char const * const s)
{
    return (!*s ? x : ToBinary(x + x + (*s == '1' ? 1 : 0), s + 1));
}
constexpr unsigned long long operator"" _b(const char * s){return ToBinary(0, s);}

#endif /* INFORMATION_HPP_ */
