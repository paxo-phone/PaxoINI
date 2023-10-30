#ifndef __INI_PARSER__
#define __INI_PARSER__

#ifdef DEBUG
    #include <iostream>
#endif

#if defined(OLD_PAXO) || defined(NEW_PAXO)
    #include "../../interface/filestream.hpp"
#endif


#include <string>
#include <unordered_map>

namespace ini
{
    /**
     * @brief This class represents an INI document.
    */
    class doc
    {
        public:

            /**
             * @brief Constructs an empty INI document.
             */
            doc();

            /**
             * @brief Constructs an INI document from a string.
             * @param str The string containing the INI data.
             */
            doc(const std::string& str);

            #if defined(OLD_PAXO) || defined(NEW_PAXO)

            /**
             * @brief Constructs an INI document from a filestream.
             * @param filestream The filestream containing the INI data.
            */
            doc(const storage::FileStream& filstream);

            #endif

            /**
             * @brief Parse an INI document from a string.
             * @param str The string containing the INI data to parse.
             */
            void parse(const std::string& str);
        
            /**
             * @brief Gets the value associated with a key in a section.
             * @param section The section name.
             * @param key The key name.
             * @return The value associated with the key in the specified section.
             */
            std::string get(const std::string& section, const std::string& key);

            /**
             * @brief Sets the value associated with a key in a section.
             * @param section The section name.
             * @param key The key name.
             * @param value The value to set for the key in the specified section.
             */
            void set(const std::string& section, const std::string& key, const std::string& value);

            /**
             * @brief Clears the contents of the INI document.
             */
            void clear(void);

            /**
             * @brief Converts the INI document to a string representation.
             * @return The INI document as a string.
            */
            std::string tostring(void);

            #ifdef DEBUG
                friend std::ostream& operator<<(std::ostream& os, doc& document);
            #endif

        private:

            std::unordered_map<std::string, std::unordered_map<std::string, std::string>> data;

    };
}

#endif /* __INI_PARSER__ */
