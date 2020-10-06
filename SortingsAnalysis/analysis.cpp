#include <stdio.h>
#include "calculations.hpp"

int main() {

    Results* res = new Results[5];
    AnalyzeSorting (10, 10, 4, Qsort<SortingsAnalyzerClass<int>>(), res);
    for (int i = 0; i < 5; ++i)
        printf ("%d %d %d\n", res[i].size, res[i].numOfComparisons, res[i].numOfAssignments);

    delete[] res;
    return 0;
}
