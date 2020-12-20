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
	void halt(string _val) {
		cout << _val << endl;
		cout << "||  ";
		system("pause");
		exit(-1);
	}

	bool isFile(string name) {
		ifstream filer(name);
		return filer.good();
	}

	string getFilename() {
		string filer;
		cout << "||  Enter Filename: ";
		getline(cin, filer);
		return filer;
	}

	void show_editor() {
		cout << endl << endl << "||  ============ CONTENT ============" << endl;
	}
	
	void done_editor() {
		cout << "||  =================================" << endl << endl << endl;
	}

	void pause() {
		system("pause");
	}

	void showAuthor() {
		cout << "||  Developed by ..." << endl;
		cout << "||  190764 Shameer Kashif" << endl;
		cout << "||  190770 Mahnam Nasir" << endl;
		cout << endl << endl;
	}
};