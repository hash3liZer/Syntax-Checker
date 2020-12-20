#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"stack.cpp"
#include"sidetask.cpp"

using namespace std;

// Class for Handling all the SYNTAX
class SYNTAX: public SIDETASK {
private:
	vector<string> lines;
	STACK stack;                 // Our Custom Stack Interface

public:
	SYNTAX(vector<string> _val) : lines(_val) {}   // Quick Pass

	string clean(string _val) {
		_val = this->rtrim(this->ltrim(_val));      // Trim Unnecessary Spaces
		return _val;
	}

	bool hasBrackets(string line) {                         // Check if there are any brackets in the given line
		return ((hasOpenBracket(line) || hasCloseBracket(line)) ? true : false);
	}

	bool hasKeywords(string line) {                        // Check if the given line has specified keywords
		return ((hasOpenKeyword(line) || hasCloseKeyword(line)) ? true : false);
	}

	bool hasOpenBracket(string line) {
		if (
			exists(line, '[') ||
			exists(line, '{') ||
			exists(line, '(')
			) {
			return true;
		}
		return false;
	}

	bool hasCloseBracket(string line) {
		if (
			exists(line, ']') ||
			exists(line, '}') ||
			exists(line, ')')
			) {
			return true;
		}
		return false;
	}

	bool hasOpenKeyword(string line) {
		if (
			exists(line, "begin") || exists(line, "BEGIN") || exists(line, "Begin") ||
			exists(line, "if") || exists(line, "IF") || exists(line, "if") ||
			exists(line, "elseif") || exists(line, "ELSEIF") || exists(line, "Elseif") ||
			exists(line, "else") || exists(line, "ELSE") || exists(line, "Else") ||
			exists(line, "for") || exists(line, "FOR") || exists(line, "For") ||
			exists(line, "while") || exists(line, "WHILE") || exists(line, "While")
		) {
			return true;
		}
		return false;
	}

	bool hasCloseKeyword(string line) {
		if (
			exists(line, "end") || exists(line, "END") || exists(line, "End") ||
			exists(line, "endif") || exists(line, "ENDIF") || exists(line, "Endif") ||
			exists(line, "endfor") || exists(line, "ENDFOR") || exists(line, "Endfor") ||
			exists(line, "endwhile") || exists(line, "ENDWHILE") || exists(line, "Endwhile")
		) {
			return true;
		}
		return false;
	}

	bool isCorrespondBracket(string open_bracket, string close_bracket) {
		if (
			(open_bracket == "[" && close_bracket == "]") ||
			(open_bracket == "{" && close_bracket == "}") ||
			(open_bracket == "(" && close_bracket == ")")
		) {
			return true;
		}
		return false;
	}

	void engageBrackets(string line, int line_counter) {
		string converter;
		for (int i = 0; i < line.length(); i++) {
			converter = line[i];
			if (hasOpenBracket(converter)) {
				stack.push(converter, line_counter);
			}
			else if (hasCloseBracket(converter)) {
				if (stack.isEmpty()) {
					halt(
						"||  Line: " + to_string(line_counter) + " Brackets: ?" + converter + " Error: Unbalanced Brackets Detected"
					);
				}

				NODE *open_bracket = stack.pop();

				if (!(isCorrespondBracket(open_bracket->getData(), converter))) {
					halt(
						"||  Line: " + to_string(line_counter) + " Brackets: " + open_bracket->getData() + "//" + converter + " Error: Unbalanced Brackets Detected"
					);
				}
			}
		}
	}

	void engage() {
		string line;
		int line_counter;
		vector<string>::iterator it = this->lines.begin();   // Creating an iterator for our vector

		for (line_counter = 1; it != lines.end(); ++it, ++line_counter) {                  // Looping through lines
			line = this->clean(*it);                         // Clean the Line

			if (line_counter == 1) {                         // Check if Line Starts with BEGIN
				if (!exists(line, "begin") && !exists(line, "BEGIN") && !exists(line, "Begin")) {
					halt(
						"||  Line: 1 Keyword: BEGIN Error: Program doesn't start with BEGIN Keyword"
					);
				}
			}

			if (this->hasBrackets(line)) {
				this->engageBrackets(line, line_counter);
			}
			if (this->hasKeywords(line)) {
				
			}

		}

		if (!(stack.isEmpty())) {
			NODE* unidentified = stack.pop();
			halt(
				"||  Line: " + to_string(unidentified->getLine()) + " Brackets: " + unidentified->getData() + "? Error: Unbalanced Brackets detected"
			);
		}

		cout << "Congratulations! Your file has passed the test" << endl;
	}
};