#include<iostream>
#include<string>

using namespace std;

/*
	This class manages our data
	which would be the keyword or bracket
	along with its line number
*/

class NODE {
private:
	int line_number;              // Line number for each word
	string data;                  // Word we are going to store here
	NODE* next;                   // Pointer to next node

public:
	// Empty Constructor for default values
	NODE() : line_number(0), data(""), next(NULL) {}

	// Constructor to initialize with given values
	NODE(int line, string data) : line_number(line), data(data), next(NULL) {}

	// Setters
	void setData(string data) {
		data = data;
	}
	void setData(int data) {
		line_number = data;
	}
	void setNext(NODE* ptr) {
		next = ptr;
	}

	// Getters
	int getLine() {
		return line_number;
	}
	string getData() {
		return data;
	}
	NODE* getNext() {
		return next;
	}

	// Our Friend Class Stack
	friend class STACK;
};