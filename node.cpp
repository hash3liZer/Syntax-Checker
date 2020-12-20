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
	friend class QUEUE;
};