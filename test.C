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