// https://app.codility.com/programmers/lessons/8-leader/

#include "L8_Leader.h"
#include <stack>
#include <algorithm>

namespace Codility {

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
		for (size_t i = 0; i < A.size(); ++i){
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