#include "HashTable.h"
using namespace std;

HashTable::HashTable(){
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = NULL;
    }
}

HashTable::~HashTable(){
    //nothing
}

void HashTable::printTableContents(){
    int counter = 0;
    int counter2 = 0;

    for(int j = 0; j < tableSize; j++){
        if(hashTable[j] == NULL){
            counter++;
        }
    }
    //cout << counter << endl;
    if(counter == tableSize){
        cout << "empty" << endl;
    }
    else{
        //cout << "funny people" << endl;
        for(int i = 0; i < tableSize; i++){
            //cout << "blah" << endl;
            //counter2++;
            HashElem *tmp = hashTable[i];
            if(tmp != NULL){
                //cout << tmp->title << ":" << tmp->year << endl;
                while(tmp != NULL){
                    //cout << "myaz" << endl;
                    cout << tmp->title << ":" << tmp->year << endl;
                    tmp = tmp->next;
                }
            }
        }
        //cout << counter2 << endl;
    }
}

void HashTable::insertMovie(std::string name, int year){
    int index; //init
    index = hashSum(name, tableSize); //hash index of movie for the hashTable array
    HashElem *movie = new HashElem; //init
    movie->title=name; //setting string title to the name of the movie
    movie->previous = NULL; //init
    movie->next = NULL; //init
    movie->year = year;

    if(hashTable[index] == NULL){ //if that index is NULL, then set that index equal to the movie
        hashTable[index] = movie;

    }
    else{
        HashElem *tmp = hashTable[index];
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next=movie;
    }
}

void HashTable::deleteMovie(std::string name){
    int index;
    index = hashSum(name,tableSize);
    //cout << "lick" << endl;
    if(hashTable[index] != NULL){
        //cout << "ricky" << endl;
        HashElem *tmp = hashTable[index];
        if(tmp != NULL){
            //cout << "finicky" << endl;
            if(tmp->title == name){
                //cout << "inda" << endl;
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
            //cout << "ficky" << endl;
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
    int index;
    bool found = false;
    index = hashSum(name, tableSize);
    if(hashTable[index] != NULL){
        HashElem *tmp = hashTable[index];
        while(tmp != NULL){
            if(tmp->title == name){
                cout << index << ":" << tmp->title << ":" << tmp->year << endl;
                found = true;
            }
            tmp = tmp->next;
        }
        if(found == false){
            cout << "not found" << endl;
        }
    }
    else if(hashTable[index] == NULL){
        cout << "not found" << endl;
    }
}

int HashTable::hashSum(std::string x, int s){
    int sum = 0;
    for(int i = 0; i < x.length(); i++){
        sum += int(x[i]);
    }
    return sum % s;
}
