#include <cstddef>
#include "sortings.hpp"

template <typename T>
class SortingsAnalyzerClass {

private:
    static unsigned int numOfComparisons;
    static unsigned int numOfAssignments;

public:
 
    SortingsAnalyzerClass();
    SortingsAnalyzerClass(const T& initValue);
    SortingsAnalyzerClass(T&& initValue);
    SortingsAnalyzerClass(const SortingsAnalyzerClass& initObj);
    SortingsAnalyzerClass(SortingsAnalyzerClass&& initObj);

    T data;

    bool operator< (const SortingsAnalyzerClass& rightOp);
    SortingsAnalyzerClass& operator= (const SortingsAnalyzerClass& rightOp);
    SortingsAnalyzerClass& operator= (const T& rightOp);
    SortingsAnalyzerClass& operator= (SortingsAnalyzerClass&& rightOp);
    SortingsAnalyzerClass& operator= (T&& rightOp);


    static unsigned int getNumOfComparisons();
    static unsigned int getNumOfAssignments();
    static void resetNumOfComparisons();
    static void resetNumOfAssignments();
    static void resetStaticMembers();
};

struct Results {

    std::size_t size = 0;
    unsigned int numOfComparisons = 0;
    unsigned int numOfAssignments = 0;
};

void generateArray (SortingsAnalyzerClass<int>* array, std::size_t size);
Results CountActionsDuringSorting (std::size_t size, const Sorting<SortingsAnalyzerClass<int>>& sort); 
Results* AnalyzeSorting (const std::size_t startSize, const std::size_t step, const std::size_t numOfSteps, const Sorting<SortingsAnalyzerClass<int>>& sort, Results* arrayOfResults);

#include <stdlib.h>

template <typename T>
unsigned int SortingsAnalyzerClass<T>::numOfComparisons = 0;

template <typename T>
unsigned int SortingsAnalyzerClass<T>::numOfAssignments = 0;

template <typename T>
SortingsAnalyzerClass<T>::SortingsAnalyzerClass() : data(T()) {};

template <typename T>
SortingsAnalyzerClass<T>::SortingsAnalyzerClass(const T& initValue) : data(initValue) {}

template <typename T>
SortingsAnalyzerClass<T>::SortingsAnalyzerClass(T&& initValue) : data(initValue) {}

template <typename T>
SortingsAnalyzerClass<T>::SortingsAnalyzerClass(const SortingsAnalyzerClass<T>& initObj) : data(initObj.data) {};

template <typename T>
SortingsAnalyzerClass<T>::SortingsAnalyzerClass(SortingsAnalyzerClass<T>&& initObj) : data(initObj.data) {};

template <typename T>
bool SortingsAnalyzerClass<T>::operator< (const SortingsAnalyzerClass<T>& rightOp) {

    ++numOfComparisons;
    return (data < rightOp.data);
}

template <typename T>
SortingsAnalyzerClass<T>& SortingsAnalyzerClass<T>::operator= (const SortingsAnalyzerClass<T>& rightOp) {
       
    ++numOfAssignments;
    data = rightOp.data;
    return *this;
}

template <typename T>
SortingsAnalyzerClass<T>& SortingsAnalyzerClass<T>::operator= (const T& rightOp) {

    data = rightOp;
    return *this;
}

template <typename T>
SortingsAnalyzerClass<T>& SortingsAnalyzerClass<T>::operator= (SortingsAnalyzerClass&& rightOp) {
    data = rightOp.data;
}

template <typename T>
SortingsAnalyzerClass<T>& SortingsAnalyzerClass<T>::operator= (T&& rightOp) {
    data = rightOp;
}

template <typename T>
unsigned int SortingsAnalyzerClass<T>::getNumOfComparisons() {
        
    return numOfComparisons;
}

template <typename T>
unsigned int SortingsAnalyzerClass<T>::getNumOfAssignments() {

    return numOfAssignments;
}

template <typename T>
void SortingsAnalyzerClass<T>::resetNumOfComparisons() {

    numOfComparisons = 0;
}

template <typename T>
void SortingsAnalyzerClass<T>::resetNumOfAssignments() {

    numOfAssignments = 0;
}

template <typename T>
void SortingsAnalyzerClass<T>::resetStaticMembers() {

    resetNumOfComparisons();
    resetNumOfAssignments();
}

SortingsAnalyzerClass<int>* generateArray (std::size_t size) {

    SortingsAnalyzerClass<int>* array = new SortingsAnalyzerClass<int>[size];
    for (std::size_t i = 0; i < size; ++i)
        array[i] = rand() % 1024 + 8;

    return array;
}

Results CountActionsDuringSorting (std::size_t size, const Sorting<SortingsAnalyzerClass<int>>& sort) {

    SortingsAnalyzerClass<int>* array = generateArray (size);
    sort(array, size);
    delete[] array;

    Results results = {size, SortingsAnalyzerClass<int>::getNumOfComparisons(), SortingsAnalyzerClass<int>::getNumOfAssignments()};
    SortingsAnalyzerClass<int>::resetStaticMembers();

    return results;
}

Results* AnalyzeSorting (const std::size_t startSize, const std::size_t step, const std::size_t numOfSteps, const Sorting<SortingsAnalyzerClass<int>>& sort, Results* arrayOfResults) {

    for (int i = 0; i < numOfSteps + 1; ++i)
        arrayOfResults[i] = CountActionsDuringSorting (startSize + i*step, sort);

    return arrayOfResults;
}



