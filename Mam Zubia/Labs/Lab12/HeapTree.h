#include <iostream>
#include"Array.h"
using namespace std;

template <typename T>
class Heap_Tree
{
    Array<T> arr;
public:
    void insert(T value);
    void display();
    void deleteMin();
    int kthSmallestElement(int* arr, int k, int size);
};

template <typename T>
void Heap_Tree<T>::insert(T value)
{
    arr.add(value);
    int size = arr.getNoOfElement() - 1;
    int i = size;
    while (i > 1)
    {
        int parent = i / 2;
        if (arr[parent] > arr[i])
        {
            arr.swap(parent, i);
            i = parent;
        }
        else
            return;
    }
}
template <typename T>
void Heap_Tree<T>::display()
{
    int size = arr.getNoOfElement() - 1;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << "\t";
    }
}

template <typename T>
void Heap_Tree<T>::deleteMin()
{
    int lastIndex = arr.getNoOfElement() - 1;
    arr.swap(1, lastIndex);
    arr.setNoOfElement(lastIndex - 1);
    int i = 1;
    while (i < lastIndex)
    {
        int left = arr[2 * i];
        int right = arr[2 * i + 1];
        int miner = arr[left] < arr[right] ? 2 * i : 2 * i + 1;
        if (arr[i] > arr[miner])
        {
            arr.swap(miner, i);
            i = miner;
        }
        else
        {
            return;
        }
    }
}

template<typename T>
int Heap_Tree<T>::kthSmallestElement(int* arr, int k, int size)
{
    for (int i = 0; i <= size; i++)
    {
        insert(arr[i]);
    }

    for (int i = 0; i < k; i++)
    {
        deleteMin();
    }
    return arr[1];
}
