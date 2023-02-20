#include <iostream>
#include <fstream>
#include "BST.h"
#include "Node.h"

using namespace std;

int main() {
	/*  Do not modify the content in "int main ()". */

	fstream file;
	file.open("input2.txt");

	if (!file.is_open()) {
		cout << "Fail to open file" << endl;
		return 0;
	}

	int TestCase = 0;
	file >> TestCase;

	while (TestCase) {
		BST bst;

		int NumberOfNode;
		file >> NumberOfNode;

		for (int i = 0; i < NumberOfNode; i++) {
			int NodeValue;
			file >> NodeValue;
			bst.insert(new Node(NodeValue));
		}

		//Inorder traversal
		cout << "Inorder_traversal: ";
		bst.InOrder_traversal(bst.getRoot());
		cout << endl;

		//Level order traversal
		cout << "Level_traversal: ";
		bst.LevelOrder_traversal(bst.getRoot());
		cout << endl<<endl;

		TestCase--;
	}


	system("pause");
	return 0;

}