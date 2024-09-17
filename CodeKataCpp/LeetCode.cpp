#include "LeetCode.h"
#include <unordered_map>
#include <algorithm>

namespace LeetCode {

	// 1. https://leetcode.com/problems/two-sum/
	// EASY

	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		if (nums.size() == 2) return std::vector<int>{0, 1};

		std::unordered_map<int, int> um;
		um.insert({ nums[0], 0 });

		for (size_t i = 1; i < nums.size(); ++i) {
			int diff = target - nums[i];
			auto search = um.find(diff);
			if (search != um.end()) {
				return std::vector<int>{search->second, static_cast<int>(i)};
			}
			um.insert({ nums[i], i });
		}

		return std::vector<int>{0, 1};
	}


	// https://leetcode.com/problems/median-of-two-sorted-arrays
	// 4. Median of Two Sorted Arrays
	// O(M+N)
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		size_t elements = nums1.size() + nums2.size();
		std::vector<int> x;
		x.reserve(elements);
		size_t idx1 = 0;
		size_t idx2 = 0;
		// Make one vector consisting of both vectors in a sorted manner.
		while (idx1 < nums1.size() || idx2 < nums2.size()) {
			bool hasBothElements = idx1 < nums1.size() && idx2 < nums2.size();
			if (hasBothElements) {
				int el1 = nums1[idx1];
				int el2 = nums2[idx2];
				if (el1 < el2) { x.push_back(el1); ++idx1; } // Add element from 1st
				else if (el2 < el1) { x.push_back(el2); ++idx2; } // Add element from 2nd
				else { x.push_back(el1); ++idx1; x.push_back(el2); ++idx2; } // Add both elements
			}
			else { // no more elements from 1st or 2nd so add rest of the elements.
				if (idx1 < nums1.size()) { x.push_back(nums1[idx1]); ++idx1; }
				else { x.push_back(nums2[idx2]); ++idx2; }
			}

		}

		if (elements % 2 != 0) {
			return x[(elements / 2)];
		}
		else
		{
			double el1 = static_cast<double>(x[(elements / 2) - 1]);
			double el2 = static_cast<double>(x[(elements / 2)]);
			return (el1 + el2) / 2;
		}
	}

}