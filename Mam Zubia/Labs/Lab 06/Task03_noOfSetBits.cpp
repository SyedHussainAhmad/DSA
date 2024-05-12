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
//	for (int i = 0; i < length - 1; i++)
//	{
//		divisor = divisor * 10;
//	}
//	return divisor;
//}
//
//void printDecimalToBinary(int num)
//{
//	int length = getLength(num);
//    if (num == 1)
//    {
//        cout << "1";
//    }
//    else if (num == 0)
//    {
//        cout << "0";
//    }
//	else
//	{
//		printDecimalToBinary(num / 2);
//		cout << num % 2;
//	}
//	
//}
//
//int countOnesInBinary(int binary)
//{
//	int length = getLength(binary);
//	int divisor = getDivisor(length);
//
//	if (length == 1)
//	{
//		return binary;
//	}
//
//	if (binary/divisor == 1)
//	{
//		return 1+ countOnesInBinary(binary % divisor);
//	}
//	else
//	{
//		return countOnesInBinary(binary % divisor);
//	}
//}
//
//int main()
//{
//    printDecimalToBinary(2);
//    cout << endl;
//    return 0;
//}