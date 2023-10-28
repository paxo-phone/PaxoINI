![](logo.jpeg)

PaxoINI is a library for analysing INI files. It was developed as part of the Paxo project to provide an INI interface to PaxOS.

- [Examples](#examples)
  - [Read](#read)
  - [Write](#write)
  - [Read and Write](#read-and-write)
- [License](#license)
- [Contact](#contact)
- [Contributors](#contributors)


# Examples

## Read

```c++
#include "ini.hpp"

...

std::string data = "\n \
    [section] \n\
    key=value \n\
";

try
{
    // initializing document
    ini::doc doc(data);
    
    // You can also use
    /*
        ini::doc doc;
        doc.parse(data);
    */

    // get "key" value
    std::cout << doc.get("section", "key") << std::endl;

    // output: value

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
```

## Write

```c++
#include "ini.hpp"

try
{
    std::ofstream output("output.txt");

    /* Intialize INI document */
    ini::doc document;
    
    /* Set values */
    document.set("section-1", "key-1", "value-1");
    document.set("section-1", "key-2", "value-2");

    document.set("section-2", "key-1", "value-1");
    document.set("section-2", "key-2", "value-2");

    /* Write it to output */
    output << document.tostring() << std::endl;

    // output: you now have a file containing the specified data in INI format

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
```

## Read and Write

```c++
#include "ini.hpp"

...

std::string data = "\n \
    [section] \n\
    key=value \n\
";

try
{
    std::ofstream output("output.txt");

    /* Intialize INI document */
    ini::doc document(data);
    
    /* Add value */
    document.set("section", "key2", "value2");

    /* Write it to output */
    output << document.tostring() << std::endl;

    // output: you now have a file containing the specified data in INI format

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
```

# License

This project is distributed under the CC0 1.0 Universal License. See [LICENSE](/LICENSE) for more information.

# Contact

You can contact us via our [Website](https://www.paxo.fr) or our [Discord](https://discord.com/invite/MpqbWr3pUG) server

# Contributors 

<a href="https://github.com/paxo-phone/PaxoINI/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=paxo-phone/PaxoINI" />
</a>