//Franklin Harvey
//Assignment 6
//CSCI 2270

#include "HashTable.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	string command;
	HashTable table;
	
	while(command != "5"){ 
        cout << "======Main Menu======" << endl; 
        cout <<	"1. Insert Movie" << endl;
        cout <<	"2. Delete Movie" << endl;
        cout <<	"3. Find Movie" << endl;
        cout <<	"4. Print Table Contents" << endl;
        cout <<	"5. Quit" << endl;
        getline(cin,command);
        if(command == "1"){ //insert
			string title;
			string year;
			cout << "Enter title:" << endl;
			getline(cin,title);
    		cout << "Enter year:" << endl;
    		getline(cin,year);
    		table.insertMovie(title, stoi(year));
        }
        else if(command == "2"){ //delete
			string title;
			cout << "Enter title:" << endl;
			getline(cin,title);
			table.deleteMovie(title);
        }
        else if(command == "3"){ //find
			string title;
			cout << "Enter title:" << endl;
			getline(cin,title);
        	table.findMovie(title);
        }
        else if(command == "4"){ //print
            table.printTableContents();
        }
        else if(command=="5"){ //quit
        	cout << "Goodbye!" << endl;
            return EXIT_SUCCESS;
        }
    }
	return 0;
}