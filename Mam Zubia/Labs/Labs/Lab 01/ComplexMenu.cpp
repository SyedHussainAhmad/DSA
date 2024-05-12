//#include"Complex.h"
//
//Complex num;
//int real, imag;
//
//void getNum()
//{
//	cout << "Enter Real Number: ";
//	cin >> real;
//	cout << "Enter Imaginary Number: ";
//	cin >> imag;
//}
//
//void doUserTasks(char ch)
//{
//	switch (ch)
//	{
//		case '1':
//		{
//			getNum();
//			num.setReal(real);
//			num.setImag(imag);
//			break;
//		}
//		case '2':
//		{
//			getNum();
//			Complex g = num.add(Complex(real,imag));
//			g.display();
//			break;
//		}
//		case '3':
//		{
//			getNum();
//			Complex g = num.subtract(Complex(real, imag));
//			g.display();
//			break;
//		}
//		case '4':
//		{
//			getNum();
//			Complex g = num.multiply(Complex(real, imag));
//			g.display();
//			break;
//		}
//		case '5':
//		{
//			getNum();
//			Complex g = num.divide(Complex(real, imag));
//			g.display();
//			break;
//		}
//		case '6':
//		{
//			Complex conj = num.conjugate();
//			conj.display();
//			break;
//		}
//		case '7':
//		{
//			num.display();
//			break;
//		}
//	}
//}
//
//void menu()
//{
//	char ch = 'q';
//	do
//	{
//		cout << "\nPress 1 to create Complex Number\n";
//		cout << "Press 2 to add Complex Number\n";
//		cout << "Press 3 to subtract Complex Number\n";
//		cout << "Press 4 to multiply Complex Number\n";
//		cout << "Press 5 to divide Complex Number\n";
//		cout << "Press 6 to conjucate Complex Number\n";
//		cout << "Press 7 to display Complex Number\n";
//		cout << "Press 8 to quit/exit\n";
//
//		cin >> ch;
//		doUserTasks(ch);
//	}
//	while (ch !='Q' || ch != 'q');
//}
//int main()
//{
//	menu();
//	cout << endl;
//	return 0;
//}