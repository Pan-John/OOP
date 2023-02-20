#include "StackList.h"

StackList::StackList() {
	top = NULL;
	//bottom = NULL;
}

void StackList::push(int x) {
	if (top == NULL) {
		top = new StackNode(x);
		size++;
		return;
	}

	StackNode* newnode = new StackNode(x); 
	newnode->next = top;
	top = newnode;
	size++;
}

void StackList::pop() {
	if (top == NULL) {
		//cout << "stack is empty.\n";
		return;
	}

	StackNode* deletenode = top;
	top = top->next;
	delete deletenode;
	deletenode = 0;
	size--;
}

void StackList::print() {
	cout << "The values in the stack : ";
	if (top == NULL) {
		cout << endl;
		return;
	}

	//from bottom to top
	int* p = new int[size];
	int i = 0;

	StackNode* current = top;
	while (current != NULL) {
		p[i] = current->val;
		current = current->next;
		i++;
	}
	
	for (int j = i-1; j >=0; j--) {
		cout << p[j] <<" ";
	}
	cout << endl;

	//from top to bottom

	//StackNode* current = top;
	//while (current != NULL) {
	//	cout << current->val << " ";
	//	current = current->next;
	//}
	//cout << endl;

}


StackList::~StackList()
{
	while (top) {
		StackNode* temp = top;
		top = top->next;
		delete temp;
	}
}