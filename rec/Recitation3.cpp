struct node{
    int value;
    node *next;
    node *prev;
};

node * DeleteNode(node *head, int value){
    if (value==head){
        node tmp;
        tmp=head;
        head=head->next;
        head->previous=null;
        delete[] tmp;
    }
    else if (value==tail){
        node tmp;
        tmp=tail;
        tail=tail->previous;
        tail->next=null;
        delete[] tmp;
    }
    else{
        node tmp;
        tmp=value->previous->next;
        tmp=value->previous->next;
    }
}