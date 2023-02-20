#pragma once
#include<iostream>
using namespace std;

struct StackNode
{
	int val;
	StackNode* next;

	StackNode() : val(0), next(NULL) {};
	StackNode(int x) : val(x), next(NULL) {};
};

class StackList
{

public:
	StackList();
	void push(int x);
	void pop();
	void print();
	~StackList();

private:
	StackNode* top;
	StackNode* bottom;
	int size;
};