//#include "sortings.hpp"
#include <stdlib.h>

template <typename T>
void BubbleSort<T>::operator() (T* array, std::size_t size) const {
    
    for (int i = 1; i < size; ++i)
        for (int j = 0; j < size - i; ++j)
            if (array[j + 1] < array[j]) {
                T buf = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buf;
            }
}

template <typename T>
void Qsort<T>::operator() (T* array, std::size_t size) const {

    qsort (array, size, sizeof(T), comparator);    

}

template <typename T>
int Qsort<T>::comparator(const void* valA, const void* valB) const {

    return (*(T*) valA < *(T*) valB) ? -1 : 1;
}

template <typename T>
void MergeSort<T>::operator() (T* array, std::size_t size) const {
 
    if (size == 1)
        return array;
 
    std::size_t sizeLeft = size / 2;
    T* left = array;
     
    std::size_t sizeRight = size / 2 + size % 2;
    T* right = array + sizeLeft;
 
    MergeSort (left, sizeLeft);
    MergeSort (right, sizeRight);
 
    int leftIndx = 0; 
    int rightIndx = 0;
    int mainIndx = 0; 
 
    int* arrBuf = new int[size];
 
    while (leftIndx < sizeLeft || rightIndx < sizeRight) {
 
        if (leftIndx >= sizeLeft) {
 
            arrBuf[mainIndx] = right[rightIndx];
            mainIndx++; rightIndx++;
 
        } else if (rightIndx >= sizeRight) {
 
           arrBuf[mainIndx] = left[leftIndx];
           mainIndx++; leftIndx++;
 
        } else if (left[leftIndx] > right[rightIndx]) {
 
            arrBuf[mainIndx] = right[rightIndx];
            mainIndx++; rightIndx++;
 
        } else {
 
            arrBuf[mainIndx] = left[leftIndx];
            mainIndx++; leftIndx++;
 
        }
    }
 
    array = CopyArray (arrBuf, array, size);
    delete[] arrBuf;
}

template <typename T>
T* MergeSort<T>::CopyArray (T* arrSource, T* arrRec, int num) const {
 
    for (int i = 0; i < num; ++i)
        arrRec[i] = arrSource[i];
 
    return arrRec;
}
 
template <typename T>
void SelectionSort<T>::operator() (T* array, std::size_t size) const {

    for (int i = 0; i < size - 1; ++i) {

        std::size_t curMinIndx = i;
        for (int j = i + 1; j < size; ++j)
            if (array[j] < array[curMinIndx])
                curMinIndx = j;

        if (curMinIndx != i) {
            
            T buf = array[curMinIndx];
            array[curMinIndx] = array[i];
            array[i] = buf;
        }
    }
}



