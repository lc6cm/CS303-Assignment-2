#include "stack.h"

Stack::Stack() {}


bool Stack::is_empty() {
	if (elements.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}


void Stack:: push(int data) {

	elements.push_back(data); //Call push_back function that comes with vectors which in this case adds the data to the top of the stack.
	}

void Stack::pop() {
	if (is_empty() != true) {
		elements.pop_back(); //Call pop_back function that deletes top 
	}
	else {
		cout << "Empty Stack" << endl;
		
	}
}

int Stack::top() {
	if (is_empty() != true) {
		return elements.back(); //Call back function that returns top 
	}
	else {
		cout << "Empty Stack" << endl;
		return -1;
	}

}

int Stack::average() {
	if (is_empty() != true) {
		int sum = 0;
		for (int i = 0; i < elements.size(); i++) {
			sum = sum + elements[i];
		}
		return (sum / elements.size());
	}
	else {
		cout << "Empty Stack" << endl;
		return -1;
	}

}

void Stack::print() {
	if (is_empty() != true) {
		cout << "Stack:" << endl;
		for (int i = 0; i < elements.size(); i++) {
			cout << elements[i] << endl;
		}
		
	}
	else {
		cout << "Empty Stack" << endl;
		
	}
}