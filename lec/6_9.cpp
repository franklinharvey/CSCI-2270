#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *next;
};

int main(){
	int a[5]={2,4,6,8,10};
	Node *head = new Node;
	head->key=a[0];
	head->next=NULL;

	Node *current=head;

	int i=1;
	while(i<5){
		Node *tmp = new Node;
		tmp->key=a[i];
		tmp->next=NULL;

		current->next=tmp;
		current=current->next;
		i++;
	}
	Node *tail=current;
	current=head;
	while(current!=NULL){
		cout<<current->key<<endl;
		current=current->next;
	}

}