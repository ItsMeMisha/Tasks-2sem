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
SortingsAnalyzerClass<T>::SortingsAnalyzerClass(const SortingsAnalyzerClass<T>& initObj) : data(initObj.data) {};

template <typename T>
bool SortingsAnalyzerClass<T>::operator< (const SortingsAnalyzerClass& rightOp) {

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



