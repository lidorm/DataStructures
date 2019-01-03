#include "queue_list.h"

int Queue_List:: getRandomNumber()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000);


	return dist6(rng);

}

void List::printList() {
	node *ptr = head;

	while (ptr->next != tail) {
		cout << ptr->next->_data << "->";
		ptr = ptr->next;
	}
	cout << endl;

}

int List::getMaxData()
{
	int max = 0;

	node *ptr = head;
	while (ptr->next != tail) {
		if (ptr->next->_data >= max) {
			max = ptr->next->_data;
		}
		ptr = ptr->next;
	}

	return max;
}

bool List::isEmptyList()
{
	if (head->next == tail) {
		cout << "empty list!" << endl;
		return true;
	}
	return false;
}

void List::insertNode(int num)
{
	node * temp = new node;
	temp->_data = num;
	
	if (head->next == NULL) {  //if the list empty,creat the list with one node
		temp->next = tail;
		temp->prev = head;
		head->next = temp;
		tail->prev = temp;
	}
	else {
		temp->next = head->next;
		head->next->prev = temp;
		head->next = temp;
		temp->prev = head;
	}
}

void List::deleteNode()
{
	int max = getMaxData();
	cout << "node data to delete is: " << max << endl;
	node *ptr = head->next;
	if (isEmptyList()) {
		cout << "underflow" << endl;
		return;
	}
	while (ptr->_data != max) {
		{
			if (ptr->next == tail)
			{
				cout << "underflow" << endl;
				return;
			}
			ptr = ptr->next;
		}
	}

	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	ptr->next = NULL;
	delete ptr;
}

void Queue_List::Enqueue(int randomNum)
{
	
		list.insertNode(randomNum);

}

void Queue_List::Dequeue()
{
	while (!list.isEmptyList()) {
		list.deleteNode();
	}
}

bool Queue_List::isEmpty()
{
	if (list.isEmptyList()) {
		return true;
	}
	return false;
}
