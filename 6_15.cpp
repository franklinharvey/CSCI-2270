#ifndef QUEUE H
#define QUEUE H
#include <string>

using namespace std;

struct Node{
	std::string key;
	Node * next;
};
class Queue{
private:
	Node* head;
	Node* tail;
	int queueSize;
	int maxQueue;
	bool isEmpty();
	bool isFull();

public:
	Queue(int);
	~Queue();
	void enqueue(std::string); //push
	std::string dequeue(); //pop
};

Queue::Queue(int size){
	queueSize=0;
	maxQueue=size;

	head=NULL;
	tail=NULL;
}

Queue::~Queue(){

}

void Queue::enqueue(std::string){
	Node *n=new Node;
	n->key=v;
	n->next=NULL;
	if (!isFull()){
		if (tail!=NULL){ //not empty
			tail->next=n;
		}
		else{ //is empty
			tail=n;
			head=tail;
		}
	}
}

std::string dequeue(){
	if (!isEmpty()){
		std::string n=head->key;
		head=head->next;
		queueSize--;
		return n;
		
	}
	else {
		std::cout<<"Queue is empty"<<std::endl;
		return "";
	}

}

bool isEmpty(int queueSize){
	if (queueSize <= 0){
		return true;
	}
	else {
		return false;
	}
}

bool isFull(int maxQueue, int queueSize){
	if (maxQueue==queueSize){
		return true;
	}
	else {
		return false;
	}
}

int main(){

}