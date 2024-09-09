// https://app.codility.com/programmers/lessons/4-counting_elements/

#include <unordered_set>
#include <vector>
#include <algorithm>

// EASY
// FrogRiverOne
// Find the earliest time when a frog can jump to the other side of a river.
int frog_river_one_solution(int X, std::vector<int>& A) {
    std::unordered_set<int> xx;
    for (size_t i = 0; i < A.size(); ++i){
        xx.insert(A[i]);
        if (X == static_cast<int>(xx.size()))
            return static_cast<int>(i);
    }
    return -1;
}

// EASY
// PermCheck
// Check whether array A is a permutation.
int perm_check_solution(std::vector<int>& A) {
    std::unordered_set <int> x;
    size_t length = A.size();
    long sum = 0;
    auto expected_sum = static_cast<long>((length * (length + 1)) / 2);
    for (size_t i = 0; i < length; ++i)
    {
        sum += A[i];
        x.insert(A[i]);
    }

    if (sum == expected_sum && x.size() == length) return 1;
    return 0;
}

// MEDIUM
// MaxCounters
// Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximum.
//
// Example test:   (5, [3, 4, 4, 6, 1, 4, 4])
std::vector<int> max_counters_solution(int N, std::vector<int>& A) {
    int max = 0;
    int followMax = 0;
    std::vector<int> vec(N, 0);
    std::for_each(A.begin(), A.end(), [&](size_t x){
        size_t idx = x - 1;
        if (idx >= N) {
            max = followMax;
        }
        else {
            if (vec[idx] < max) vec[idx] = max + 1;
            else                ++vec[idx];

            if (followMax < vec[idx]) followMax = vec[idx];
        }
    });

    for (int i = 0; i < N; ++i)
    {
        if (vec[i] < max)
            vec[i] = max;
    }
    return vec;
}

// MEDIUM
// MissingInteger
// Find the smallest positive integer that does not occur in a given sequence.
int missing_integer_solution(std::vector<int>& A) {
    int result = 1;
    std::unordered_set<int> us;
    std::for_each(A.begin(), A.end(), [&us](int x) {us.insert(x); });
    std::for_each(A.begin(), A.end(), [&](int x) {
        if (x == result) {
            while (us.find(result) != us.end()) { ++result; }
        }
        });
    return result;
}