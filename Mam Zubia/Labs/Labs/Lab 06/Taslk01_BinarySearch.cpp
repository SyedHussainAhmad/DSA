//#include<iostream>
//using namespace std;
//
//int binarySearch(int* arr, int element, int& left, int& right)
//{
//    if (left>right)
//    {
//        return -1;
//    }
//
//    int middle = (left + right) / 2;
//
//    if (arr[middle] == element)
//    {
//        return element;
//    }
//    else if (arr[middle] > element)
//    {
//        right = middle;
//    }
//    else
//    {
//        left = middle;
//    }
//    int result = binarySearch(arr,element,left,right);
//    return result;
//}
//
//int main()
//{
//    int arr[5] = {1,2,3,4,5,};
//
//    int left = 0, right = 4;
//    cout << binarySearch(arr, 3, left,right);
//    cout << endl;
//    return 0;
//}