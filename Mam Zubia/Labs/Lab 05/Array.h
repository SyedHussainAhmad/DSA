#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

template<typename T >
class Array
{
private:
	T* data;
	int size;
	int capacity;
    void copyArray(Array* source, int* destination);
    void swap(T& num1, T& num2);
    double getSum(Array<T> nums);

public:
    Array();
	Array(int size);
	~Array();
	int getSize() const;
	void reSize(int newCapacity);
	T& operator[](int index);
	void insert(int index, const T& value);
	void remove(int index);
	void sort();
	void display();

    //Task 3:
    Array<T> findElements(Array<T> nums, int k);

    //Task 4:
    int maximumSum(Array<T> nums);
};


template<typename T>
void Array<T>::copyArray(Array* source, int* destination)
{
    for (int i = 0; i < source->size; i++)
    {
        destination[i] = source->data[i];
    }
}
template<typename T>
double getSum(Array<T> num)
{
    int sum = 0;
    for (int i = 0; i < num.size; i++)
    {
        sum += num.data[i];
    }
    return sum;
}

template<typename T>
void Array<T>::swap(T& num1, T& num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
}

template<typename T>
Array<T>::Array()
{
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
Array<T>::Array(int n)
{
    size = 0;
    capacity = n;
    data = new int[n];
}

template<typename T>
Array<T>::~Array()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }
}

template<typename T>
T& Array<T>::operator[](int index)
{
    return data[index];
}

template<typename T>
void Array<T>::insert(int index, const T& value)
{
    if (index == -1)
    {
        return;
    }
    if (size+1 > capacity)
    {
        reSize(size *2);
    }
    for (int i = size-1; i >= index; i--)
    {
        data[i + 1] = data[i];
    }

    data[index] = value;
    size++;
}

template<typename T>
void Array<T>::remove(int index)
{
    if (index == -1)
    {
        return;
    }
    for (int i = index; i <= size; i++)
    {
        data[index] = data[index+1];
    }

    capacity--;
}

template<typename T>
void Array<T>::sort()
{
    int i = size-1;
    int j = 0;
    while (i>= 0)
    {
        while (j<i)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
            j++;
        }
        i--;
    }
}

template<typename T>
void Array<T>::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ' ';
    }
}

template<typename T>
int Array<T>::getSize() const
{
    return size;
}

template<typename T>
void Array<T>::reSize(int cap)
{
    if (cap <= 0)
    {
        this->~Array();
        return;
    }
    int* temp = new int[cap];
    if (cap)
    {
        copyArray(this, temp);
    }
    this->~Array();
    data = temp;
    size = cap;
}

template<typename T>
Array<T> Array<T>::findElements(Array<T> nums, int k)
{
    Array<T> result(2);

    int left = data[0];
    int right = data[size-1];

    int i = size - 1, j = 0;
    while (j<i)
    {
        if (left+ right == key)
        {
            result.insert(0, data[j]);
            result.insert(1, data[i]);
        }
        else if (left + right > key)
        {
            i--;
        }
        else
        {
            j++;
        }
    }
}

template<typename T>
int Array<T>::maximumSum(Array<T> nums)
{
    double sum = getSum(nums);
    //Array<T> result(size);
    int i = 0, j = size - 1;
    //int fistTerm = data[i], secondTerm = data[j];

    while (i<j)
    {
        if (sum - num[i] > sum - num[j])
        {
            sum = sum - sum - num[i];
            j--;
        }
        else
        {
            sum = sum - num[j];
            i++;
        }
    }

    
    return sum;
}

#endif // !ARRAY_H
