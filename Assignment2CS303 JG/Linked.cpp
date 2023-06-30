#include "Linked.hpp"
#include <iostream>

// Constructor for the list class
list::list() {
	headPtr = nullptr;
	num_Items = 0;
}

// Overloaded constructor for the list class, initializes the list with a single element
list::list(Employee e) {
	Node* tempPtr = new Node;
	tempPtr->data = e;
	tempPtr->nextPtr = nullptr;
	headPtr = tempPtr;
	num_Items = 1;
}

// Add an element to the front of the list
void list::push_front(Employee e) {
	Node* newNode = new Node;
	newNode->data = e;
	newNode->nextPtr = headPtr;
	headPtr = newNode;
	num_Items++;
}

// Add an element to the back of the list
void list::push_back(Employee e) {
	Node* newNode = new Node;
	newNode->data = e;
	newNode->nextPtr = nullptr;

	if (headPtr == nullptr) {
		headPtr = newNode;
		return;
	}

	Node* temp = headPtr;
	while (temp != nullptr) {
		if (temp->nextPtr == nullptr) {
			temp->nextPtr = newNode;
			break;
		}
		temp = temp->nextPtr;
	}
	num_Items++;
}

// Remove the last element from the list
void list::pop_back() {
	if (headPtr == nullptr)
		return;

	if (headPtr->nextPtr == nullptr) {
		delete headPtr;
		headPtr = nullptr;
		return;
	}

	Node* newNode = headPtr;
	Node* last = nullptr;
	while (newNode->nextPtr != nullptr) {
		last = newNode;
		newNode = newNode->nextPtr;
	}

	delete newNode;
	newNode = nullptr;
	last->nextPtr = nullptr;
	num_Items--;
}

// Remove the first element from the list
void list::pop_front() {
	Node* newNode = headPtr;
	headPtr = headPtr->nextPtr;
	delete newNode;
	newNode = nullptr;
	num_Items--;
	return;
}

// Retrieve the value of the first element in the list
Employee list::front() {
	return headPtr->data;
}

// Retrieve the value of the last element in the list
Employee list::back() {
	Node* temp = headPtr;
	while (temp->nextPtr != nullptr) {
		temp = temp->nextPtr;
	}
	return temp->data;
}

// Clear the list, removing all elements
void list::empty() {
	if (headPtr == nullptr)
		return;

	while (headPtr != nullptr) {
		Node* newNode = headPtr;
		headPtr = headPtr->nextPtr;
		delete newNode;
		num_Items = 0;
	}
}

// Insert an element at a specified index in the list
void list::insert(size_t index, const Employee& item) {
	if (index == 0) {
		push_front(item);
		return;
	}

	Node* newNode = new Node;
	newNode->data = item;
	newNode->nextPtr = nullptr;

	Node* prev = nullptr;
	Node* current = headPtr;
	size_t curr = 0;
	while (current != nullptr && curr < index) {
		prev = current;
		current = current->nextPtr;
		curr++;
	}

	if (current != nullptr) {
		prev->nextPtr = newNode;
		newNode->nextPtr = current;
	}
	else
		prev->nextPtr = newNode;

	num_Items++;
}

// Remove an element at a specified index in the list
bool list::remove(size_t index) {
	if (headPtr == nullptr)
		return false;

	num_Items--;

	if (index == 0) {
		pop_front();
		return true;
	}

	Node* prev = nullptr;
	Node* curr = headPtr;
	size_t currIndex = 0;

	while (curr != nullptr && currIndex < index) {
		prev = curr;
		curr = curr->nextPtr;
		currIndex++;
	}

	if (curr != nullptr) {
		prev->nextPtr = curr->nextPtr;
		delete curr;
		return true;
	}

	return false;
}

// Overloaded comparison operator for the Employee class
bool Employee::operator==(const Employee& other) const {
	return (vacDays == other.vacDays) && (healthCon == other.healthCon);
}

// Find the index of a specified element in the list
size_t list::find(const Employee& item) {
	Node* temp = headPtr;
	size_t index = 0;
	while (temp != nullptr) {
		if (item == temp->data) {
			return index;
		}
		temp = temp->nextPtr;
		index++;
	}
	return num_Items;
}

// Print the elements of the list
void list::Print() {
	std::cout << "Linked List: ";
	Node* tempPtr = headPtr;
	while (tempPtr != nullptr) {
		std::cout << tempPtr->data.vacDays << " ";
		tempPtr = tempPtr->nextPtr;
	}
	std::cout << std::endl;
}
