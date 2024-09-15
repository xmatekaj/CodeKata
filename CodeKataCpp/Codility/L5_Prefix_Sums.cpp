#include "L5_Prefix_Sums.h"
#include <string>
#include <algorithm>
#include <limits>

// https://app.codility.com/programmers/lessons/5-prefix_sums/
 
namespace Codility {
    // EASY
    // PassingCars
    // Count the number of passing cars on the road.
    int passingCars(std::vector<int>& A) {
        int x = 0;
        int numOfZeroes = 0;
        int threshold = 1000000000;
        std::for_each(A.begin(), A.end(), [&](int item) {
            if (item == 0) {
                ++numOfZeroes;
            }
            else { // == 1
                x += numOfZeroes;
                if (x > threshold) return -1;
            }
            });
        if (x > threshold) return -1;
        return x;
    }


    // MEDIUM
    // CountDiv
    // Compute number of integers divisible by k in range[a..b].
    int countDiv(int A, int B, int K) {
        int x = B / K;
        int y = A / K;
        if (A == B && A % K == 0) return 1;
        int res = x - y;
        if (A % K == 0) ++res;
        return res;
    }

    // MEDIUM
    // GenomicRangeQuery
    // Find the minimal nucleotide from a range of sequence DNA.
    std::vector<int> genomicRangeQuery(std::string& S, std::vector<int>& P, std::vector<int>& Q) {

        std::vector<std::vector<int>> prefixSums(4, std::vector<int>(S.length() + 1, 0));
        constexpr int NUM_OF_NUCLEOTIDES = 4;

        // calculate prefix sum for each of the nucleotides
        for (int i = 0; i < S.length(); ++i)
        {
            // copy previous values
            for (int nucleotide = 0; nucleotide < NUM_OF_NUCLEOTIDES; ++nucleotide)
            {
                prefixSums[nucleotide][i + 1] = prefixSums[nucleotide][i];
            }

            switch (S[i]) {
            case 'A': prefixSums[0][i + 1]++; break;
            case 'C': prefixSums[1][i + 1]++; break;
            case 'G': prefixSums[2][i + 1]++; break;
            default: prefixSums[3][i + 1]++; break;
            }
        }

        std::vector<int> result(P.size());
        for (int i = 0; i < P.size(); i++) {
            int start = P[i];
            int end = Q[i] + 1; // inclusive, thus +1

            for (int nucleotide = 0; nucleotide < NUM_OF_NUCLEOTIDES; ++nucleotide) {
                if (prefixSums[nucleotide][end] - prefixSums[nucleotide][start] > 0) {
                    result[i] = nucleotide + 1; //  nucleotide + 1 because A = 1 and prefixSums[0] indicates 'A'
                    break;
                }
            }
        }
        return result;
    }


    // MEDIUM
    // MinAvgTwoSlice
    // Find the minimal average of any slice containing at least two elements.
    // [4, 2, 2, 5, 1, 5, 8] -> 1
    int minAvgTwoSlice(std::vector<int>& A)
    {
        size_t N = A.size();
        if (N < 2) return 0;

        double min_avg = std::numeric_limits<double>::max();
        size_t min_start_position = 0;

        // Check slices of length 2
        for (size_t i = 0; i < N - 1; ++i) {
            double avg = (A[i] + A[i + 1]) / 2.0;
            if (avg < min_avg) {
                min_avg = avg;
                min_start_position = i;
            }
        }

        // Check slices of length 3
        for (size_t i = 0; i < N - 2; ++i) {
            double avg = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
            if (avg < min_avg) {
                min_avg = avg;
                min_start_position = i;
            }
        }

        return static_cast<int>(min_start_position);
    }
}