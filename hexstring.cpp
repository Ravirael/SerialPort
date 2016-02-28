#include "hexstring.h"
#include <sstream>

std::string HexString::fromHex(const std::string &hexStr)
{
    std::string str;
    unsigned value;
    std::stringstream stream(hexStr);

    while (!stream.eof())
    {
        if (stream.peek() == '0')
        {
            stream >> std::hex >> value;
            str += (char)value;
        }
        else
        {
            stream.get();
        }
    }

    return str;
}

std::string HexString::toHex(const std::string &str, const std::string &separator)
{
    std::stringstream stream;
    std::string hexStr;

    stream << std::hex << std::uppercase;

    for (char c : str)
    {
        stream << "0x" << (unsigned)c << separator;
    }

    hexStr = stream.str();
    hexStr.pop_back();
    return hexStr;
}
