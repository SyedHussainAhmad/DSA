#include"CDLL.h"

//Private Functions:
template <typename T>
Node <T>* CDLL<T>::searchAddress(const T& key)
{
	Node<T>* temp = head;
	while (temp != head->prev && temp->data != key)
	{
		temp = temp->next;
	}
	if (temp == head->prev && temp->data == key)
		return temp;
	if (temp != head->prev)
		return temp;
	return nullptr;
}

template <typename T>
void CDLL<T>::copyFrom(const CDLL<T>& other)
{
	if (other.head)
	{
		Node<T>* otherTemp = other.head;
		do
		{
			insertAtTail(otherTemp->data);
			otherTemp = otherTemp->next;
		} while (otherTemp != other.head);
	}
}


//Public Functions:
template <typename T>
CDLL<T>::CDLL() :head(nullptr)
{

}

template <typename T>
CDLL<T>::~CDLL()
{
	if (head)
	{
		Node<T>* temp = head;
		do
		{
			Node<T>* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		} while (temp != head);
	}
}

template <typename T>
CDLL<T>& CDLL<T>::operator = (const CDLL<T>& ref)
{
	if (&ref == this)
		return *this;
	this->~CDLL();
	if (ref.head == nullptr)
		return *this;
	copyFrom(ref);
	return *this;
}

template <typename T>
CDLL<T>::CDLL<T>(const CDLL<T>& ref)
{
	*this = ref;
}

template <typename T>
void CDLL<T>::insertAtHead(T val)
{
	Node<T>* temp = new Node<T>(val);
	if (!head)
	{
		head = temp;
		head->next = head;
		head->prev = head;
	}
	else
	{
		temp->next = head;
		temp->prev = head->prev;
		head->prev->next = temp;
		head->prev = temp;
		head = temp;
	}
}

template <typename T>
void CDLL<T>::insertAtTail(T val)
{
	Node<T>* temp = new Node<T>(val);
	if (!head)
	{
		head = temp;
		head->next = head;
		head->prev = head;
	}
	else
	{
		temp->prev = head->prev;
		temp->next = head;
		head->prev->next = temp;
		head->prev = temp;
	}
}

template <typename T>
void CDLL<T>::insertAfter(T key, T val)
{
	if (!head)
		return;
	else
	{
		Node<T>* newNode = new Node<T>(val);
		Node<T>* location = searchAddress(key);
		if (location == nullptr)
			return;
		if (location == head->prev)
			return insertAtTail(val);
		location->next->prev = newNode;
		newNode->next = location->next;
		location->next = newNode;
		newNode->prev = location;
	}
}

template <typename T>
void CDLL<T>::insertBefore(T key, T val)
{
	if (!head)
		return;
	else
	{
		Node<T>* newNode = new Node<T>(val);
		Node<T>* location = searchAddress(key);
		if (location == nullptr)
			return;
		if (location == head)
			return insertAtHead(val);
		location->prev->next = newNode;
		newNode->prev = location->prev;
		newNode->next = location;
		location->prev = newNode;
	}
}

template <typename T>
void CDLL<T>::removeAtHead()
{
	if (!head)
		return;
	else if (head == head->prev)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		head->next->prev = head->prev;
		Node<T>* temp = head;
		head = head->next;
		head->prev->next = head;
		delete temp;
	}
}

template <typename T>
void CDLL<T>::removeAtTail()
{
	if (!head)
		return;
	else if (head == head->prev)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node<T>* temp = head->prev;
		head->prev = head->prev->prev;
		head->prev->next = head;
		delete temp;

	}
}

template <typename T>
void CDLL<T>::removeAfter(T key)
{
	if (!head)
		return;
	else
	{
		Node<T>* location = searchAddress(key);
		if (location == nullptr)
			return;
		if (location == head->prev)
			return removeAtTail();
		Node<T>* temp = location->next;
		location->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
}

template <typename T>
void CDLL<T>::removeBefore(T key)
{
	if (!head)
		return;
	else
	{
		Node<T>* location = searchAddress(key);
		if (location == nullptr)
			return;
		if (location == head->next)
			return removeAtHead();
		Node<T>* temp = location->prev;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
}

template <typename T>
void CDLL<T>::remove(T key)
{
	if (!head)
		return;
	else if (head->data == key)
		return removeAtHead();
	else if (head->prev->data == key)
		return removeAtTail();
	else
	{
		Node<T>* location = searchAddress(key);
		location->prev->next = location->next;
		location->next->prev = location->prev;
		delete location;
	}

}

template <typename T>
void CDLL<T>::display()
{
	if (!head)
		return;
	Node<T>* temp = head;
	do
	{
		cout << "Prev: " << temp->prev->data << ";";
		cout << "Data:  " << temp->data << ";";
		cout << "Next:  " << temp->next->data << ";";
		temp = temp->next;
		cout << endl;
	} while (temp != head);
}

template <typename T>
int CDLL<T>::getLength()
{
	int len = 0;
	if (!head)
		return len;
	Node <T>* temp = head;
	do
	{
		temp = temp->next;
		len++;
	} while (temp != head);
	return len;
}

//Task 02:
template <typename T>
void CDLL<T>::rotateCircularDLL(int times)
{
	int len = getLength();
	int rotateNumber = times % len;
	Node <T>* tail = head;
	while (rotateNumber >= 1)
	{
		tail = tail->prev;
		rotateNumber--;
	}
	head = tail;
}

//Task 03:
template <typename T>
bool CDLL<T>::targetSum(int target)
{
	Node<T>* left = head;
	Node<T>* right = head->prev;
	while (left != right)
	{
		if (left->data + right->data < target)
		{
			left = left->next;
		}
		else if (left->data + right->data > target)
		{
			right = right->prev;
		}
		else
		{
			return true;
		}
	}
	return false;
}