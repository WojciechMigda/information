#include "Information.hpp"
#include <iostream>

static Information  foo = 147_bit;

Information bar(void)
{
    return foo;
}

int main(void)
{
    std::cout << "In bits: " << bar().to(bit) << '\n';
    std::cout << "In nibbles: " << bar().to(nibble) << '\n';
    std::cout << "In octets: " << bar().to(octet) << '\n';
    std::cout << "In bytes: " << bar().to(byte) << '\n';
    std::cout << "In words: " << bar().to(word) << '\n';
    std::cout << "In dwords: " << bar().to(dword) << '\n';
    std::cout << "In qwords: " << bar().to(qword) << '\n';
    return 0;
}
