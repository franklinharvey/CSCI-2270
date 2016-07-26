//Franklin Harvey
//Assignment 5
//CSCI 2270

#include "Graph.h"
using namespace std;

int main(int argc, char *argv[]){
    Graph g;
    int counter = 0;

    vector<string> cities;
    ifstream file; 
    file.open(argv[1]); 
    if(file.good()){
        string data;
        getline(file,data); 
        stringstream ss(data); 
        string nameMatrix;
        string columnOne;
        getline(ss, columnOne, ','); 
        while(getline(ss, nameMatrix, ',')){ 
            g.addVertex(nameMatrix);
            cities.push_back(nameMatrix);
            counter++;
        }
        
        int index = 0;
        while(getline(file,data)){
            int counter2 = 0;
            stringstream ss(data);
            string columnTwo;
            string nameMatrix;
            getline(ss, columnTwo, ',');
            while(getline(ss, nameMatrix, ',')){ 
                if(stoi(nameMatrix) > 0){
                    g.addEdge(cities[index], cities[counter2], stoi(nameMatrix));
                }
                counter2++;
            }
            index++;
        }
    }

    string command;
    while(command != "4"){ 
        cout << "======Main Menu======" << endl; 
        cout <<	"1. Print vertices" << endl;
        cout <<	"2. Find districts" << endl;
        cout <<	"3. Find shortest path" << endl;
        cout <<	"4. Quit" << endl;
        getline(cin,command); 
        if(command == "1"){ 
            g.displayEdges();
        }
        else if(command == "2"){
            g.assignDistricts();
        }
        else if(command == "3"){
            string firstLine;
            string secondLine;
            cout << "Enter a starting city:" << endl;
            getline(cin, firstLine);
            cout << "Enter an ending city:" << endl;
            getline(cin, secondLine);
            g.shortestPath(firstLine, secondLine);
        }
        else if(command == "4"){ 
            cout << "Goodbye!" << endl;
            return EXIT_SUCCESS;
        }
    }
return 0;
}
