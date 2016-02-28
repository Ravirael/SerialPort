#ifndef HEXSTRING_H
#define HEXSTRING_H

#include <string>

namespace HexString
{
    std::string fromHex(const std::string &hexStr);

    std::string toHex(const std::string &str, const std::string &separator = " ");
}

#endif // HEXSTRING_H
