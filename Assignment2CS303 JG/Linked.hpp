#pragma once
#include<iostream>

// Definition of the Employee class
class Employee {
private:

public:
	int vacDays;
	int healthCon;
	bool operator==(const Employee& other) const;
};

// Definition of the Professional class, derived from Employee
class Professional : public Employee {
	int monSal;
};

// Definition of the nonProfessional class, derived from Employee
class nonProfessional :public Employee {
	int hourly;
};

// Definition of the Node structure for the linked list
struct Node {
	Employee data;
	Node* nextPtr;
};

// Definition of the list class
class list {
private:
	Node* headPtr = nullptr;
	int num_Items = 0;
public:
	list(); // Constructor
	list(Employee e); // Overloaded constructor
	void push_front(Employee e); // Add an element to the front of the list
	void push_back(Employee e); // Add an element to the back of the list
	void pop_back(); // Remove the last element from the list
	void pop_front(); // Remove the first element from the list
	Employee front(); // Retrieve the value of the first element in the list
	Employee back(); // Retrieve the value of the last element in the list
	void empty(); // Clear the list, removing all elements
	void insert(size_t index, const Employee& item); // Insert an element at a specified index in the list
	bool remove(size_t index); // Remove an element at a specified index in the list
	size_t find(const Employee& item); // Find the index of a specified element in the list
	void Print(); // Print the elements of the list
};
