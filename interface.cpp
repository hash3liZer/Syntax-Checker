#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
	Interface Class to manage tasks like printinng
	and handle file tasks
*/

class INTERFACE {
public:
	// Print the error message and exit from program
	void halt(string _val) {
		cout << _val << endl;
		cout << "||  ";
		system("pause");
		exit(-1);
	}

	// Check if provided file exists or not
	bool isFile(string name) {
		ifstream filer(name);
		return filer.good();
	}

	// Get filename from the user
	string getFilename() {
		string filer;
		cout << "||  Enter Filename: ";
		getline(cin, filer);
		return filer;
	}

	// Printing start lines of the builtin editor
	void show_editor() {
		cout << endl << endl << "||  ============ CONTENT ============" << endl;
	}
	
	// Showing that editor has eended
	void done_editor() {
		cout << "||  =================================" << endl << endl << endl;
	}

	// Executing pause command in terminal.
	void pause() {
		system("pause");
	}

	// Showing the authors of the program
	void showAuthor() {
		cout << "||  Developed for Learning and Testing @hash3liZer" << endl;
		cout << "||  Highly Stable (Works even for Oneliners)" << endl;
		cout << endl << endl;
	}
};