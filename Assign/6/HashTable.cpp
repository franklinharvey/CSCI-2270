#include "HashTable.h"

using namespace std;

HashTable::HashTable(){
	for (int i=0;i<tableSize;i++){
		hashTable[i]=NULL;
	}
}
HashTable::~HashTable(){
	//nothing
}

void HashTable::printTableContents(){
	int index=0;
	bool emptyCheck=true;
	while (index<10){
		HashElem* tmp=hashTable[index];
		while (tmp!=NULL){
			cout<<tmp->title<<":"<<tmp->year<<endl;
			emptyCheck=false;
			tmp=tmp->next;
		}
		index++;
	}
	if (emptyCheck){
		cout << "empty" << endl;
	}
}

void HashTable::insertMovie(std::string name, int year){
	HashElem* hashElement=new HashElem;
	hashElement->title=name;
	hashElement->year=year;
	hashElement->next=NULL;
	hashElement->previous=NULL;
	int index=hashSum(name, tableSize); //get hash
	if (hashTable[index]==NULL){
		hashTable[index]=hashElement;
	}
	else{
		HashElem * tmp=hashTable[index];
		while (tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=hashElement;
		hashElement->previous=tmp;
	}
}

void HashTable::deleteMovie(std::string name){
    int index = hashSum(name,tableSize);
    if(hashTable[index] != NULL){
        HashElem *tmp = hashTable[index];
        if(tmp != NULL){
            if(tmp->title == name){
                if(tmp->next != NULL){
                    hashTable[index] = tmp->next;
                    tmp = NULL;
                }
                else{
                    hashTable[index] = NULL;
                    tmp = NULL;
                }
            }
        }
        bool a = true;
        while(tmp != NULL && a){
            if(tmp->next->title == name){
                HashElem* tmp2 = tmp->next->next;

                tmp->next = tmp2;
                a = false;
            }
            tmp = tmp->next;
        }
    }
}

void HashTable::findMovie(std::string name){
	int index=0;
	bool  findCheck=false;
	while (index<10){
		HashElem* tmp=hashTable[index]; //start at head
		while (tmp!=NULL){
			if (tmp->title==name){
				cout << index << ":" << name << ":" << tmp->year << endl;
				findCheck=true;
				return;
			}
			tmp=tmp->next; //traverse
		}
		index++;
	}
	if (!findCheck){
		cout << "not found" << endl;
	}
}

int HashTable::hashSum(std::string x, int s){
	std::string name = x; 
    int sum = 0;
    
    for(int i = 0; i<name.length(); i++){ 
            sum += int(name[i]); //add ASCII values
    }
    
    return sum % s; //mod by table size
}