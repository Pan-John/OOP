#include "BST.h"
#include<iostream>
#include<queue>
using namespace std;

void BST::insert(Node* insertNode) {
	//TODO: insert a node to BST

	if (root == NULL) {
		root = insertNode;
		return;
	}

	Node* current = getRoot();
	while (1) {
		if (current == NULL) {
			current = insertNode;
		}
		
		if (insertNode->getValue() > current->getValue()) {
			if (current->getRchild() == NULL) {
				current->setRchild(insertNode);
				return;
			}
			current = current->getRchild();

		}
		if (insertNode->getValue() < current->getValue()) {
			if (current->getLchild() == NULL) {
				current->setLchild(insertNode);
				return;
			}
			current = current->getLchild();
		}
	}
}

void BST::InOrder_traversal(Node* root)
{
	//TODO: Inorder traversal
	//Node* current=root;
	
	if (root != NULL) {
		InOrder_traversal(root->getLchild());//L
		cout << root->getValue()<<" ";//V
		InOrder_traversal(root->getRchild());//R
	}
}
/*
void BinaryTree::Inorder(TreeNode *current){
	if (current) {                          // if current != NULL
		Inorder(current->leftchild);        // L
		std::cout << current->str << " ";   // V
		Inorder(current->rightchild);       // R
	}
}
post LRV
pre VLR
*/

void BST::LevelOrder_traversal(Node* root)
{
	//TODO: Level order traversal
	queue<Node*> q;
	q.push(this->root);                     

	while (!q.empty()) {                     

		Node* current = q.front();      
		q.pop();
		cout << current->getValue() << " ";   

		if (current->getLchild() != NULL) {    
			q.push(current->getLchild());
		}
		if (current->getRchild()!= NULL) {  
			q.push(current->getRchild());
		}
	}
}


Node* BST::getRoot() {
	//TODO: return root of BST
	return root;
}


/*
void BST::DeleteBST(int KEY){               // �n�R���㦳KEY��node

	TreeNode *delete_node = Search(KEY);    // ���T�{BST���O�_���㦳KEY��node
	if (delete_node == NULL) {
		std::cout << "data not found.\n";
		return;
	}

	TreeNode *y = 0;      // �u���n�Q�R��������O���骺node
	TreeNode *x = 0;      // �n�Q�R����node��"child"

	if (delete_node->leftchild == NULL || delete_node->rightchild == NULL){
		y = delete_node;
	}
	else{
		y = Successor(delete_node);        // �Ny�]��delete_node��Successor
	}                                      // �g�L�o��if-else, y�վ㦨�ܦh�u���@��child
										   // �����վ㦨case1��case2�ӳB�z
	if (y->leftchild != NULL){
		x = y->leftchild;                  // �Nx�]��y��child, �i��O���İO����,
	}                                      // �]���i��ONULL
	else{
		x = y->rightchild;
	}

	if (x != NULL){                        // �by�Q�R�����e, �o�ӨB�J��x���^BST
		x->parent = y->parent;             // ���Y���ϤG(c)��, ���ñ��^�t�P�H���B�J
	}
										   // ���ۦA��n�Q����O���骺node��"parent"���V�s��child
	if (y->parent == NULL){                // �Y�R�����O�����root, �N��x���s��root
		this->root = x;
	}
	else if (y == y->parent->leftchild){    // �Yy�쥻�O��parent��left child
		y->parent->leftchild = x;           // �K��x�Ҧby��parent��left child, ���Ny
	}
	else{                                   // �Yy�쥻�O��parent��right child
		y->parent->rightchild = x;          // �K��x�Ҧby��parent��right child, ���Ny
	}
											// �w��case3
	if (y != delete_node) {                 // �Yy�Odelete_node������, �̫�n�A�Ny�����
		delete_node->key = y->key;          // ��^delete_node���O�����m, �ñNy���O�����m����
		delete_node->element = y->element;  // �ϤG(d), y�Y�O�F��, delete_node�Y�O��|
	}

	delete y;                               // �Ny���O�����m����
	y = 0;
}
*/