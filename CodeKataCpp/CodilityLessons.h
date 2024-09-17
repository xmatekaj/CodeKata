#pragma once

#include <vector>
#include <string>

namespace Codility {
    namespace Lessons {
        namespace Arrays {
            std::vector<int> cyclicRotation(std::vector<int>& A, int K);
            int oddOccurrencesInArray(std::vector<int>& A);
        }
        namespace TimeComplexity{
            int frogJmp(int X, int Y, int D);
            int permMissingElem(std::vector<int>& A);
            int tapeEquilibrium(std::vector<int>& A);
        }
        namespace CountingElements {
            int frogRiverOne(int X, std::vector<int>& A);
            int permCheck(std::vector<int>& A);
            std::vector<int> maxCounters(int N, std::vector<int>& A);
            int missingInteger(std::vector<int>& A);
        }
        namespace PrefixSums {
            int passingCars(std::vector<int>& A);
            int countDiv(int A, int B, int K);
            std::vector<int> genomicRangeQuery(std::string& S, std::vector<int>& P, std::vector<int>& Q);
            int minAvgTwoSlice(std::vector<int>& A);
        }
        namespace Sorting {
            int distinct(std::vector<int>& A);
            int maxProductOfThree(std::vector<int>& A);
            int triangle(std::vector<int>& A);
        }
        namespace StacksAndQueues {
            int brackets(std::string& S);
            int fish(std::vector<int>& A, std::vector<int>& B);
            int nesting(std::string& S);
            int stoneWall(std::vector<int>& H);
        }
        namespace Leader {
            int dominator(std::vector<int>& A);
            int equiLeader(std::vector<int>& A);
        }


    }
}