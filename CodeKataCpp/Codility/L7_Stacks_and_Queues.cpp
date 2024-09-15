#include "L7_Stacks_and_Queues.h"

// https://app.codility.com/programmers/lessons/7-stacks_and_queues/

#include <stack>
#include <algorithm>

namespace Codility {
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