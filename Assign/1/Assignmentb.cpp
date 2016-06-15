#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

struct saleItem{
    string type;
    int price; //e.g 100, 2987
    string itemStatus; //e.g wanted or for sale.... false or 0 is "for sale"
    //saleItem(){}; //constructor
};

int main(int argc, char *argv[]) {
	int index = 0;
	int counter=0;
	int itemsSold=0;
	int leftOver=0;
	int saleCheck=0;
	saleItem itemArray[100]; //array from txt file
	saleItem wantItemArray[100];
	saleItem emptySaleItem;
		emptySaleItem.type = "\0";
		emptySaleItem.itemStatus = "no";
		emptySaleItem.price = 0;
	saleItem indexItem;
	
	for (int r=0; r<100; r++){ //clears array
		counter++;
		itemArray[r] = emptySaleItem;	
		wantItemArray[r] = emptySaleItem;
	}
	
	if (argc==2){ //checks for argument

		ifstream inFile;
		string data; // create an instance
		inFile.open(argv[1]); //open the file from argument

		if (inFile.good()){ //file open error check
			//cout<<"opened successfully"<<endl;
			
			while (getline(inFile, data)) { //read / get every line of the file & store it
				counter++;
				string token;
				stringstream ss(data); // create a string stream variable from string data
				ss << data;
				int indexTwo = 0;
				while (getline(ss, token, ',')){ //delimits by line
					if (indexTwo == 0){
						indexItem.type = token;
					}
					else if(indexTwo == 1){
						indexItem.itemStatus = token;
					}
					else {
						indexItem.price = std::stoi(token);
					}
					indexTwo++;
					counter++;
				}

				if (indexItem.itemStatus == " wanted"){
					wantItemArray[index]=indexItem;
					itemArray[index]=emptySaleItem;
				}
				else{
					itemArray[index]=indexItem;
					wantItemArray[index]=emptySaleItem;
				}

				ss.clear();
				index++;
			}


			for (int q = 0; q<100;q++){
				counter++;
				int wantIndexPrice =  wantItemArray[q].price;
				string wantIndexType = wantItemArray[q].type;
				for (int a = 0; a<100; a++){
					counter++;
					int saleIndexPrice = itemArray[a].price;
					string saleIndexType = itemArray[a].type;
					if (wantItemArray[q].itemStatus == "DONE"){
						//nothing, skip finished requests
						break;
					}
					else{
						if (saleIndexPrice > 0){ //not empty spot
							if (wantIndexType == saleIndexType){ //same type
								if (wantIndexPrice > saleIndexPrice){ //greater price
									//cout<<"ITEM FOUND AT: "<<a<<endl;
									cout<<itemArray[a].type<<" "<<itemArray[a].price<<endl;
									itemArray[a] = emptySaleItem;
									wantItemArray[q].itemStatus = "DONE";
									itemsSold++;
									break;
								}
							}
						}
					}
				}
			}
			
			for (int y=0;y<100;y++){
				counter++;
				if (itemArray[y].itemStatus == "no"){
					for (int j=y;j<99;j++){
						counter++;
						itemArray[j]=itemArray[j+1];
					}
					itemArray[99]=emptySaleItem;
				}
				if (y>0){
					if (itemArray[y].itemStatus!="no"){
						if (itemArray[y-1].itemStatus == "no"){
							y=-1;
						}
					}
				}
			}
		}
		
		else {
			//cout<<"File unsuccessfully opened"<<endl;
		}
		for (int t=0;t<100;t++){
			counter++;
			if (itemArray[t].price>0){
				cout<<itemArray[t].type<<" "<<itemArray[t].price<<endl;
				leftOver++;
			}
		}
		cout<<"Items Sold"<<itemsSold<<'#'<<endl;
		cout<<"Items remaining in the message board after reading all lines in the file."<<leftOver<<'#'<<endl;
		cout<<"Loop Iterations "<<counter<<endl;
		inFile.close(); //close the file
		}
		else{ // if no argument
			cout<<"ERROR: No Argument"<<endl;
		}
	return 0;
}
