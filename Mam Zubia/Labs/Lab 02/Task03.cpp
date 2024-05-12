//#include<iostream>
//using namespace std;
//
//int getProduct(int* nums, int size)
//{
//    int product = 1;
//    for (int i = 0; i < size; i++)
//    {
//        product *= nums[i];
//    }
//    return product;
//}
//
//int* productExceptSelf(int* nums, int size)
//{
//    int* result = new int[size];
//    int product = getProduct(nums, size);
//
//    for (int i = 0; i < size; i++)
//    {
//        result[i] = product / nums[i];
//    }
//    return result;
//}
//
//int main()
//{
//    int* nums = new int[4]{1,2,3,4};
//    int* result = productExceptSelf(nums, 4);
//
//    for (int i = 0; i < 4; i++)
//    {
//        cout << result[i] << '\t';
//    }
//    cout << endl;
//    return 0;
//}
