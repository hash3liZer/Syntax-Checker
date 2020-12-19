#include<iostream>
#include<string>

using namespace std;

class NODE {
private:
	string data;
	NODE* next;

public:
	NODE() : data(""), next(NULL) {}
	NODE(string data) : data(data), next(NULL) {}

	void setData(string data) {
		data = data;
	}
	void setNext(NODE* ptr) {
		next = ptr;
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

	void push(string data) {
		NODE* tmp = new NODE(data);
		if (isEmpty()) {
			tmp->next = NULL;
		}
		else {
			tmp->next = this->top;
		}
	}

	string pop() {
		if (isEmpty()) {
			return "";
		}
		else {
			string rtval;
			NODE* tmp = this->top;
			this->top = tmp->next;
			rtval = tmp->data;
			delete tmp;
			return rtval;
		}
	}
};