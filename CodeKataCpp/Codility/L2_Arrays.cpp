#include "L2_Arrays.h"
#include <unordered_set>
#include <algorithm>

// https://app.codility.com/programmers/lessons/2-arrays/

namespace Codility {
    // EASY
    // CyclicRotation
    // Rotate an array to the right by a given number of steps.
    std::vector<int> cyclicRotation(std::vector<int>& A, int K)
    {
        if (A.empty()) return A;
        size_t x = K % A.size();
        if (x == 0) return A;
        std::rotate(A.rbegin(), A.rbegin() + x, A.rend());
        return A;
    }

    // EASY
    // OddOccurrencesInArray
    // Find value that occurs in odd number of elements.
    int oddOccurrencesInArray(std::vector<int>& A)
    {
        std::unordered_set<int> x;
        std::for_each(A.begin(), A.end(), [&](int item) {
            if (x.find(item) == x.end())
            {
                x.insert(item);
            }
            else
            {
                x.erase(item);
            }
            });
        return *x.begin();
    }
}