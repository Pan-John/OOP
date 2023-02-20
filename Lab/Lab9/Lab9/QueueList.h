#pragma once
#include<iostream>
using namespace std;

struct QueueNode
{
	int val;
	QueueNode* next;

	QueueNode() : val(0), next(NULL) {};
	QueueNode(int x) : val(x), next(NULL) {};
};

class QueueList
{

public:
	QueueList();
	void enqueue(int x);
	void dequeue();
	void print();
	~QueueList();

private:
	QueueNode* front;
	QueueNode* back;
	int size;
};