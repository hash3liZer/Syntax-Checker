#include<iostream>
#include<string>
#include"node.cpp"

using namespace std;

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