#include <cstddef>

namespace myContainers {

    template <typename T>
    class Vector {
        
    public:
        Vector ();

        Vector (const Vector<T>& other);
        Vector (Vector<T>&& other);

        Vector (const std::size_t size, const T& value = T());

        ~Vector ();
        
        void push_back (const T& value);
        void push_back (T&& value);

        void pop_back ();

        std::size_t size ();
        std::size_t capacity ();

        T& operator[] (std::size_t indx);
        const T& operator[] (std::size_t indx) const;

    private:
        T* data = nullptr;
        std::size_t curSize = 0;
        std::size_t curCapacity = 0;
        const int capacityDelta = 10;

        void enlargeCapacity ();
        void reduceCapacity ();
        void checkSizeAndCapacity ();
        
    };
}
