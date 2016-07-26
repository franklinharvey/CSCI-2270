/*Franklin Harvey
Class: Samantha Molnar
Assignment 1*/

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
    int itemStatus; //e.g wanted or for sale.... false or 0 is "for sale"
    //saleItem(){}; //constructor
};

int main(int argc, char *argv[]) {
	int index=0;
	int counter=0;
	int itemsSold=0;
	int leftOver=0;
	int saleCheck=0;
	saleItem itemArray[100]; //array from txt file
	saleItem indexItem;
	saleItem emptySaleItem;
		emptySaleItem.type = "\0";
		emptySaleItem.itemStatus = 2;
		emptySaleItem.price = 0;

	for (int r=0; r<100; r++){ //clears array
		itemArray[r] = emptySaleItem;
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
						if(token == " wanted"){
							indexItem.itemStatus = 1;
						}
						else{
							indexItem.itemStatus = 0;
						}
					}
					else {
						indexItem.price = std::stoi(token);
					}
					indexTwo++;
					counter++;
				}
				bool writeCheck = true;
				for (int i=0;i<index;i++){
					counter++;
					if (indexItem.itemStatus==0){ //check for sale
						if (indexItem.price<=itemArray[i].price){ //check price
							if (indexItem.itemStatus!=itemArray[i].itemStatus){ //check opposite status
								if(indexItem.type==itemArray[i].type){
									cout<<indexItem.type<<" "<<indexItem.price<<endl;
									itemArray[i]=emptySaleItem;
									indexItem = emptySaleItem;
									writeCheck = false;
									break;
								}
							}
						}
					}
					else{ //item wanted
						if (indexItem.price>=itemArray[i].price){ //check price, higher
							if ((itemArray[i].itemStatus==0)&&(itemArray[i].itemStatus!=2)){ //want vs for sale
								if(indexItem.type==itemArray[i].type){
									cout<<itemArray[i].type<<" "<<itemArray[i].price<<endl;
									itemArray[i]=emptySaleItem;
									indexItem = emptySaleItem;
									writeCheck=false;
									break;
								}
							}
						}
					}
				}
				if (writeCheck == true){
					itemArray[index]=indexItem;
					index++;
				}
				ss.clear();
			}
			/*for (int i=0;i<100;i++){
				cout<<itemArray[i].type<<itemArray[i].itemStatus<<itemArray[i].price<<endl;
			}*/
			cout<<'#';
			cout<<endl;
		}
		else {
			//cout<<"File unsuccessfully opened"<<endl;
		}

		for (int i=0;i<index;i++){
			counter++;
			if (itemArray[i].itemStatus==2){
				for (int j=i;j<99;j++){
					itemArray[j]=itemArray[j+1];
					itemArray[j+1]=emptySaleItem;
				}
			}
			if (i>0){
				if (itemArray[i].price>0){
					if (itemArray[i-1].itemStatus==2){
						i=0;
					}
				}

			}
		}
		/*for (int i=0;i<100;i++){
			cout<<itemArray[i].type<<itemArray[i].itemStatus<<itemArray[i].price<<endl;
		}*/

		for (int i=0;i<index;i++){
			counter++;
			if (itemArray[i].itemStatus == 0){
				cout<<itemArray[i].type<<", for sale, "<<itemArray[i].price<<endl;
			}
			else if (itemArray[i].itemStatus==1){
				cout<<itemArray[i].type<<", wanted, "<<itemArray[i].price<<endl;
			}
			else {
				break;
			}
		}
		cout<<'#';
		cout<<endl;
		//cout<<"Items Sold"<<itemsSold<<'#';
		//cout<<"Items remaining in the message board after reading all lines in the file."<<leftOver<<'#';
		cout<<"loop iterations:"<<counter<<endl;
		inFile.close(); //close the file
	}
	else{ // if no argument
		//cout<<"ERROR: No Argument"<<endl;
	}
}
