#include <iostream>
#include <string>

#include "../include/linalg.h"

using namespace std;

// Commands
const string HELP = "help";
const string LINALG = "linalg";

// List of all commands (with the exception of help)
const string COMMANDS[] = {
	LINALG
};

// If no arguments were provided, take input from user to specify which module should run
void takeInput(int argc, char** argv){
	string input;

	cout << "Please enter module name (type 'help' for a list of possible commands): ";

	while(cin >> input){
		if(cin.eof()) break;

		if(input == HELP){
			cout << "Here is a list of accepted commands:" << endl;
			for(auto command : COMMANDS) cout << "- " << command << endl;
			cout << endl;
		}else if(input == LINALG){
			LinAlg linalg{};
			linalg.run(argc, argv);
		}else{
			cout << "Unsupported command, please try again." << endl;
		}
	}
}

int main(int argc, char** argv)
{
	// Immediately Launches the Linear Algebra module
	if(argc > 1 && argv[1] == "-" + LINALG){
		LinAlg linAlg{};
		linAlg.run(argc, argv);
	}else{
		takeInput(argc, argv);
	}

	return 0;
}