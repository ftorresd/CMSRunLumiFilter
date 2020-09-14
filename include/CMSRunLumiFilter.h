#include <string>
#include "json.hpp"
using nlohmann::json;

namespace CMSRunLumi
{
    class CMSRunLumiFilter
    {
    private:
        json good_runs_lumis_json;
        int foo;

    public:
        CMSRunLumiFilter(string);
        bool isGoodRun(int, int);
    };

    CMSRunLumiFilter::CMSRunLumiFilter(string inputJsonFile)
    {
        std::ifstream ifs(inputJsonFile);
        good_runs_lumis_json = json::parse(ifs);

    }

    bool CMSRunLumiFilter::isGoodRun(int runNumber, int lumi)
    {
        string test_run = std::to_string(runNumber); // the standard is: CMS Lumi JSON have run number as strings
        int test_lumi = lumi;

        bool is_good_run_lumi = false;

        if (this->good_runs_lumis_json.find(test_run) != this->good_runs_lumis_json.end())
        {
            for (auto const &interval : this->good_runs_lumis_json[test_run])
            {
                int low = interval.front();
                int high = interval.back();
                if (test_lumi >= low && test_lumi <= high)
                {
                    is_good_run_lumi = true;
                }
            }
        }
        return is_good_run_lumi;
    }

} // namespace CMSRunLumi