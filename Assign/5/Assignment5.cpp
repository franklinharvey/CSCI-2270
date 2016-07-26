#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[]){
	graph g;
	int counter=0;
	vector <vector <string> > cityVector;
	ifstream file;
	file.open(argv[1]);
	string userCommand;

	if (file.good()){
		string data;
		getline(file, data);
		stringstream ss(data);
		string word;
		string firstWord;
		getline(ss, firstWord, ',');
		
		while(getline(ss, word, ',')){
			g.addVertex(word);
			cityVector.push_back(word);
			counter++
		}
		int index=0;
		while(getline(file, data)){
			int secondCounter=0;
			stringstream ss(data);
			string firstWord2;
			getline(ss, firstWord2, ',')
			while(getline(ss, word, ',')){
				if(std::stoi(word>0)){
					addEdge();
				}
			}
		}
	}

	while (userInput!=true){
		cout << "======Main Menu======" << endl;
		cout << "1. Print vertices" << endl;
		cout << "2. Find districts" << endl;
		cout << "3. Find shortest path" << endl;
		cout << "4. Quit" << endl;
		getline(cin, userCommand);
		
		if (userCommand=="1"){
			g.displayEdges();
		}
		else if (userCommand=="2"){
			g.assignDistricts();
		}
		else if (userCommand=="3"){
			string line1;
			string line2;
			cout<<"Enter a starting city:"<<endl;
			getline(cin, line1);
			cout<<"Enter an ending city:"<<endl;
			getline(cin, line2);
		}
		else if (userCommand=="4"){
			cout<<"Goodbye!"<<endl;
			return EXIT_SUCCESS;
		}

	}
	return 0;
}
