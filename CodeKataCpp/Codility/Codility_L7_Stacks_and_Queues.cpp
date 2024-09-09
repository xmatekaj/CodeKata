// https://app.codility.com/programmers/lessons/7-stacks_and_queues/

#include <stack>
#include <string>
#include <vector>
using namespace std;

// EASY
// Brackets
// Determine whether a given string of parentheses(multiple types) is properly nested.
int brackets_solution(string& S) {

    if (S.length() == 0) return 1;
    if (S.length() % 2 != 0) return 0;

    stack<char> x;

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

    if (x.size() > 0) return 0;

    return 1;
}


// EASY
// Fish
// N voracious fish are moving along a river.Calculate how many fish are alive.

// TODO

// EASY
// Nesting
// Determine whether a given string of parentheses(single type) is properly nested.
int neting_solution(string& S) {
    if (S.length() == 0) return 1;
    if (S.length() % 2 != 0) return 0;

    stack<char> x;

    for (size_t i = 0; i < S.length(); ++i)
    {
        if (S[i] == ')') {
            if (x.empty()) return 0;
            if (x.top() != '(')  return 0;
            x.pop();
        }
        else {
            x.push(S[i]);
        }
    }

    if (x.empty()) return 1;

    return 0;
}

// EASY
// StoneWall
// Cover "Manhattan skyline" using the minimum number of rectangles.
int stone_wall_solution(vector<int>& H) {
    stack<int> s;
    int counter = 0;
    int height = 0;
    int currentHeight = 0;
    for (size_t i = 0; i < H.size(); ++i)
    {
        currentHeight = H[i];

        if (s.empty()) {
            s.push(currentHeight);

            ++counter;
            height += currentHeight;
        }
        else
        {
            if (height == currentHeight)
            {
                // do nothing
            }
            else if (height < currentHeight)
            {
                int diff = currentHeight - height;
                ++counter;
                s.push(diff);
                height += diff;
            }
            else // height > currentHeight
            {
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

            }
        }
    }
    return counter;
}
