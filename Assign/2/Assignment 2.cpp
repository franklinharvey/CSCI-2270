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

struct uniqueWord{
    string word; //"peeta"
    int count; //e.g 100, 2987
};

bool CommonWord(string newWord){
    bool match = false;
    string commonWords[50]= {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i", "it", "for", "not", "on", "with", "he", "as", "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her","she", "or", "an", "will", "my", "one", "all", "would", "their", "there", "what", "so","up", "out", "if", "about", "who", "get", "which","go", "me"};
    for(int i = 0; i<50; i++)
    {
        if(newWord == commonWords[i])
        {
            match=true;
            break;
        }
    }
    return match;
}

bool uniqueNonCommon(string newWord, uniqueWord p, int uniqueNonCommons){
	bool match = false;
	for (int i=0;i<uniqueNonCommons;i++){
		if (p[i].word == newWord){
			match = true;
			p[i].count+=1;
		}
	}
	return match;
}

void printTopWords(uniqueWord p, int topWords, int size){
	uniqueWord topArray[topWords];
	int indexCount = 0;
	for (int i=0;i<topWords;i++){
		topArray[i].count=indexCount;
	}
	for (int i=0;i<size;i++){
		for (int j=0;i<topWords;i++){
			if (p[i].count>topArray[j].count){
				for (int k=topWords-1;k>j;k--){
					topArray[k]=topArray[k-1];
				}
			}
		}
	}
	for (int i=0;i<topWords;i++){
		cout<<topArray.count<<" - "<<topArray.word<<endl;
	}
}

int main(int argc, char *argv[]) {
	int size=1;
	uniqueWord *p = new uniqueWord[size];
	uniqueWord *p2 = new uniqueWord[size*2];
	bool running=false;
	int index=0;
	int topWords = std::stoi(argv[2]);
	int totalNonCommons=0;
	int uniqueNonCommons=0;

	if (argc==3){
		
		ifstream inFile;
		string data; // create an instance
		inFile.open(argv[1]); //open the file from argument

		if (inFile.good()){
			while (running!=true){
				while (getline(inFile, data)) { //read / get every line of the file & store it
					stringstream ss(data);
					string newWord;
					ss << data;

					if (index==size){
						p2 = new uniqueWord[size*2];
						for (int i=0;i<size;i++){
	    					p2[i]=p[i];
	    				}
	    				delete []p;
	    				size=size*2;
	    				p=new uniqueWord[size];
	    				for (int i=0;i<size;i++){
							p[i]=p2[i];
						}
					}

					while (getline(ss, newWord)){ //delimits by line
						
						if (index==size){
							p2 = new uniqueWord[size*2];
							for (int i=0;i<size;i++){
	    						p2[i]=p[i];
	    					}
	    					delete []p;
	    					size=size*2;
	    					p=new uniqueWord[size];
	    					for (int i=0;i<size;i++){
								p[i]=p2[i];
							}
						}

						if (CommonWord(newWord)==true){
							//nothing
						}
						else if (uniqueNonCommon(newWord, p, uniqueNonCommons)==true){
							totalNonCommons++;
						}
						else{
							p[index].word = newWord;
							p[index].count+=1;
							totalNonCommons++;
							index++;
						}
					}
				}
				running=true;
			}
			printTopWords(p, topWords, size);
		}
		else { //file not opened
			cout<<"File unsuccessfully opened"<<endl;
		}
	}
	else{ // if no argument
		cout<<"ERROR: No Argument"<<endl;
	}
}
