#ifndef __PAXO_INI__
#define __PAXO_INI__

#include <string>

namespace ini
{
    namespace lexer
    {

        /**
         * @brief Enumeration representing different types of tokens in INI parsing.
         */
        enum TokType
        {
            NEWLINE,         ///< Represents a newline character (\n).
            STRING,          ///< Represents a string, either in quotes ("abc") or unquoted (abc).
            EQUAL,           ///< Represents the equal sign (=).
            LEFT_BRACKET,    ///< Represents the left bracket ([).
            RIGHT_BRACKET,   ///< Represents the right bracket (]).
            END              ///< Represents the end of the token stream.
        };

        /**
         * @brief Structure representing a token in INI parsing.
         */
        struct Tok
        {
            TokType type;       ///< Type of the token.
            std::string value;  ///< Value associated with the token.
        };

        #ifdef DEBUG
            /**
             * @brief Converts a token to its string representation.
             * @param tok The token to convert.
             * @return String representation of the token.
             */
            std::string toktostr(const Tok& tok);
        #endif

        /**
         * @brief Retrieves the next token from the given string.
         * @param str The string to extract the token from.
         * @param i The current index in the string.
         * @return The next token in the string.
         */
        Tok nexttok(const std::string& str, int& i);
    }
}

#endif /* __PAXO_INI__ */