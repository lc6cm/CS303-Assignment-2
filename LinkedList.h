#pragma once

#include <iostream>
using namespace std;

struct Node {
	int data;
	int size;

	Node* next;
};

class Linked {
private:
	Node* head;
	Node* tail;

public:
	Linked();
	Linked(int data);
	void push_front(int data);
	void push_back(int data);
	void pop_front();
	void pop_back();
	int front();
	int back();
	bool is_empty();
	void insert(int index, int data); //Index to know where to insert, data to know what to put at index
	bool remove(int index);
	int find(int data);
	void print_list();


};