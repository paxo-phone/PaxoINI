#ifndef __INI_UTILS__
#define __INI_UTILS__

#include <string>

namespace ini
{
    /**
     * @brief Checks if a character is a whitespace character.
     * @param c The character to be checked.
     * @return True if the character is a whitespace character, false otherwise.
     */
    bool iswhitespace(const char c);

    /**
     * @brief Ignores whitespace characters in the given string at a specific index.
     * @param str The string to check for whitespace characters.
     * @param i The index within the string where whitespace characters will be ignored.
     */
    void ignorewhitespaces(const std::string& str, int& i);
}

#endif /* __INI_UTILS__ */