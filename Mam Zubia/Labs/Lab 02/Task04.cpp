#include<iostream>
using namespace std;

double getSum(int* nums, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
    }
    return sum;
}

double* findAverage(int* nums, int size, int k)
{
    int resSize = size - k + 1;
    double* result = new double[resSize];
    double sum = getSum(nums, k);
    int firstTerm = 0;
    int lastTerm = 0;

    for (int i = 0; i < resSize; i++)
    {
        result[i] = (sum - firstTerm + lastTerm) / k;
        firstTerm = nums[i];
        lastTerm = nums[i+k];
    }
    return result;
}

int main()
{
    int* nums = new int[6] {1, 12, -5, -6, 50, 3};
    double* result = findAverage(nums,6, 4);

    for (int i = 0; i < 3; i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
    cout << endl;
    return 0;
}
