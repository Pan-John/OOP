#include "QueueList.h"

QueueList::QueueList() {
	front = NULL;
	back = NULL;
}

void QueueList::enqueue(int x) {
	if (front==NULL && back ==NULL) {
		front = new QueueNode(x);
		back = front;
		size++;
		return;
	}

	QueueNode* newNode = new QueueNode(x);
	back->next = newNode;
	back = newNode;
	size++;
}

void QueueList::dequeue() {
	if (front == NULL && back == NULL) {
		//cout << "Queue is empty.\n";
		return;
	}
	if (front == back) {
		front = NULL;
		back = NULL;
		size=0;
	}
	else {
		QueueNode* deletenode = front;
		front = front->next;
		delete deletenode;
		deletenode = 0;
		size--;
	}

}

void QueueList::print() {
	cout << "The values in the queue : ";

	if (front == NULL && back == NULL) {
		cout << endl;
		return;
	}

	//from back to front
	int* p = new int[size];
	int i = 0;
	QueueNode* current = front;
	while (current != NULL) {
		p[i] = current->val;
		current = current->next;
		i++;
	}

	for (int j = i - 1; j >= 0; j--) {
		cout << p[j] << " ";
	}
	cout << endl;


	// from front to back
/*
	QueueNode* current = front;
	while (current != NULL) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
*/
}

QueueList::~QueueList()
{
	while (front) {
		QueueNode* temp = front;
		front = front->next;
		delete temp;
	}
}