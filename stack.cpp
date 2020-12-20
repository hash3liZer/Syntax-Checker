#include<iostream>
#include<string>

using namespace std;

class NODE {
private:
	int line_number;
	string data;
	NODE* next;

public:
	NODE() : line_number(0), data(""), next(NULL) {}
	NODE(int line, string data) : line_number(line), data(data), next(NULL) {}

	void setData(string data) {
		data = data;
	}
	void setData(int data) {
		line_number = data;
	}
	void setNext(NODE* ptr) {
		next = ptr;
	}

	int getLine() {
		return line_number;
	}
	string getData() {
		return data;
	}
	NODE* getNext() {
		return next;
	}

	friend class STACK;
};

// Stack Class for implementing Stack
class STACK {
private:
	NODE* top;

public:
	STACK() {
		top = NULL;
	}

	void setTop(NODE *ptr) {
		top = ptr;
	}
	NODE* getTop(){
		return top;
	}

	bool isEmpty() {
		return (top == NULL ? true : false);
	}

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
};