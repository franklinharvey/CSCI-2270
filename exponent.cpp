int length(Node *n)
{
	int length;
	if (n==NULL){
		length(n->next);
		length++;
	}
	else {
		return 1+length(n->next);
	}
}

int main(char *argv[]){
	return length(*n);
}