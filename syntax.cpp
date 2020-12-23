#include<iostream>
#include<string>
#include<vector>
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
	// Contructor that takes the lines to be initiated with
	SYNTAX(vector<string> _val) {
		lines = _val;
		current_word = "";
		current_word_count = 0;
	} 

	// Clean a given string and trim spaces on left and right side. 
	string clean(string _val) {
		_val = this->rtrim(this->ltrim(_val));      // Trim Unnecessary Spaces
		return _val;
	}

	// Check if given word is an open Bracket
	bool isOpenBracket(string word) {              // If given word is an open bracket
		if (
			word == "[" ||
			word == "{" ||
			word == "("
		) {
			return true;
		}
		return false;
	}

	// Check if given word is a close bracket
	bool isCloseBracket(string word) {             // If given word is a close bracket
		if (
			word == "]" ||
			word == "}" ||
			word == ")"
		) {
			return true;
		}
		return false;
	}

	// Checks if given word is an Open Keyword
	bool isOpenKeyword(string word) {              // If given word is an open Keyword
		if (
			word == "begin" ||
			word == "if" ||
			word == "for" ||
			word == "while"
		) {
			return true;
		}
		return false;
	}

	// Checks if given word is a Close Keyword
	bool isCloseKeyword(string word) {             // If given word is a close Keyword
		if (
			word == "end" ||
			word == "elseif" ||
			word == "else" ||
			word == "endif" ||
			word == "endfor" ||
			word == "endwhile"
		) {
			return true;
		}
		return false;
	}

	// Checks if a given words are corresponding or not
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

	// The method which validates the syntax by pushing to stack and checking the closing words
	void validate(string line, int line_counter) {         
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

	// This is the line Parser
	// Loop through a given line and and seperate Words & Brackets
	void looper(string line, int line_counter) {
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

	// This loops through each line and pass it to our looper function
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