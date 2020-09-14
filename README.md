## CMS Run:Lumi Filter

**A dead simple 💀🎯 CMS Run:Lumi filter for vanilla [ROOT](https://root.cern.ch/) macros.** Should work in more complex implementations...

## Usage

Just include the `"include/CMSRunLumiFilter.h"`, create a `CMSRunLumiFilter` object (providing the reference JSON file). 

## Example 

As in [`test.C`](https://github.com/ftorresd/CMSRunLumiFilter/blob/master/test.C):

```C++
#include "include/CMSRunLumiFilter.h"
using namespace CMSRunLumi;

void test()
{
    // create a CMS Filter object
    CMSRunLumiFilter runFilter = CMSRunLumiFilter("etc/golden_json_2016.txt");

    // good run:lumi example
    // run: 273404
    // lumi: 3
    if (runFilter.isGoodRun(273404, 3) == true)
    {
        std::cout << "Good run:lumi! \u2705" << std::endl;
    }

    // bad run:lumi example
    // run: 9999
    // lumi: 333
    if (runFilter.isGoodRun(9999, 333) == false)
    {
        std::cout << "Bad run:lumi! \u274C" << std::endl;
    }
}
```



## Credits

This is heavily dependent on `nlohmann/json` library.

https://github.com/nlohmann/json
