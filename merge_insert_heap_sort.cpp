#include<iostream>
using namespace std;
// traversal over array
void traversal(int *arr,int size){
	if(size==0){
		cout<<"ARRAY IS EMPTY "<<endl;
		return;
	}
	for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
	cout<<endl;
}
// insert an element at the begin of an array
void insert_at_begin(int element,int*arr,int &size){
	for(int i=size;i>0;i--){
			arr[i]=arr[i-1];
			}
	arr[0]=element;
	size++;
	cout<<"ELEMENT INSERTED AT THE BEGIN SUCESSFULLY"<<endl;
	traversal(arr,size);
}
// insert an element at the end of an array
void insert_at_end(int element,int*arr,int&size){
	arr[size]=element;
	size++;
	cout<<"ELEMENT INSERTED AT THE END SUCESSFULLY"<<endl;
	traversal(arr,size);
}
// insert an element at some particular index provided by user
void insert_at_mid(int element,int*arr,int&size){
	int index;
	cout<<"ENTER THE INDEX AT WHICH YOU WANT TO INSERT"<<endl;
	cin>>index;
	if(index>=size&&index<0){cout<<"INVALID ENTRY"<<endl;
	return;
	}
	for(int i=size;i>index;i--){
		arr[i]=arr[i-1];
	}
	arr[index]=element;
	size++;
	cout<<"ELEMENT INSERTED AT "<<index<<" INDEX SUCESSFULLY"<<endl;
	traversal(arr,size);
}
// delete an element from the begin of an array i.e. element at 0 index
void delete_from_begin(int*arr,int&size){
	for(int i=1;i<size;i++){
        	arr[i-1]=arr[i];
            }
    size--;
    cout<<"ELEMENT FROM THE BEGIN DELETED SUCESSFULLY"<<endl;
    traversal(arr,size);
}
// delete an element from the end of an array i.e. element at size-1 index
void delete_from_end(int* arr,int&size){
	size--;
	cout<<"ELEMENT AT THE END DELETED SUCESSFULLY"<<endl;
	traversal(arr,size);
}
// delete an element from a particular index provided by user
void delete_from_mid(int* arr,int&size){
	int index;
	cout<<"ENTER THE INDEX  YOU WANT TO DELETE"<<endl;
	cin>>index;
	if(index>=size&&index<0){cout<<"INVALID ENTRY"<<endl;
	return;
	}
	for(int i=index+1;i<=size;i++){
		arr[i-1]=arr[i];
	}
	size--;
	cout<<"ELEMENT AT "<<index<<" INDEX DELETED SUCESSFULLY"<<endl;
	traversal(arr,size);
}
// SWAP FUNCTION
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
// INSERTION SORT
void insertion_sort(int *arr,int size){
	for(int i=1;i<size;i++){
		int current=arr[i];
		int j;
		// comparing and shifting
		for(j=i-1;j>=0;j--){
			if(arr[j]>current){
				arr[j+1]=arr[j];
			}
			else{
				break;
			}
		}
		// inserting current at its right position
		arr[j+1]=current;
	}
}
// Merge sort
void merge(int arr[],int si,int ei){
	int size=ei-si+1;
	int mid=(si+ei)/2;
	int *out=new int[size];
	int i=si;
	int j=mid+1;
	int k=0;
	while(i<=mid && j<=ei){
		if(arr[i]<arr[j]){
			out[k]=arr[i];
			i++;
			k++;
		}
		else{
			out[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		out[k]=arr[i];
		k++;
		i++;
	}
	while(j<=ei){
		out[k]=arr[j];
		k++;
		j++;
	}
	int m=0;
	for(int i=si;i<=ei;i++){
		arr[i]=out[m];
		m++;
	}
	delete [] out;
}
void merge_sort(int *arr,int si, int ei){
	//Base case
	if(si>=ei){
		return;
	}
	int mid=(si+ei)/2;
	merge_sort(arr,si,mid);
	merge_sort(arr,mid+1,ei);
	merge(arr,si,ei);
}
// HEAP SORT INPLACE(SPACE COMPEXITY=O(1))
void heap_sort(int *arr,int size){
	// BUILDING THE HEAP IN INPUT ARRAY ITSELF
	for(int i=1;i<size;i++){
		int index_of_child=i;
		// up-heapifying
		while(index_of_child>0){
			int index_of_parent=(index_of_child-1)/2;
			// FOR DESCENDING ORDER SORTING REPLACE '>' TO '<'
			if(arr[index_of_child]>arr[index_of_parent]){
				swap(arr[index_of_child],arr[index_of_parent]);
			}
			else{
				break;
			}
			index_of_child=index_of_parent;
		}
	}
	// REMOVING ELEMENT FROM HEAP ARRAY
	int i=size;
	while(i>1){
		// swaping root node to leaf node
		swap(arr[i-1],arr[0]);
		// removing leaf node
		i=i-1;
		int pi=0;
		// index of childs
		int lci=2*pi+1;
		int rci=2*pi+2;
		// down heapyfying
		while(lci<i){
			// for Descending sort find minimum index
			int max_index=pi;
			if(arr[max_index]<arr[lci]){
				max_index=lci;
			}
			// checking is rc exist or not
			if(rci<i && arr[max_index]<arr[rci]){
				max_index=rci;
			}
			if(max_index==pi){
				break;
			}
			swap(arr[max_index],arr[pi]);
			pi=max_index;
			lci=2*pi+1;
			rci=2*pi+2;
		}

	}
}
// main function
int main(){
    int arr[100];
    int size=0;
	cout<<" ******01916412819*******"<<endl;
	cout<<" ******Aditya_Sharma*****"<<endl;
	int choice;
	do{
      cout<<" ******************************************************"<<endl;
      cout<<" **     ENTER 1 TO  TRAVERSE ON ARRAY                **"<<endl;
      cout<<" **     ENTER 2 TO INSERT AN ELEMENT IN ARRAY        **"<<endl;
      cout<<" **     ENTER 3 TO DELETE AN ELEMENT FORM ARRAY      **"<<endl;
      cout<<" **     ENTER 4 FOR INSERTION SORT ON ARRAY          **"<<endl;
      cout<<" **     ENTER 5 FOR MERGE SORT  ON ARRAY             **"<<endl;
      cout<<" **     ENTER 6 FOR HEAP SORT ON ARRAY               **"<<endl;
      cout<<" **     ENTER 7 TO EXIT                              **"<<endl;
	  cout<<" ******************************************************"<<endl;
		cin>>choice;
		switch(choice){
		    //traversal
			case 1:
			traversal(arr,size);
			break;
			//insertion
			case 2:
			if(size==0){
				cout<<"ENTER THE FIRST ELEMENT TO INSERT IN ARRAY"<<endl;
				cin>>arr[0];
				size++;
			}
			else{
				int choice2;
				int element;
				cout<<"ENTER 1 TO INSERT AT BEGIN"<<endl;
				cout<<"ENTER 2 TO INSERT AT END"<<endl;
				cout<<"ENTER 3 TO INSERT AT ith INDEX"<<endl;
				cin>>choice2;
				cout<<"ENTER THE ELEMENT"<<endl;
				cin>>element;
				if(choice2==1){   insert_at_begin(element,arr,size);    }
				else if(choice2==2){   insert_at_end(element,arr,size);  }
				else if(choice2==3){  insert_at_mid(element,arr,size);   }
				else{   cout<<"ENTER VALID CHOICE"<<endl;       }
			}
			break;
			//deletion
			case 3:
            if(size==0){cout<<"ARRAY IS ALREDY EMPTY,CAN'T DELETE"<<endl;}
			else if(size==1){
				size--;
				cout<<"LAST ELEMENT OF ARRAY DELETED NOW ARRAY IS EMPTY"<<endl;
		    }
		    else{
		    	int choice3;
				cout<<"ENTER 1 TO DELETE FROM BEGINN"<<endl;
				cout<<"ENTER 2 TO DELETE FROM END"<<endl;
				cout<<"ENTER 3 TO DELETE FROM ith INDEX"<<endl;
				cin>>choice3;
				if(choice3==1){  delete_from_begin(arr,size);  }
				else if(choice3==2){  delete_from_end(arr,size); }
				else if(choice==3){  delete_from_mid(arr,size);  }
				else{ cout<<"ENTER VALID CHOICE"<<endl;  }
		    }
		    break;
		    //bubble sort
		    case 4:
		    if(size==0){
		    	cout<<"CAN'T SORT ARRAY IS EMPTY"<<endl;
		    	break;
		    }
		    if(size==1){
		    	cout<<"SINGLE ELEMENT ALREADY SORTED"<<endl;
		    	break;
		    }
		    insertion_sort(arr,size);
		    traversal(arr,size);
		    break;
		    //quick sort
		    case 5:
		    if(size==0){
		    	cout<<"CAN'T SORT ARRAY IS EMPTY"<<endl;
		    	break;
		    }
		    if(size==1){
		    	cout<<"SINGLE ELEMENT ALREADY SORTED"<<endl;
		    	break;
		    }
		    merge_sort(arr,0,size-1);
		    traversal(arr,size);
		    break;
		    //exit
		    case 6:
		    if(size==0){
		    	cout<<"CAN'T SORT ARRAY IS EMPTY"<<endl;
		    	break;
		    }
		    if(size==1){
		    	cout<<"SINGLE ELEMENT ALREADY SORTED"<<endl;
		    	break;
		    }
		    heap_sort(arr,size);
		    traversal(arr,size);
		    break;
		    case 7:
		    cout<<"EXITED SUCESSFULLY"<<endl;
		    exit(0);
		    default: cout<<"ENTER VALID CHOICE"<<endl;
		}
	}while(choice!=7);

return 0;
}
