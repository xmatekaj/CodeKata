#include <unordered_set>
#include <vector>

// https://app.codility.com/programmers/lessons/6-sorting/

// EASY
// Distinct
// Compute number of distinct values in an array.



int distinct_solution(std::vector<int>& A) {
    std::unordered_set<int> s;
    for (size_t i = 0; i < A.size(); ++i)
    {
        s.insert(A[i]);
    }
    return static_cast<int>(s.size());
}

// EASY
// MaxProductOfThree
// Maximize A[P] * A[Q] * A[R] for any triplet(P, Q, R).

// TODO
// 33%
int max_product_of_three_solution(std::vector<int>& A) {
    int max1 = A[0];
    int max2 = A[1];
    int max3 = A[2];

    if (A.size() == 3) return max1 * max2 * max3;
    for (size_t i = 1; i < A.size(); ++i)
    {
        if (A[i] >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
    }
    return max1 * max2 * max3;
}

// EASY
// Triangle
// Determine whether a triangle can be built from a given set of edges.

// TODO
int triangle_solution(std::vector<int>& A) {
    // A[P] + A[Q] > A[R]
    // A[Q] + A[R] > A[P]
    // A[R] + A[P] > A[Q]
    // 0 ≤ P < Q < R < N
    std::vector<int> vec;
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (A[i] > 0) vec.push_back(A[i]);
    }
    if (vec.size() < 3) return 0;


    for (size_t P = 0; P < vec.size() - 2; ++P)
    {
        for (size_t Q = 1; Q < vec.size() - 1; ++Q)
        {
            if (Q == P) continue;

            for (size_t R = 2; R < vec.size(); ++R)
            {
                if (P == Q || P == R || Q == R) continue;
                bool condition1 = (long)vec[P] + (long)vec[Q] > vec[R];
                if (condition1) {
                    bool condition2 = (long)vec[Q] + (long)vec[R] > vec[P];
                    if (condition2) {
                        bool condition3 = (long)vec[R] + (long)vec[P] > vec[Q];
                        if (condition1 && condition2 && condition3) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


// MEDIUM
// NumberOfDiscIntersections
// Compute the number of intersections in a sequence of discs.
// TODO