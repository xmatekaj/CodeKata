#include "CodilityLessons.h"
#include <unordered_set>
#include <algorithm>
#include <stack>

namespace Codility {
    namespace Lessons {
        namespace Arrays {
            // https://app.codility.com/programmers/lessons/2-arrays/
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
        
        namespace TimeComplexity {
            // https://app.codility.com/programmers/lessons/3-time_complexity/

            // EASY
            // FrogJmp
            // Count minimal number of jumps from position X to Y.
            int frogJmp(int X, int Y, int D) {

                int position = X;
                int destination = Y;
                int jump_distance = D;

                int distance = destination - position;
                int jumps = distance % jump_distance != 0 ?
                    distance / jump_distance + 1 :
                    distance / jump_distance;
                return jumps;
            }

            // EASY
            // PermMissingElem
            // Find the missing element in a given permutation.
            int permMissingElem(std::vector<int>& A)
            {
                int last_element = static_cast<int>(A.size() + 1);
                long expected_sum = (last_element * (last_element + 1)) / 2;
                long sum = 0;
                std::for_each(A.begin(), A.end(), [&sum](int x) { sum += x; });
                return expected_sum - sum;
            }

            // EASY
            // TapeEquilibrium
            // Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
            int tapeEquilibrium(std::vector<int>& A)
            {
                size_t length = A.size();
                long sum1 = A[0];
                long sum2 = 0;
                std::for_each(A.begin(), A.end(), [&sum2](int x) { sum2 += x; });
                long diff = abs(sum1 - sum2);
                for (size_t i = 1; i < length - 1; ++i)
                {
                    sum1 += A[i];
                    sum2 -= A[i];
                    long new_diff = abs(sum1 - sum2);
                    if (new_diff < diff) diff = new_diff;
                }
                return static_cast<int>(diff);
            }

        }
        
        namespace CountingElements {
            // https://app.codility.com/programmers/lessons/4-counting_elements/

            // EASY
            // FrogRiverOne
            // Find the earliest time when a frog can jump to the other side of a river.
            int frogRiverOne(int X, std::vector<int>& A) {
                std::unordered_set<int> xx;
                for (size_t i = 0; i < A.size(); ++i) {
                    xx.insert(A[i]);
                    if (X == static_cast<int>(xx.size()))
                        return static_cast<int>(i);
                }
                return -1;
            }

