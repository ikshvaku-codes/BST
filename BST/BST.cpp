// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../../BST/queue.h"

class BST {

public:
	Node* root;
	BST() {
		root = NULL;
	}


	void insert(int key) {
		Node* node = root;
		Node* temp = NULL;

		while (node) {
			if (node->data == key) {
				cout << "\nNode already Present";
			}
			else if (node->data > key) {
				temp = node;
				node = node->lTree;
			}
			else if (node->data < key) {
				temp = node;
				node = node->rTree;
			}
		}

		Node* newNode = new Node;
		newNode->data = key;
		newNode->lTree = NULL;
		newNode->rTree = NULL;

		if (root == NULL) {
			root = newNode;
		}
		else if (temp->data > key) {
			temp->lTree = newNode;
		}
		else {
			temp->rTree = newNode;
		}

	}

	Node * insert(Node* node, int key) {

		Node * newNode = new Node;
		newNode->data = key;
		newNode->lTree = NULL;
		newNode->rTree = NULL;

		if (node == NULL) {
			return newNode;
		}
		else if (node->data > key) {
			node->lTree = insert(node->lTree, key);
		}
		else if (node->data < key) {
			node->rTree = insert(node->rTree, key);
		}
		
		return newNode;

	}

	void search(int key) {
		Node* node = root;
		bool isFound = false;
		while (node) {
			if (node->data == key) {
				isFound = true;
				cout << "\nKey Found: " << node->data;
				break;
			}
			else if (node->data > key) {
				node = node->lTree;
			}
			else {
				node = node->rTree;
			}

			
		}

		if (!isFound) {
			cout << "Key Not Found";
		}
	}


	void preOrder(Node* nod) {
		if (nod == NULL) {

		}
		else {
			cout << nod->data;
			preOrder(nod->lTree);
			preOrder(nod->rTree);
		}
	}

	void inOrder(Node* nod) {
		if (nod == NULL) {

		}
		else {
			inOrder(nod->lTree);
			cout << nod->data<<"\t";

			inOrder(nod->rTree);
		}

	}
	void postOrder(Node* nod) {
		if (nod == NULL) {

		}
		else {
			postOrder(nod->lTree);
			postOrder(nod->rTree);
			cout << nod->data<<"\t";


		}
	}
};


int main()
{
	BST b;

	b.insert(33);
	b.insert(20);
	b.insert(30);
	b.insert(15);
	b.insert(26);
	b.insert(150);
	b.insert(1000);
	b.insert(60);

	b.inOrder(b.root);

	b.search(150);
	b.search(0);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
