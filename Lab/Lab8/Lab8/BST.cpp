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
void BST::DeleteBST(int KEY){               // 要刪除具有KEY的node

	TreeNode *delete_node = Search(KEY);    // 先確認BST中是否有具有KEY的node
	if (delete_node == NULL) {
		std::cout << "data not found.\n";
		return;
	}

	TreeNode *y = 0;      // 真正要被刪除並釋放記憶體的node
	TreeNode *x = 0;      // 要被刪除的node的"child"

	if (delete_node->leftchild == NULL || delete_node->rightchild == NULL){
		y = delete_node;
	}
	else{
		y = Successor(delete_node);        // 將y設成delete_node的Successor
	}                                      // 經過這組if-else, y調整成至多只有一個child
										   // 全部調整成case1或case2來處理
	if (y->leftchild != NULL){
		x = y->leftchild;                  // 將x設成y的child, 可能是有效記憶體,
	}                                      // 也有可能是NULL
	else{
		x = y->rightchild;
	}

	if (x != NULL){                        // 在y被刪除之前, 這個步驟把x接回BST
		x->parent = y->parent;             // 此即為圖二(c)中, 把基紐接回龜仙人的步驟
	}
										   // 接著再把要被釋放記憶體的node之"parent"指向新的child
	if (y->parent == NULL){                // 若刪除的是原先的root, 就把x當成新的root
		this->root = x;
	}
	else if (y == y->parent->leftchild){    // 若y原本是其parent之left child
		y->parent->leftchild = x;           // 便把x皆在y的parent的left child, 取代y
	}
	else{                                   // 若y原本是其parent之right child
		y->parent->rightchild = x;          // 便把x皆在y的parent的right child, 取代y
	}
											// 針對case3
	if (y != delete_node) {                 // 若y是delete_node的替身, 最後要再將y的資料
		delete_node->key = y->key;          // 放回delete_node的記憶體位置, 並將y的記憶體位置釋放
		delete_node->element = y->element;  // 圖二(d), y即是達爾, delete_node即是西魯
	}

	delete y;                               // 將y的記憶體位置釋放
	y = 0;
}
*/