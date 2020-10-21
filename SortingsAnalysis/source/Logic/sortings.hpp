#include <cstddef> 

template <typename T>
class Sorting {

public:
    virtual void operator() (T* array, std::size_t size) const = 0;
};

template <typename T>
class BubbleSort : public Sorting<T> {

public:
    virtual void operator() (T* array, std::size_t size) const override;
};

template <typename T>
class Qsort : public Sorting<T> {

public:
    virtual void operator() (T* array, std::size_t size) const override;

private:
    static int comparator(const void* valA, const void* valB);
};

template <typename T>
class MergeSort : public Sorting<T> {

public:
    virtual void operator() (T* array, std::size_t size) const override;

private:
    static T* CopyArray (T* arrSource, T* arrRec, int num);
};

template <typename T>
class SelectionSort : public Sorting<T> {

public:
    virtual void operator() (T* array, std::size_t size) const override;
};

#include <stdlib.h>

template <typename T>
void BubbleSort<T>::operator() (T* array, std::size_t size) const {
    
    for (int i = 1; i < size; ++i)
        for (int j = 0; j < size - i; ++j) {
            if (array[j + 1] < array[j]) {
                T buf = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buf;
            }

        }
}

template <typename T>
void Qsort<T>::operator() (T* array, std::size_t size) const {

    qsort (array, size, sizeof(T), comparator);    

}

template <typename T>
int Qsort<T>::comparator(const void* valA, const void* valB) {

    return (*(T*) valA < *(T*) valB) ? -1 : 1;
}

template <typename T>
void MergeSort<T>::operator() (T* array, std::size_t size) const {
 
    if (size == 1)
        return;
 
    std::size_t sizeLeft = size / 2;
    T* left = array;
     
    std::size_t sizeRight = size / 2 + size % 2;
    T* right = array + sizeLeft;
 
    operator() (left, sizeLeft);
    operator() (right, sizeRight);
 
    int leftIndx = 0; 
    int rightIndx = 0;
    int mainIndx = 0; 
 
    T* arrBuf = new T[size];
 
    while (leftIndx < sizeLeft || rightIndx < sizeRight) {
 
        if (leftIndx >= sizeLeft) {
 
            arrBuf[mainIndx] = right[rightIndx];
            mainIndx++; rightIndx++;
 
        } else if (rightIndx >= sizeRight) {
 
           arrBuf[mainIndx] = left[leftIndx];
           mainIndx++; leftIndx++;
 
        } else if (right[rightIndx] < left[leftIndx]) {
 
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
T* MergeSort<T>::CopyArray (T* arrSource, T* arrRec, int num) {
 
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



