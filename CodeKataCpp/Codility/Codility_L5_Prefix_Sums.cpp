#include <vector>
#include <algorithm>

// https://app.codility.com/programmers/lessons/5-prefix_sums/
// EASY
// PassingCars
// Count the number of passing cars on the road.

// 100%
int passing_cars_solution(std::vector<int>& A) {
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
int count_div_solution(int A, int B, int K) {
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

// A DNA sequence can be represented as a string consisting of the letters A, C, Gand T, which correspond to the types of successive nucleotides in the sequence.Each nucleotide has an impact factor, which is an integer.Nucleotides of types A, C, Gand T have impact factors of 1, 2, 3 and 4, respectively.You are going to answer several queries of the form : What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence ?
// The DNA sequence is given as a non - empty string S = S[0]S[1]...S[N - 1] consisting of N characters.There are M queries, which are given in non - empty arrays P and Q, each consisting of M integers.The K - th query(0 ? K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K](inclusive).
// 	For example, consider string S = CAGCCTA and arrays P, Q such that :
// P[0] = 2    Q[0] = 4
// P[1] = 5    Q[1] = 5
// P[2] = 0    Q[2] = 6
// The answers to these M = 3 queries are as follows :
// The part of the DNA between positions 2 and 4 contains nucleotides G and C(twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
// The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
// The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
// Write a function :
// vector<int> solution(string & S, vector<int> &P, vector<int> &Q);
// that, given a non - empty string S consisting of N characters and two non - empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.
// Result array should be returned as an array of integers.
// For example, given the string S = CAGCCTA and arrays P, Q such that :
// P[0] = 2    Q[0] = 4
// P[1] = 5    Q[1] = 5
// P[2] = 0    Q[2] = 6
// the function should return the values[2, 4, 1], as explained above.
// Write an efficient algorithm for the following assumptions :
// N is an integer within the range[1..100, 000];
// M is an integer within the range[1..50, 000];
// each element of arrays Pand Q is an integer within the range[0..N - 1];
// P[K] ? Q[K], where 0 ? K < M;
// string S consists only of upper - case English letters A, C, G, T.


// MEDIUM
// MinAvgTwoSlice
// Find the minimal average of any slice containing at least two elements.

