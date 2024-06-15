#include"PriorityQueue.h"
#include"HeapTree.h"

int main()
{
	PriorityQueue pr{ 5 };
	pr.enqueue(Task(1,10,"Task01 - Low Priority"));
	pr.enqueue(Task(2,50,"Task02 - High Priority"));
	pr.enqueue(Task(3,30,"Task03 - Medium Priority"));
	pr.enqueue(Task(4,40,"Task04 - Midium-High Priority"));

	cout << pr.peek().description;
	cout << endl;
	cout << pr.dequeue().description;
	cout << endl;
	cout << pr.peek().description;
	
	int arr[] = { 1,26,74,32 };
	Heap_Tree<int> t;
	t.kthSmallestElement(arr, 3, 4);

	return 0;
}