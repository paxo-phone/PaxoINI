#include "utils.hpp"

namespace ini
{
    #define WHITESPACE " \n\t"
    
    bool iswhitespace(const char c)
    {
        return (c == ' ' || c == '\r' || c == '\t');
    }

    void ignorewhitespaces(const std::string& str, int& i)
    {
        while( i < str.size() && iswhitespace(str[i]) )
            i++;
    }
}