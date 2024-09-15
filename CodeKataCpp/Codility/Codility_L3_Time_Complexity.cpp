#include "../Codility_L3_Time_Complexity.h"

// https://app.codility.com/programmers/lessons/3-time_complexity/

// EASY
// FrogJmp
// Count minimal number of jumps from position X to Y.
int frogjmp_solution(int X, int Y, int D) {

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
int permmissingelem_solution(std::vector<int>& A)
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
int tape_quilibrium_usolution(std::vector<int>& A)
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