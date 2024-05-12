//#include<iostream>
//using namespace std;
//
//int getLength(int num)
//{
//	int length = 0;
//	while (num != 0)
//	{
//		num = num / 10;
//		length++;
//	}
//	return length;
//}
//
//int getDivisor(int length)
//{
//	if (length == 0)
//	{
//		return 0;
//	}
//	int divisor = 1;
//	for (int i = 0; i < length-1; i++)
//	{
//		divisor = divisor * 10;
//	}
//	return divisor;
//}
//
//int evenDigits(int num)
//{
//	int length = getLength(num);
//	int divisor = getDivisor(length);
//
//	if (length == 1)
//	{
//		return ((num % 2 == 0) ? num : 0);
//	}
//
//	int temp = num/divisor;
//	temp = ((temp % 2 == 0) ? temp : 0);
//
//	int result = temp * 10 + evenDigits(num % divisor);
//	return result;
//}
//
//
//int main()
//{
//	cout << evenDigits(122);
//    cout << endl;
//    return 0;
//}