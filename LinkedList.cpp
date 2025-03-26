#include "LinkedList.h"

Linked::Linked() {
	head = nullptr;
	tail = nullptr;


}

Linked::Linked(int data) {
    Node* tempPtr = new Node;  // Create a new Node dynamically using the 'new' keyword
    tempPtr->data = data;      // Set the 'data' member of the new Node to the given 'data'
    tempPtr->next = nullptr; // Set the 'nextPtr' of the new Node to nullptr (as it's the only node in the list for now)

    head = tempPtr;  // Set the head pointer to the newly created node
    tail = tempPtr;  // Set the tail pointer to the newly created node

}
 //Print linked list
void Linked::print_list() {
    Node* current = head;
    if (head == nullptr) {  // Check if the list is empty
        cout << "Empty List" << endl;  // Print error message if the list is empty
    }
    else {
        cout << "Current List:" << endl;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
}



//Add node as new head
void Linked::push_front(int data) {
    Node* tempNode = new Node;//Makes new node to hold new data temporarily.
    tempNode->data = data;//Assigns new data to temp node.
    tempNode->next = head; //Makes new node point to previous head of list.
    head = tempNode;//Adds data in tempNode to the front of list by updating head.


}

//Add node as new tail
void Linked::push_back(int data) {
    Node* tempNode = new Node;//Makes new node to hold new data temporarily.
    tempNode->data = data;//Assigns new data to temp node.
    tempNode->next = nullptr;//Makes new node point to null pointer/ end of list.
    if (head == tail) {// Check if list is empty or only has 1 node.
        head = tail;
        tail = head;
    }

    else {
        tail->next = tempNode;// Have previous tail point to new tail.
        tail = tempNode; // Set new data as new tail. 

    }
}
//Delete first node
void Linked::pop_front() {
    if (head == nullptr) {  // Check if the list is empty
        cout << "Empty List" << endl;  // Print error message if the list is empty
    }
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    
}




//Delete last node
void Linked::pop_back() {
    if (head == nullptr) { // Check if list is empty
        cout << "Empty List" << endl;
    }
    else {
        if (head == tail) { // Check if there is only one node in the list
            delete head; // Delete the only node in the list
            head = nullptr; // Set head to nullptr because the list is now empty
            tail = nullptr; // Set tail to nullptr as well
        }
        else {
            Node* current = head;
            while (current->next != tail) { // Iterate through the list until the node before the tail is reached
                current = current->next; // Go to the next node
            }
            delete tail; // Delete the tail node
            tail = current; // Set current node as the new tail
            tail->next = nullptr; // Set new tail's next to nullptr
        }
    }
}
// Return data in head
int Linked::front() {
    if (head == nullptr) { // Check if list is empty
        cout << "Empty List" << endl;
        return -1; // Indicate error
    }
    else {
        return head->data; // Return data stored in head
    }
}

// Return data in tail
int Linked::back() {
    if (tail == nullptr) { // Check if list is empty
        cout << "Empty List" << endl;
        return -1; // Indicate error
    }
    else {
        return tail->data; // Return data stored in tail
    }
}

bool Linked::is_empty(){
    if (head = nullptr) {//Check if list is empty.
        return true;
    }
    else {
        return false;
    }

}

//Insert new data at a certain index
void Linked::insert(int index, int data) {
    if (index < 0) {// Validate index or return error statment
        cout << "Index not vaild" << endl;
        return;
    }
    if (index == 0) { //Case for insertion at beginning of list calling push_front function
        
        Node* newNode = new Node;//Makes new node to hold new data temporarily.
        newNode->data = data;//Assigns new data to temp node.
        newNode->next = head; //Makes new node point to previous head of list.
        head = newNode;//Adds data in tempNode to the front of list by updating head.
        //adaptation for insertion function
        if (tail == nullptr) {
            tail = newNode;
        }
        return;
    }

    Node* current = head;
    int curr_index = 0;

    while (current != nullptr && curr_index < index-1 ) { //Iterating through list to find node at index right before the target index.
        current = current->next;//Go to next node in list.
        curr_index++;
    }

    if (current == nullptr) {// Validate current index or return error statment
        cout << "Index not vaild" << endl;
        return;
    }

    Node* newNode = new Node; //Make new node
    newNode->data = data;
    newNode->next = current->next;//Update the next node of the new node to the next of the current node
    current->next = newNode;//Update the next of the current node so that the new node comes after it.
    if (newNode->next == nullptr) {
        tail = newNode;
    }


}
//Remove new data at a certain index
bool Linked::remove(int index) {
    if (index < 0) {// Validate index or return error statment
        cout << "Index not vaild" << endl;
        return false;
    }
    if (index == 0) { //Case for insertion at begining of list calling pop_front function
        pop_front();
        return true;
    }
    Node* current = head;
    Node* previous = nullptr;
    int curr_index = 0;
    while (current != nullptr && curr_index < index) { //Iterating through list to find node at index right before the target index.
        previous = current;// 
        current = current->next;
        curr_index++;
    }
    if (current == nullptr) {
        cout << "Index not vaild" << endl;
        return false;
    }

    previous->next = current->next; //Update pointers
    delete current; 
    return true;



}

int Linked::find(int data) {
    
    Node* current = head;
    int index = 0;
    while (current != nullptr) {//Iterating through list
        if (current->data == data) { //Checking to see if data in node at index is target data.
            return index;//returing index of target data.
        }
        current = current->next;
        index++;

    }
    return -1;
}