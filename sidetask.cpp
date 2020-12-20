#include<iostream>
#include<string>

using namespace std;

class SIDETASK {
private:
	const string WHITESPACE = " \n\r\t\f\v";           // Constant for checking with white spaces

public:
	void halt(string _val) {
		cout << _val << endl;
		cout << "||  ";
		system("pause");
		exit(-1);
	}

	string ltrim(const string s)     // Removing Left Spaces
	{
		size_t start = s.find_first_not_of(WHITESPACE);
		return (start == string::npos) ? "" : s.substr(start);
	}

	string rtrim(const string s){         // Removing Right Spaces
		size_t end = s.find_last_not_of(WHITESPACE);
		return (end == string::npos) ? "" : s.substr(0, end + 1);
	}

	bool startswith(string str, string tosearch) {
		
	}

	bool exists(string str, string tosearch) {                      // Check Existence
		string tocheck = "";
		for (int i = 0; i < str.length(); i++) {
			if (isalpha(str[i])) {
				tocheck += str[i];
			}
			else {
				if (tocheck == tosearch) {
					return true;
				}
			}
		}
		if (tocheck == tosearch) {
			return true;
		}
		return false;
	}
	bool exists(string str, char tosearch) {                      // Overloaded Constructors
		if (str.find(tosearch) != string::npos) {
			return true;
		}
		return false;
	}

	bool isSpaceBoth(char lhs, char rhs) {   // Checking if both given values are spaces
		return (lhs == rhs) && (lhs == ' ');
	}
}; 