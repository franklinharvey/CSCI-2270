#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main() {
	ifstream inFile;
	// create an instance, can be named whatever you want
	string data;
	inFile.open("structtext.txt"); //open the file
	if (inFile.good()){ //error check
		cout<<"opened successfully"<<endl;
		while (getline(inFile, data)) {//read / get every line of the file & store it
			cout<<data<<endl; // can see the data (each line) printed
			stringstream ss(data); // create a string stream variable from string data
			string elementOne; ss>>elementOne;
			//cout<<elementOne<<endl;
			string elementTwo; ss>>elementTwo;
			cout<<elementTwo<<endl;
		}
	}
	else {
		cout<<"File unsuccessfully opened"<<endl;
	}
	inFile.close(); //close the file
	return 0;
}
