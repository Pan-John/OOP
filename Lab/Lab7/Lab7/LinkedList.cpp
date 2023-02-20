#include "LinkedList.h"

LinkedList::LinkedList() {
	// Constructor
	Head = NULL;
}

void LinkedList::Push_back(int x) {
	// TODO : Insert a node to the end of the linked list, the node¡¦s value is x.
	
	if (Head == NULL) {
		Head = new ListNode(x);
		return;
	}

	ListNode* newNode = new ListNode(x);
	ListNode* current = Head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;

}

void LinkedList::Push_front(int x) {

	if (!Head) {
		Head = new ListNode(x);
		return;
	}
	ListNode* newNode = new ListNode(x);
	newNode->next = Head;
	Head = newNode;
}

void LinkedList::Insert(int index, int x) {
	// TODO : Insert a node to the linked list at position ¡§index¡¨, the node's
	// value is x. The index of the first node in the linked list is 0.

	ListNode* current = Head, * temp = NULL;
	ListNode* newNode = new ListNode(x);

	if (index == 0) {
		Push_front(x);
		return;
	}

	int count = 1;
	while (count != index) {
		current = current->next;
		count++;
	}
	temp = current->next;
	current->next = newNode;
	newNode->next = temp;
}

void LinkedList::Delete(int index) {
	// TODO : Remove the node with index ¡§index¡¨ in the linked list.

	ListNode* current = Head, * temp = NULL;

	if (index == 0) {
		Head = current->next;
		delete current;
		current = NULL;
		return;
	}

	int count = 1;
	while (count != index) {
		current = current->next;
		count++;
	}
	temp= current->next->next;
	delete current->next;
	current->next = temp;

}

void LinkedList::Reverse() {
	// TODO : Reverse the linked list.
	// Example :
	//
	// Original List : 1 -> 2 -> 3 -> 4 -> NULL
	// Updated List  : 4 -> 3 -> 2 -> 1 -> NULL
	if (Head == NULL || Head->next == NULL) {
		return;
	}

	ListNode* previous = NULL, * current = Head, * preceding = current->next;

	while (preceding != NULL) {
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}
	current->next = previous;
	Head = current;

}

void LinkedList::Swap(int index_1, int index_2) {
	if (index_1 == index_2) {
		return;
	}
	// TODO : Swap two nodes in the linked list
	// Example : 
	// index_1 : 1   ,  index_2 : 3
	// 
	// Original List : 1 -> 2 -> 3 -> 4 -> NULL
	// Updated List  : 1 -> 4 -> 3 -> 2 -> NULL

	if (index_1 > index_2) { // ensure that index_1 < index_2
		int temp;
		temp = index_1;
		index_1 = index_2;
		index_2 = temp;
	}
	ListNode* current = Head;
	int count = 0, node1_value, node2_value;
	while (current != NULL) {
		if (count == index_1) {
			node1_value = current->val;
		}
		if (count == index_2) {
			node2_value = current->val;
			break;
		}

		current = current->next;
		count++;
	}

	current = Head;
	count = 0;
	while (current != NULL) {
		if (count == index_1) {
			current->val=node2_value;
		}
		if (count == index_2) {
			current->val=node1_value;
			break;
		}

		current = current->next;
		count++;
	}


}

void LinkedList::Print() {

	cout << "List: ";
	// TODO : Print all the elements in the linked list in order.'
	if (Head == NULL) {
		cout << "list is empty!" << endl;
		return;
	}
	ListNode* current = Head;
	while (current != NULL) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;

}

LinkedList::~LinkedList()
{
	while (Head) {
		ListNode* temp = Head;
		Head = Head->next;
		delete temp;
	}
}