            // EASY
            // PermCheck
            // Check whether array A is a permutation.
            int permCheck(std::vector<int>& A) {
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
            std::vector<int> maxCounters(int N, std::vector<int>& A) {
                int max = 0;
                int followMax = 0;
                std::vector<int> vec(N, 0);
                std::for_each(A.begin(), A.end(), [&](size_t x) {
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
            int missingInteger(std::vector<int>& A) {
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
        }
        
        namespace PrefixSums {
            // https://app.codility.com/programmers/lessons/5-prefix_sums/

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
        
        namespace Sorting {
            // https://app.codility.com/programmers/lessons/6-sorting/

            // EASY
            // Distinct
            // Compute number of distinct values in an array.
            int distinct(std::vector<int>& A) {
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
            int maxProductOfThree(std::vector<int>& A) {
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
            int triangle(std::vector<int>& A) {
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
        }
        
        namespace StacksAndQueues {
            // https://app.codility.com/programmers/lessons/7-stacks_and_queues/

            // EASY
            // Brackets
            // Determine whether a given string of parentheses(multiple types) is properly nested.
            int brackets(std::string& S) {

                if (S.length() == 0) return 1;
                if (S.length() % 2 != 0) return 0;

                std::stack<char> x;

                for (size_t i = 0; i < S.length(); ++i)
                {
                    switch (S[i]) {
                    case ')':
                        if (x.empty()) return 0;
                        if (x.top() != '(') return 0;
                        x.pop();
                        break;
                    case ']':
                        if (x.empty()) return 0;
                        if (x.top() != '[') return 0;
                        x.pop();
                        break;
                    case '}':
                        if (x.empty()) return 0;
                        if (x.top() != '{') return 0;
                        x.pop();
                        break;
                    default:
                        x.push(S[i]);
                        break;
                    }
                }

                if (x.empty()) return 1;

                return 0;
            }


            // EASY
            // Fish
            // N voracious fish are moving along a river. Calculate how many fish are alive.
            // TODO
            int fish(std::vector<int>& A, std::vector<int>& B) {
                // B
                // 0 represents a fish flowing upstream,
                // 1 represents a fish flowing downstream.
                return -1;
            }


            // EASY
            // Nesting
            // Determine whether a given string of parentheses(single type) is properly nested.
            int nesting(std::string& S) {
                if (S.length() == 0) return 1;
                if (S.length() % 2 != 0) return 0;

                std::stack<char> x;

                std::for_each(S.begin(), S.end(), [&x](char c)
                    {
                        if (c == ')') {
                            if (x.empty())		 return 0;
                            if (x.top() != '(')  return 0;
                            x.pop();
                        }
                        else {
                            x.push(c);
                        }
                    });

                if (x.empty()) return 1;

                return 0;
            }

            // EASY
            // StoneWall
            // Cover "Manhattan skyline" using the minimum number of rectangles.
            int stoneWall(std::vector<int>& H) {
                std::stack<int> s;
                int counter = 0;
                int height = 0;
                int currentHeight = 0;

                auto addCurrentHeight = [&]() {
                    s.push(currentHeight);

                    ++counter;
                    height += currentHeight;
                    };

                auto increaseHeigh = [&]() {
                    while (height > currentHeight)
                    {
                        int toRemove = s.top();
                        s.pop(); // remove first element
                        height -= toRemove;
                    }
                    if (height < currentHeight)
                    {
                        int diff = currentHeight - height;
                        ++counter;
                        height += diff;
                        s.push(diff);
                    }
                    };

                auto decreaseHeight = [&]() {
                    int diff = currentHeight - height;
                    ++counter;
                    s.push(diff);
                    height += diff;
                    };

                std::for_each(H.begin(), H.end(), [&](int h) {
                    currentHeight = h;

                    if (s.empty()) {
                        addCurrentHeight();
                    }
                    else {
                        if (height > currentHeight) {
                            increaseHeigh();
                        }
                        else if (height < currentHeight) {
                            decreaseHeight();
                        }
                    }
                    });

                return counter;
            }
        }
        
        namespace Leader {
            // https://app.codility.com/programmers/lessons/8-leader/

            // EASY
            // Dominator
            // Find an index of an array such that its value occurs at more than half of indices in the array.
            int dominator(std::vector<int>& A) {

                if (A.empty()) return -1;
                if (A.size() == 1) return 0;

                std::stack<int> s;
                std::for_each(A.begin(), A.end(), [&s](int item)
                    {
                        if (s.empty()) {
                            s.push(item);
                        }
                        else {
                            int top = s.top();
                            if (top != item) {
                                s.pop();
                            }
                            else {
                                s.push(item);
                            }
                        }
                    });

                size_t cnt = 0;
                int idx = -1;
                int element = s.top();
                for (size_t i = 0; i < A.size(); ++i) {
                    if (A[i] == element) {
                        if (idx < 0) idx = static_cast<int>(i);
                        ++cnt;
                    }
                }
                if (cnt > A.size() / 2) return idx;
                return -1;
            }

            // EASY
            // EquiLeader
            // Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
            int equiLeader(std::vector<int>& A)
            {
                size_t size = A.size();
                int candidate = 0;
                int count = 0;

                for (int num : A) {
                    if (count == 0) {
                        candidate = num;
                        count = 1;
                    }
                    else if (candidate == num) {
                        ++count;
                    }
                    else {
                        --count;
                    }
                }

                size_t total_count = std::count(A.begin(), A.end(), candidate);

                if (total_count <= size / 2) return 0;

                int equi_leaders = 0;
                size_t left_count = 0;

                // Count equi leaders
                for (size_t i = 0; i < size; ++i) {
                    if (A[i] == candidate) ++left_count;
                    // [4, 3, 4, 4, 4, 2]
                    bool is_leader_on_the_left = left_count > (i + 1) / 2;
                    size_t right_count = total_count - left_count;
                    bool is_leader_on_the_right = right_count > (size - i - 1) / 2;
                    if (is_leader_on_the_left && is_leader_on_the_right) {
                        equi_leaders++;
                    }
                }

                return equi_leaders;
            }
        }


    }
}