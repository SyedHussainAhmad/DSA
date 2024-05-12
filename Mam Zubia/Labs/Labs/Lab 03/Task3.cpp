#include "Stack.h"
int* nextGreaterToLeft(int arr[], int n) 
{
    Stack<int> stack;
    int* result = new int[n];

    for (int i = 0; i < n; ++i) 
    {
        while (!stack.isEmpty() && stack.top() <= arr[i]) 
        {
            stack.pop();
        }

        if (stack.isEmpty()) 
        {
            result[i] = -1;
        }
        else 
        {
            result[i] = stack.top();
        }

        stack.push(arr[i]);
    }

    return result;
}

void printArray(int arr[], int n)  //For Testing Purpose...
{
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//int main() 
//{
//    int nums1[] = { 4, 5, 2, 0 };
//    int nums2[] = { 1, 6, 4, 10, 2, 5 };
//    int n1 = sizeof(nums1) / sizeof(nums1[0]);
//    int n2 = sizeof(nums2) / sizeof(nums2[0]);
//
//    cout << "Output for nums1: ";
//    int* result1 = nextGreaterToLeft(nums1, n1);
//    printArray(result1, n1);
//
//    cout << "Output for nums2: ";
//    int* result2 = nextGreaterToLeft(nums2, n2);
//    printArray(result2, n2);
//
//    delete[] result1;
//    delete[] result2;
//
//    return 0;
//}
