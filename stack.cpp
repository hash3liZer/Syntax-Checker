#include<iostream>
#include<string>
#include"node.cpp"

using namespace std;

// Stack Class for implementing Stack
class STACK {
private:
	NODE* top;

public:
	// Constructor for Stack class
	STACK() {
		top = NULL;
	}

	// Setter
	void setTop(NODE *ptr) {
		top = ptr;
	}
	// Getter
	NODE* getTop(){
		return top;
	}

	// Checks if stack is empty
	bool isEmpty() {
		return (top == NULL ? true : false);
	}

	// Push a new value to Stack
	void push(string data, int line) {
		NODE* tmp = new NODE(line, data);
		if (isEmpty()) {
			tmp->next = NULL;
		}
		else {
			tmp->next = this->top;
		}
		this->top = tmp;
	}

	// Pop a value from Stack
	NODE* pop() {
		if (isEmpty()) {
			return NULL;
		}
		else {
			NODE* tmp = this->top;
			this->top = tmp->next;
			return tmp;
		}
	}

	// Display all valuess from Stack
	// For debugging purposes.
	void display() {
		cout << "Stack: ";
		NODE* tmp = top;
		while (tmp) {
			cout << tmp->data;
			tmp = tmp->next;
		}
		cout << endl;
	}
};