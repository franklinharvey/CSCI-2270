#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct carData{
    string make;
    string model;
    string year;
};

int main() {
	carData carArray[10];
	ifstream inFile;
	int index = 0;
	// create an instance, can be named whatever you want
	string data;
	inFile.open("structtext.txt"); //open the file
	if (inFile.good()){ //error check
		cout<<"opened successfully"<<endl;
		while (getline(inFile, data)) {//read / get every line of the file & store it
			//cout<<data<<endl; // can see the data (each line) printed


			stringstream ss(data); // create a string stream variable from string data
			string elementOne; ss>>elementOne;
            //cout<<elementOne<<endl;
			string elementTwo; ss>>elementTwo;
			//cout<<elementTwo<<endl;
			string elementThree; ss>>elementThree;
			//cout<<elementThree<<endl;
			carArray[index].make=elementOne;
			carArray[index].model=elementTwo;
			carArray[index].year=elementThree;
            index++;
            //cout<<carArray[index].make<<carArray[index].model<<carArray[index].year<<endl;
		}
		for (int i=0; i<10; i++){
            cout<<"Make: "<<carArray[i].make<<" Model: "<<carArray[i].model<<" Year: "<<carArray[i].year<<endl;
		}
	}
	else {
		cout<<"File unsuccessfully opened"<<endl;
	}
	inFile.close(); //close the file
	return 0;
}
