#include<iostream>
#include<string>

using namespace std;

/*
	This class is inhertted by syntax class
	and manages all the extra functions
	which would be used more and more
	all over the class
*/

class SIDETASK {
private:
	const string WHITESPACE = " \n\r\t\f\v";           // Constant for checking with white spaces

public:
	// Printing Our Error and exiting from the program
	void halt(int line, string exception, string error) {
		cout << "~~  Error Encountered" << endl;
		cout << "~~  Line Number: " << line << endl;
		cout << "~~  Exception: " << exception << endl;
		cout << "~~  Error: " << error << endl << endl;

		cout << "##  ";
		system("pause");
		exit(-1);
	}

	// Overloaded Constructor
	// When we have two lines to show
	void halt(int line1, int line2, string exception, string sequence, string error) {
		cout << "~~  Error Encountered" << endl;
		cout << "~~  Line Numbers: " << line1 << ", " << line2 << endl;
		cout << "~~  Exception: " << exception << endl;
		cout << "~~  Sequence: " << sequence << endl;
		cout << "~~  Error: " << error << endl << endl;

		cout << "##  ";
		system("pause");
		exit(-1);
	}

	// Trimming Spaces from left
	string ltrim(const string s)     // Removing Left Spaces
	{
		size_t start = s.find_first_not_of(WHITESPACE);
		return (start == string::npos) ? "" : s.substr(start);
	}

	// Trimming Spaces from Right
	string rtrim(const string s){         // Removing Right Spaces
		size_t end = s.find_last_not_of(WHITESPACE);
		return (end == string::npos) ? "" : s.substr(0, end + 1);
	}
}; 