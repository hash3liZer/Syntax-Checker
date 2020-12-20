#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"stack.cpp"
#include"sidetask.cpp"

using namespace std;

/*
	This class handles all the Syntax
	and file parsing
*/

class SYNTAX : public SIDETASK {
private:
	vector<string> lines;
	STACK stack;                 // Our Custom Stack Interface
	STACK stack2;                // Stack for handling the if structure

	string current_word;         // Current Detected Word
	int current_word_count;      // Detected Word Counter

public:
	SYNTAX(vector<string> _val) {
		lines = _val;
		current_word = "";
		current_word_count = 0;
	} 

	string clean(string _val) {
		_val = this->rtrim(this->ltrim(_val));      // Trim Unnecessary Spaces
		return _val;
	}

	bool isOpenBracket(string line) {              // If given word is an open bracket
		if (
			line == "[" ||
			line == "{" ||
			line == "("
		) {
			return true;
		}
		return false;
	}

	bool isCloseBracket(string line) {             // If given word is a close bracket
		if (
			line == "]" ||
			line == "}" ||
			line == ")"
		) {
			return true;
		}
		return false;
	}

	bool isOpenKeyword(string line) {              // If given word is an open Keyword
		if (
			line == "begin" ||
			line == "if" ||
			line == "for" ||
			line == "while"
		) {
			return true;
		}
		return false;
	}

	bool isCloseKeyword(string line) {             // If given word is a close Keyword
		if (
			line == "end" ||
			line == "elseif" ||
			line == "else" ||
			line == "endif" ||
			line == "endfor" ||
			line == "endwhile"
		) {
			return true;
		}
		return false;
	}

	bool isCorrespond(string open, string close) {         // If given words are corresponding input and output
		if (
			(open == "begin" && close == "end") ||
			(open == "if" && close == "endif") ||
			(open == "for" && close == "endfor") ||
			(open == "while" && close == "endwhile") ||
			(open == "[" && close == "]") ||
			(open == "{" && close == "}") ||
			(open == "(" && close == ")")
		) {
			return true;
		}
		return false;
	}

	void validate(string line, int line_counter) {          // The method which validates the syntax by pushing to stack and checking the closing words
		// Check for Begin Error
		if (current_word_count == 0) {
			if (line != "begin") {
				halt(
					line_counter, "BeginError", "Program doesn't start with Keyword 'begin'"
				);
			}
		}

		// Increment current Word and Counter
		current_word = line;
		current_word_count++;

		// Push to stack if is an open word
		if (isOpenKeyword(line) || isOpenBracket(line)) {
			stack.push(line, line_counter);
			if (line == "if") {
				stack2.push(line, line_counter);
			}
		}
		// Perform Operations is a close word
		else if (isCloseKeyword(line) || isCloseBracket(line)) {
			// Error is no opening found for the word
			if (stack.isEmpty()) {
				halt(
					line_counter, "SyntaxError", "No Opening Found for " + line  
				);
			}
			NODE* open;
			// Operations when word is either elseif or else
			if (line == "elseif" || line == "else") {
				open = stack2.getTop();
				if (!open) {
					halt(
						line_counter, "SyntaxError", "No Opening Found for " + line + " detected"
					);
				}
				
				if (open->getData() == line) {
					halt(
						line_counter, "MultipleElse", "Multiple Else Statements are detected"
					);
				}
				else {
					if (line == "else") {
						stack2.push(line, line_counter);
					}
				}
			}
			// Check if Words are corresponding or not. 
			else {
				open = stack.pop();
				if (open->getData() == "if") {
					stack2.pop();
				}
				if (!(isCorrespond(open->getData(), line))) {
					halt(
						open->getLine(), line_counter, "SyntaxError", open->getData() + " || " + line, "Invalid Opening/Closing for the provided syntax. Check the Lines."
					);
				}
			}
		}
	}

	void looper(string line, int line_counter) {              // Loop through a given line and and seperate Words & Brackets
		string converter = "";
		for (int i = 0; i < line.length(); i++) {
			if (!isalpha(line[i]) || i + 1 == line.length()) {

				if (i + 1 == line.length()) {
					if (isalpha(line[i])) {
						converter += line[i];
						validate(converter, line_counter);
					}
					else {
						validate(converter, line_counter);
						converter = line[i];
						validate(converter, line_counter);
					}
				}
				else {
					validate(converter, line_counter);
					converter = line[i];
					validate(converter, line_counter);
				}

				converter = "";
			}
			else {
				converter += line[i];
			}
		}
	}

	void parser() {
		string line;
		
		// Loop through the vector and pass each line to the seperator function
		vector<string>::iterator it1 = lines.begin();   
		for (; it1 != lines.end(); ++it1) {
			line = this->clean(*it1);
			looper(line, (it1 - lines.begin()) + 1);
		}

		// At the End, check if the final word was "end"
		if (it1 == lines.end()) {
			if (current_word != "end") {
				halt(
					(it1 - lines.begin()) + 1, "EndError", "Program doesn't finish with 'end' Keyword"
				);
			}
		}

		// If Stack still is not empty, then it means an opening was left somewhere
		if (!(stack.isEmpty())) {
			NODE* open = stack.pop();
			halt(
				open->getLine(), "SyntaxError", "No Closing was found for " + open->getData()
			);
		}

		cout << "Congratulations! The Syntax of the provided File is Valid!" << endl;
	}
};