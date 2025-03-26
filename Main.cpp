//Lupe Campos Soto
//CS303 Assignment 2

#include <iostream>
#include "stack.h"  // Assuming you have the stack header file
#include "LinkedList.h"

using namespace std;

void linkedListMenu() {
    Linked myList;  // Assuming you have a Linked class implemented
    int choice;
    do {
        // Linked List Menu
        cout << "\nLinked List Menu:" << endl;
        cout << "1) Print list" << endl;
        cout << "2) Push front" << endl;
        cout << "3) Push back" << endl;
        cout << "4) Pop front" << endl;
        cout << "5) Pop back" << endl;
        cout << "6) Return front value" << endl;
        cout << "7) Return back value" << endl;
        cout << "8) Insert value" << endl;
        cout << "9) Remove value" << endl;
        cout << "10) Find value index" << endl;
        cout << "0) Return to Main Menu" << endl; // Option to return to the main menu
        cout << "Enter number choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myList.print_list();
            break;
        case 2: {
            int data;
            cout << "Enter value to push front: ";
            cin >> data;
            myList.push_front(data);
            break;
        }
        case 3: {
            int data;
            cout << "Enter value to push back: ";
            cin >> data;
            myList.push_back(data);
            break;
        }
        case 4:
            myList.pop_front();
            break;
        case 5:
            myList.pop_back();
            break;
        case 6:
            cout << "Front value: " << myList.front() << endl;
            break;
        case 7:
            cout << "Back value: " << myList.back() << endl;
            break;
        case 8: {
            int index, data;
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> data;
            myList.insert(index, data);
            break;
        }
        case 9: {
            int index;
            cout << "Enter index to remove: ";
            cin >> index;
            if (!myList.remove(index)) {
                cout << "Failed to remove value at index." << endl;
            }
            break;
        }
        case 10: {
            int data;
            cout << "Enter value to find: ";
            cin >> data;
            int index = myList.find(data);
            if (index == -1) {
                cout << "Value not found in the list." << endl;
            }
            else {
                cout << "Value found at index " << index << endl;
            }
            break;
        }
        case 0:  // Return to Main Menu
            return;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (true);
}

void stackMenu() {
    Stack myStack;
    int choice;
    do {
        // Stack Menu
        cout << "\nStack Menu:" << endl;
        cout << "1) Push" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Top" << endl;
        cout << "4) Average" << endl;
        cout << "5) Print Stack" << endl;
        cout << "0) Return to Main Menu" << endl;  // Option to return to the main menu
        cout << "Enter number choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter value to push: ";
            cin >> data;
            myStack.push(data);
            break;
        }
        case 2:
            myStack.pop();
            break;
        case 3:
            cout << "Top value: " << myStack.top() << endl;
            break;
        case 4:
            cout << "Average value: " << myStack.average() << endl;
            break;
        case 5:
            myStack.print();
            break;
        case 0:  // Return to Main Menu
            return;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (true);
}

int main() {
    int choice;
    do {
        // Main Menu
        cout << "\nMain Menu:" << endl;
        cout << "1) Linked List" << endl;
        cout << "2) Stack" << endl;
        cout << "0) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            linkedListMenu();
            break;
        case 2:
            stackMenu();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
