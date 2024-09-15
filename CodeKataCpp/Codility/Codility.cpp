#include "Codility.h"

namespace Codility {

    void runCodilityTests()
    {
        std::string S = "CAGCCTA";
        std::vector<int> P = { 2, 5, 0 };
        std::vector<int> Q = { 5, 4, 6 };
        std::vector<int> genomic_range_result = genomicRangeQuery(S, P, Q);

        std::vector<int> min_avg = { 4, 2, 2, 5, 1, 5, 8 };
        int min_avg_result = minAvgTwoSlice(min_avg);
    }

}