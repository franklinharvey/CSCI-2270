int *ArrayDynamicAllocation(int array[], int size, int number){
	int *p = new int[size];
	int *p2 = new int[size*2];

    int index=0;

    for (int i=0;i<size;i++){
    	p[i]=array[i]; //pass array into p
    }

    while (index<number){
    	p2 = new int[size*2]; //redeclare p2 size size*2, so that size is doubled for every loop

	    for (int i=0;i<size;i++){
	    	p2[i]=p[i]; //pass p into the 1st half of p2
	    	p2[size+i]=p[i]; //pass p into the 2nd half of p2
	    }
	    
	    delete []p; //not totally necessary
	    
	    for (int i=0;i<size;i++){
	    	p2[size+i]=p2[size+i]*2; //double all of the values in the secind half of p2
	    }

	    size = size*2; //redeclare size as 2x
		p=new int[size];	//redeclare p
	    for (int i=0;i<size;i++){
	    	p[i]=p2[i];	//pass p2 into p, so that at the top of the loop p is still used as if it were the original
	    }
		index++; //up the index
	}
    return p; //no matter how many times it loops, even if 0, p should be correct
    delete []p2; //deallocate
    delete []p; //deallocate

}