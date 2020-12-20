#include<iostream>
#include<string>
#include<vector>
#include"interface.cpp"
#include"syntax.cpp"

using namespace std;

// Inheriting All Printing Methods from the Interface Class
class CHECKER: public INTERFACE {
private:
	string filename;
	vector<string> lines;    // Will be Storing File Lines here

public:
	// Parsing File Name and reading data
	CHECKER(int argc, char *argv[]) {
		if (argc < 2) {
			// Get Filename Interactively, in case it has not been specified.
			this->filename = this->getFilename();
		}
		else {
			this->filename = argv[1];  // Storing filename
		}
	}

	// Check File existence
	void validate() {
		if (!(this->isFile(this->filename))) {
			this->halt("||  No Such File Exists");
		}
	}
	
	// Reading File Data
	void read() {
		this->show_editor();
		ifstream filer(
			this->filename
		);

		string line;
		int counter = 1;
		while (getline(filer, line)) {
			cout << counter << "   " << line << endl;
			this->lines.push_back(line);  // Pushing Each Line into our Vector
			++counter;
		}

		filer.close();
		this->done_editor();
	}

	// The Main Method which would do all the checkings for the Syntax
	void engage() {
		SYNTAX* syntax = new SYNTAX(
			this->lines
		);  // A Syntax Class Instance
		
		// Parsing the provided File
		syntax->parser();
	}
};

int main(int argc, char *argv[]) {
	// Showing Authors
	INTERFACE* ifacer = new INTERFACE;
	ifacer->showAuthor();

	// Creating a CHECKER Instance
	CHECKER* checker = new CHECKER(
		argc,
		argv
	);

	// Check File Existence
	checker->validate();

	// Reading File Data
	checker->read();

	// Checking File Syntax
	checker->engage();
	
	// Clearing all Memory
	checker->pause();
	delete checker;
	delete ifacer;

	// Return
	return 0;
}