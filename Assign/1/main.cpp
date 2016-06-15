#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

struct saleItem{
    int itemType; //e.g -1 empty, 0 bike, 1 chicken, 2 dresser, 3 microwave, 4 truck
    string itemTypeString;
    int itemPrice; //e.g 100, 2987
    string itemStatus; //e.g wanted or for sale.... false or 0 is "for sale"
    //saleItem(){}; //constructor
};

int main(int argc, char *argv[]) {
	int index = 0;
	int loopIterations=0;
	int itemsSold=0;
	int leftOver=0;
	int check = 0;
	int checkIndex = 0;
	saleItem saleItemArray[100]; //array from txt file
	saleItem wantItemArray[100];
	saleItem emptySaleItem;
	emptySaleItem.itemType = -1;
	emptySaleItem.itemStatus = "\0";
	emptySaleItem.itemPrice = 0;
	saleItem indexItem;
	
	for (int r=0; r<100; r++){ //clears array
		saleItemArray[r] = emptySaleItem;	
		wantItemArray[r] = emptySaleItem;
		loopIterations++;
	}
	
	if (argc==2){ //checks for argument

		ifstream inFile;
		string data; // create an instance
		inFile.open(argv[1]); //open the file from argument

		if (inFile.good()){ //file open error check
			cout<<"opened successfully"<<endl;
			
			while (getline(inFile, data)) { //read / get every line of the file & store it
				string token;
				stringstream ss(data); // create a string stream variable from string data
				ss << data;
				int indexTwo = 0;
				while (getline(ss, token, ',')){ //delimits by line
					if (indexTwo == 0){
						if (token == "bike"){
							indexItem.itemType = 0;
							indexItem.itemTypeString = "bike";
						}
						else if (token == "chicken"){
							indexItem.itemType = 1;
							indexItem.itemTypeString = "chicken";
						}
						else if (token == "dresser"){
							indexItem.itemType = 2;
							indexItem.itemTypeString = "dresser";
						}
						else if (token == "microwave"){
							indexItem.itemType = 3;
							indexItem.itemTypeString = "microwave";
						}
						else if (token == "truck"){
							indexItem.itemType = 4;
							indexItem.itemTypeString = "truck";
						}
						else{
							indexItem.itemType = -1;
						}
					}
					else if(indexTwo == 1){
						indexItem.itemStatus = token;
					}
					else {
						indexItem.itemPrice = std::stoi(token);
					}
					indexTwo++;
					loopIterations++;

					

				}
				
				

				if (indexItem.itemStatus == " wanted"){
					wantItemArray[index]=indexItem;
					saleItemArray[index]=emptySaleItem;
				}
				else{
					saleItemArray[index]=indexItem;
					wantItemArray[index]=emptySaleItem;
				}

				ss.clear();
				index++;
				loopIterations++;
			}

			for (int q = 0; q<100;q++){
				int wantIndexPrice =  wantItemArray[q].itemPrice;
				string wantIndexType = wantItemArray[q].itemTypeString;
				for (int a = 0; a<100; a++){
					int saleIndexPrice = saleItemArray[a].itemPrice;
					string saleIndexType = saleItemArray[a].itemTypeString;
					if (wantItemArray[q].itemStatus == "DONE"){
						//nothing, skip finished requests
						cout<<"it is finished"<<endl;
						break;
					}
					else{
						//different status, or want vs for sale
						if (saleIndexPrice > 0){ //not empty spot
							//cout<<"1"<<endl;
							if (wantIndexType == saleIndexType){ //same type
								if (wantIndexPrice > saleIndexPrice){ //greater price
									cout<<"ITEM FOUND AT: "<<a<<endl;
									cout<<saleItemArray[a].itemTypeString<<" "<<saleItemArray[a].itemPrice<<endl;
									saleItemArray[a] = emptySaleItem;
									wantItemArray[q].itemStatus = "DONE";
									itemsSold++;
									cout<<wantItemArray[q].itemTypeString<<endl;
									break;
								}
							}
							
						}
						
					}
					loopIterations++;
				}
				loopIterations++;
			}
		}
		
		else {
			cout<<"File unsuccessfully opened"<<endl;
		}
		for (int t=0;t<100;t++){
			if (saleItemArray[t].itemPrice>0){
				leftOver++;
			}
			loopIterations++;
		}
		cout<<"Items Sold"<<endl;
		cout<<itemsSold<<'#'<<endl;
		cout<<"Items remaining in the message board after reading all lines in the file."<<endl;
		cout<<leftOver<<'#'<<endl;
		cout<<"Loop Iterations "<<loopIterations<<endl;
		inFile.close(); //close the file
		}
		else{ // if no argument
			cout<<"ERROR: No Argument"<<endl;
		}
	return 0;
}
