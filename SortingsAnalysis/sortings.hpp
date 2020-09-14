class Sorting {

public:
    template <typename T>
    virtual void operator() (T* array, std::size_t size) const;
};

class BubbleSort : public Sorting {

public:
    template <typename T>
    virtual void operator() (T* array, std::size_t size) const override;
};

class Qsort : public Sorting {

public:
    template <typename T>
    virtual void operator() (T* array, std::size_t size) const override;
};

class MergeSort : public Sorting {

public:
    template <typename T>
    virtual void operator() (T* array, std::size_t size) const override;
};

class SelectionSort : public Sorting {

public:
    template <typename T>
    virtual void operator() (T* array, std::size_t size) const override;
};
