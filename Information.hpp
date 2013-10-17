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
typedef struct pair
{
    value_t     q; // quotient
    value_t     r; // remainder
    constexpr pair(const value_t q, const value_t r) : q(q), r(r) {}
} pair_t;
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
constexpr value_t operator/(const Information & rhs) const {return m_amount / rhs.m_amount;}
constexpr bool operator==(const Information & rhs) const {return m_amount == rhs.m_amount;}
constexpr bool operator!=(const Information & rhs) const {return m_amount != rhs.m_amount;}
constexpr bool operator<=(const Information & rhs) const {return m_amount <= rhs.m_amount;}
constexpr bool operator>=(const Information & rhs) const {return m_amount >= rhs.m_amount;}
constexpr bool operator<(const Information & rhs) const {return m_amount < rhs.m_amount;}
constexpr bool operator>(const Information & rhs) const {return m_amount > rhs.m_amount;}

constexpr value_t to(const Information & rhs) const {return *this / rhs;}
constexpr pair_t div(const Information & rhs) const {return pair(m_amount / rhs.m_amount, m_amount % rhs.m_amount);}
constexpr pair_t convert(const Information & rhs) const {return this->div(rhs);}

friend constexpr Information operator"" _bit(unsigned long long x);
friend constexpr Information operator"" _nibble(unsigned long long x);
friend constexpr Information operator"" _byte(unsigned long long x);
friend constexpr Information operator"" _octet(unsigned long long x);
friend constexpr Information operator"" _word(unsigned long long x);
friend constexpr Information operator"" _dword(unsigned long long x);
friend constexpr Information operator"" _qword(unsigned long long x);

private:
std::size_t  m_amount;
constexpr Information(const value_t amount) : m_amount(amount) {}
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

namespace InformationPrivate
{
// http://www.codeproject.com/Articles/447922/Application-of-Cplusplus11-User-Defined-Literals-t
// with modifications based on this SO answer:
// http://stackoverflow.com/a/19168580/2003487
constexpr unsigned long long __M_to_binary(const unsigned long long x, char const * const s)
{
    return (!*s ? x : __M_to_binary(x + x + (*s == '1' ? 1 : 0), s + 1));
}
constexpr unsigned long long operator"" _b(const char * s){return __M_to_binary(0, s);}
}
using InformationPrivate::operator"" _b;

#endif /* INFORMATION_HPP_ */
