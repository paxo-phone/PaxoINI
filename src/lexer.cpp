#include <string>
#include <iostream>

#include "lexer.hpp"
#include "utils.hpp"

namespace ini
{
    namespace lexer
    {
        Tok nexttok(const std::string& str, int& i)
        {
            ignorewhitespaces(str, i); // will do nothing if i ≥ size(str), it's safe
            
            if( i < str.size() && (str[i] == ';' || str[i] == '#') )
            {
                do 
                {
                    i++;
                } while(i < str.size() && str[i] != '\n');
            }

            if( i >= str.size() )
                return { END, "" };

            /* NEWLINE */
            if (str[i] == '\n')
            {
                i++;
                return { NEWLINE, "" };
            }

            /* EQUAL */
            if (str[i] == '=')
            {
                i++;
                return { EQUAL, "" };
            }

            /* LEFT_BRACKET */
            if (str[i] == '[')
            {
                i++;
                return { LEFT_BRACKET, "" };
            }

            /* RIGHT_BRACKET */
            if (str[i] == ']')
            {
                i++;
                return { RIGHT_BRACKET, "" };
            }
            
            /* STRING */

            Tok token;
            token.type = STRING;
            token.value = "";

            /* with quotes*/
            if (str[i] == '"')
            {
                i++;
                while(i < str.size() && str[i] != '"' && str[i] != '\n')
                    token.value += str[i++];

                if ( str[i] < str.size() )
                    i++;

                return token;
            }
            /* whithout quotes*/
            else
            {
                while( i < str.size() && str[i] != '\n' 
                                    && str[i] != '=' 
                                    && str[i] != '[' 
                                    && str[i] != ']'
                                    && str[i] != '"'
                                    && str[i] != ';'
                                    && str[i] != '#' )
                token.value += str[i++];

                return token;
            }


            return { END, "" };
        }

        #ifdef DEBUG
            std::string toktostr(const Tok& tok)
            {
                std::string toknames[] = {"newline", "string", "equal", "left_bracket", "right_bracket", "end"};

                if(tok.type == STRING)
                    return (toknames[tok.type] + " -> " + "(" + tok.value + ")");
                else
                    return (toknames[tok.type]);
            }
        #endif
    }
}

