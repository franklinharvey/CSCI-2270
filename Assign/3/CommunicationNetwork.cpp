#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

CommunicationNetwork::CommunicationNetwork(){

}
CommunicationNetwork::~CommunicationNetwork(){
	//dtor
}

void CommunicationNetwork::addCity(string previousCity, string newCity){
	if (previousCity=="First"){
		City *head = new City;
		head->cityName = newCity;
		head->next=NULL;
		City *current = CommunicationNetwork::head;
		head->next=CommunicationNetwork::head;
		CommunicationNetwork::head=head;
	}
	else {
		City *current = CommunicationNetwork::head;
		while(current->cityName != previousCity){
        	current = current->next;
    	}
		City *addNewCity=new City;
		addNewCity->cityName=newCity;
		addNewCity->next=current->next;
		current->next=addNewCity;
	}
}

void CommunicationNetwork::buildNetwork(){
	string cityNameArray[10]={"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
	City *head = new City;
	head->cityName = cityNameArray[0];
	head->next=NULL;
	City *current = head;
	CommunicationNetwork::head=current;
	int i = 1;
    while(i < 10){
        City *tmp = new City;
        tmp->cityName = cityNameArray[i]; //(*tmp).value
        tmp->next = NULL;

        current->next = tmp;
        current = current->next;
        i++;
    }
    City *tail = current;

    current = head;
    while(current!=NULL){
    	current=current->next;
    }
}

void CommunicationNetwork::transmitMsg(string filename){ //this is like a string
	ifstream inFile;
	string data; // create an instance
	inFile.open(filename); //open the file from argument

	if (inFile.good()){
		while (getline(inFile, data)) { //read / get every line of the file & store it
			stringstream ss(data);
			string newWord;
			ss << data;
			while (getline(ss, newWord, ' ')){
				City *current = CommunicationNetwork::head;
				while(current != NULL){
        			current->message=newWord;
        			cout<<current->cityName<<" received "<< current->message<<endl;
        			current = current->next;
    			}
			}
		}
	}
	else {
		cout<<"File Not Found"<<endl;
	}
}

void CommunicationNetwork::printNetwork(){
	cout<<"===CURRENT PATH==="<<endl;

	City *current = CommunicationNetwork::head;
	while(current != NULL){
        cout<<current->cityName<<" -> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
}

void CommunicationNetwork::deleteEntireNetwork(){
	
}





