#pragma once
#include <iostream>
class Node {
public:
	Node(int val) {
		value = val;
		lchild = NULL;
		rchild = NULL;
	}
	int getValue();
	Node* getLchild();
	Node* getRchild();

	void setLchild(Node* node);
	void setRchild(Node* node);
private:
	int value;
	Node* lchild;
	Node* rchild;
};
