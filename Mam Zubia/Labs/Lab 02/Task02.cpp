//#include<iostream>
//using namespace std;
//
//
//int findSQRT(double num)
//{
//    int left = 0;
//    int right = num;
//    int middle = 0;
//    while (left <= right)
//    {
//        middle = (left + right) /2;
//        double middleSQR = middle * middle;
//        if (middleSQR == num)
//        {
//            return middle;
//        }
//        else if (middleSQR > num)
//        {
//            right = middle;
//        }
//        else
//        {
//            left = middle;
//        }
//        if (num > middleSQR && num < ( middle + 1) * (middle+ 1))
//        {
//            return middle;
//        }
//    }
//    return middle;
//}
//
//int main()
//{
//    cout << findSQRT(49);
//    cout << endl;
//    return 0;
//}
