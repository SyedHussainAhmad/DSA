#include"Dog.h"
#include"Cat.h"
#include"Mouse.h"

#include"Date.h"

int main()
{
	Dog dg;
	Cat c;
	Mouse m;
	Animal* a = &dg;
	a->makeSound();

	/*Date d(13, 11, 2024);
	d.addDays(60);
	d.displayDate();*/


	cout << endl;
	return 0;
}