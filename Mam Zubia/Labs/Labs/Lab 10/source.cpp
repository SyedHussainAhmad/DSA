#include"CDLL.h"

int main()
{
	CDLL<int> element;
	element.insertAtTail(6);
	element.insertAtTail(7);
	element.insertAtTail(1);
	element.insertAtTail(4);
	element.insertAtTail(3);
	cout << element.targetSum(7);
}