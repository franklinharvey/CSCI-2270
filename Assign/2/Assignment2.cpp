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
    string commonWords[50]= {"the","be","to","of","and","a","in","that","have","i","it","for","not","on","with","he","as","you","do","at","this","but","his","by","from","they","we","say","her","she","or","an","will","my","one","all","would","their","there","what","so","up","out","if","about","who","get","which","go","me"};
    for(int i = 0; i<50; i++){
        if(newWord == commonWords[i]){
            match=true;
            break;
        }
    }
    return match;
}

uniqueWord sortArray(uniqueWord newArray, int size){

	return newArray;
}

int main(int argc, char *argv[]) {
	int size=100;
	uniqueWord *p = new uniqueWord[size];
	uniqueWord *p2 = new uniqueWord[size*2];
	bool running=false;
	int index=0;
	int topWords = std::stoi(argv[2]);
	int totalNonCommons=0;
	int uniqueNonCommons=0;
	int arrayDoubled=0;

	if (argc==3){
		
		ifstream inFile;
		string data; // create an instance
		inFile.open(argv[1]); //open the file from argument

		if (inFile.good()){
			while (getline(inFile, data)) { //read / get every line of the file & store it
				stringstream ss(data);
				string newWord;
				ss << data;	

				while (getline(ss, newWord, ' ')){ //delimits by line
					if (uniqueNonCommons==size){
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
						arrayDoubled++;
					}

					bool match = false;
					for (int i=0;i<size;i++){
						if (p[i].word == newWord){
							match = true;
							p[i].count++;
							break;
						}
					}
					if (CommonWord(newWord)==true){
						//nothing
					}
					else if (match==true){
						totalNonCommons++;
					}
					else if ((match==false) && (CommonWord(newWord) == false)){
						p[index].word = newWord;
						p[index].count=1;
						totalNonCommons++;
						index++;
						uniqueNonCommons++;
					}
				}
				ss.clear();
			}

		}
		else { //file not opened
			cout<<"File unsuccessfully opened"<<endl;
		}		
		
		uniqueWord temp;
		for (int i=size-1;i>0;i--){
			for (int j=size-1;j>0;j--){
				//if (p[j].count>682){
				//	p[j].count=0;
				//}

				if (p[j].count>p[j-1].count){
						temp=p[j-1];
						p[j-1]=p[j];
						p[j]=temp;
				}
			}
		}

		for (int i=0;i<topWords;i++){
			cout<<p[i].count<<" - "<<p[i].word<<endl;
		}

		cout<<"#"<<endl;
		cout<<"Array doubled: "<<arrayDoubled<<endl;
		cout<<"#"<<endl;
		cout<<"Unique non-common words: "<<uniqueNonCommons<<endl;
		cout<<"#"<<endl;
		cout<<"Total non-common words: "<<totalNonCommons<<endl;

		for (int i=0;i<uniqueNonCommons;i++){
			p[i].word="\0";
			p[i].count=0;
		}

		uniqueNonCommons=0;
		totalNonCommons=0;
		arrayDoubled=0;

		delete []p;
		delete []p2;
		inFile.close();
	}
	else{ // if no argument
		cout<<"ERROR: No Argument"<<endl;
	}
}