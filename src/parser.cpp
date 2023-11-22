#include <string>
#include <unordered_map>
#include <stdexcept>

#include "parser.hpp"
#include "lexer.hpp"
#include "utils.hpp"

#if ESP32
    #include "../../interface/filestream.hpp"
#endif

namespace ini
{
    doc::doc()
    {}

    doc::doc(const std::string& str)
    {
        this->parse(str);
    }
    
    #if defined(OLD_PAXO) || defined(NEW_PAXO)

    /**
     * @brief Constructs an INI document from a filestream.
     * @param filestream The filestream containing the INI data.
    */
    doc(const storage::FileStream& filstream)
    {
        this->parse(filestream.read());
    }

    #endif
    

    std::string doc::get(const std::string& section, 
                         const std::string& key)
    {
        return this->data[section][key];
    }

    void doc::set(const std::string& section, 
                  const std::string& key, 
                  const std::string& value)
    {
        this->data[section][key] = value;
    }

    void doc::clear(void)
    {
        this->data.clear();
    }

    void doc::parse(const std::string& str)
    {
        int i = 0;

        lexer::Tok tok; 
        std::string currsection = "";

        while(1)
        {
            tok = lexer::nexttok(str, i);

            if( tok.type == lexer::END )
                break;

            if( tok.type == lexer::NEWLINE )
            {
                continue;
            }

            if(tok.type == lexer::LEFT_BRACKET)
            {
                tok = lexer::nexttok(str, i);

                if ( tok.type != lexer::STRING )
                    throw std::logic_error("Expected STRING after LEFT_BRACKET");
                
                if ( lexer::nexttok(str, i).type != lexer::RIGHT_BRACKET )
                    throw std::logic_error("Expected RIGHT_BRACKET after LEFT_BRACKET and STRING");
                
                if ( lexer::nexttok(str, i).type != lexer::NEWLINE )
                    throw std::logic_error("Expected NEWLINE after LEFT_BRACKET, STRING and RIGHT_BRACKET");
                
                currsection = tok.value;

                continue;
            }

            if(tok.type == lexer::STRING)
            {
                std::string key = tok.value;

                if ( lexer::nexttok(str, i).type != lexer::EQUAL )
                    throw std::logic_error("Expected EQUAL after STRING");

                lexer::Tok valuetok = lexer::nexttok(str, i);
                if( valuetok.type != lexer::STRING)
                    throw std::logic_error("Expected STRING after STRING and EQUAL");
                
                if( lexer::nexttok(str, i).type != lexer::NEWLINE)
                    throw std::logic_error("Expected NEWLINE after STRING, EQUAL and STRING");
                
                this->data[currsection][key] = valuetok.value;

                continue;
            }

        }

    }

    std::string doc::tostring(void)
    {
        std::string o = "";

        for(auto& section: this->data) { // iterate through sections
            o += "[" + section.first + "]" + "\n";
            for(auto& entry: section.second) { // iterate through section entries
                o += entry.first + "=" + entry.second + '\n';
            }
        }

        return o;
    }


    #ifdef DEBUG
        
        std::ostream& operator<<(std::ostream& os, doc& document)
        {
            os << document.tostring();
            return os;
        }

    #endif

}
