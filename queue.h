#pragma once


#include <iostream>
using namespace std;

class Node {
public:
	Node* lTree;
	int data;
	Node* rTree;
};


class Queue {

	int front;
	int rear;
	int size;
	Node** q;

public:
	int getRear() {
		return this->rear;
	}
	Queue() {
		front = rear = -1;
		size = 10;
		*q = new Node[size];
	}
	Queue(int size) {
		front = rear = -1;
		this->size = size;
		q = new Node* [this->size];
	}
	void enqueue(Node* x);
	Node* dequeue();
	bool isEmpty();

};


void Queue::enqueue(Node* x) {
	if (rear == size - 1) {
		cout << "Overflow";
	}
	else {
		rear++;
		q[rear] = x;
	}
}

Node* Queue::dequeue() {
	if (rear == -1) {
		cout << "UnderFlow"; 
		return NULL;
	}
	else {
		front++;
		return q[front];
	}
}

bool Queue::isEmpty() {
	if (rear == front) {
		return true;
	}
	return false;
}

