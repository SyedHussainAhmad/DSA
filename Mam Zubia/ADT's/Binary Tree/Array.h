#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>

template <typename T>
class Array {
private:
    T* arr;
    int capacity;
    int noOfElements;

    // Function to resize the array when needed
    void resize()
    {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < noOfElements; ++i)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    // Constructor
    Array(int initialCapacity = 10) : capacity(initialCapacity), noOfElements(1)
    {
        arr = new T[capacity];
    }

    // Copy constructor
    Array(const Array& other) : capacity(other.capacity), noOfElements(other.noOfElements)
    {
        arr = new T[capacity];
        for (int i = 0; i < noOfElements; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    // Assignment operator
    Array& operator=(const Array& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] arr;

        capacity = other.capacity;
        noOfElements = other.noOfElements;
        arr = new T[capacity];
        for (int i = 0; i < noOfElements; ++i)
        {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // Destructor
    ~Array()
    {
        if (arr)
            delete[] arr;
    }

    // Access operator (const version)
    const T& operator[](int index) const
    {
        if (index < 0 || index >= noOfElements)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Access operator (non-const version)
    T& operator[](int index)
    {
        if (index < 0 || index >= noOfElements)
        {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Function to add a new element
    void add(const T& element)
    {
        if (noOfElements == capacity)
        {
            resize();
        }
        arr[noOfElements++] = element;
    }

    // Function to get the number of elements
    int size() const {
        return noOfElements;
    }
    int getNoOfElement()
    {
        return noOfElements;
    }
    void setNoOfElement(int v)
    {
        noOfElements = v;
    }
    void swap(int source, int destination) {
        if (source < 0 || source >= noOfElements || destination < 0 || destination >= noOfElements) {
            throw std::out_of_range("Index out of range");
        }
        T temp = arr[source];
        arr[source] = arr[destination];
        arr[destination] = temp;
    }
    bool isEmpty()
    {
        if (noOfElements == 1)
            return true;
        return false;
    }
};

#endif // !ARRAY_H
