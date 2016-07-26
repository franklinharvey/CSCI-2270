using namespace std;

struct TreeNode{
	int key;
	TreeNode *parent;
	TreeNode *leftChild;
	TreeNode *rightChild;
}

void printNodeKeys(TreeNode *root){
	if (root->leftChild!=NULL){
		printNodeKeys(root->leftChild);
	}
	cout<<root->key<<endl;
	if (root->rightChild!=NULL){
		printNodeKeys(root->rightChild);
	}
}

void insertNode(TreeNode *root, TreeNode *z){
	TreeNode *p=NULL;
	TreeNode *tmp=root;
	while (tmp!=NULL){
		p=tmp;
		if(z->key < tmp->key){
			tmp=tmp->leftChild;
		}
		else{
			tmp=tmp->rightChild;
		}
	}
	z->parent=p;
	if (z->key < p->key){
		p->leftChild=z;
	}
	else {
		p->rightChild=z;
	}
}

TreeNode *treeSearch(TreeNode *x, int k){
	if (x==NULL){
		cout<<"VALUE NOT FOUND IN TREE"<<endl;
		return x;
	}
	else if (x->key==k){
		return x;
	}

	else {
		if (x->key > k){
			treeSearch(x->leftChild,k);
		}
		else {
			treeSearch(x->rightChild,k);
		}
	}
}

int main(){
	return 0;
}