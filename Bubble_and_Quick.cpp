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
// BUBBLE SORT USING RECURSION
void bubble_sort(int *arr,int size){
	  //BASE CASE
     if(size==1){
     	return;
     }
     for(int i=0;i<size-1;i++){
     	if(arr[i]>arr[i+1]){
     		swap(arr[i],arr[i+1]);
     	}
     }
     bubble_sort(arr,size-1);
}

//position function of quick sort
int partition(int *arr,int si,int ei){
	// taking start element as pivot
	int pivot=arr[si];
	int countSmaller=0;
	for(int i=si+1;i<=ei;i++){
		if(arr[i]<=pivot){
			countSmaller++;
		}
	}
	// pivot_index is right position of pivot in array
	int pivot_index=si+countSmaller;
	// putting pivot at its right position
	swap(arr[si],arr[pivot_index]);
	// now putting values less  or equal than pivot at left side of pivot
	// and putting values greater than pivot at right side of pivot
	int i= si;
	int j=ei;
	while (i < pivot_index && j > pivot_index){
        if(arr[i] <= pivot){
            i++;
        }
        else if(arr[j] > pivot){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
	return pivot_index;
}
//quick sort
void quick_sort(int *arr,int start,int end){
	//base case
	if(start>=end){
		return;
	}
	int pivot_index=partition(arr,start,end);
	quick_sort(arr,start,pivot_index-1);
	quick_sort(arr,pivot_index+1,end);
}
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
      cout<<" **     ENTER 4 FOR BUBBLE SORT ON ARRAY             **"<<endl;
      cout<<" **     ENTER 5 FOR QUICK SORT ON ARRAY              **"<<endl;
      cout<<" **     ENTER 6 TO EXIT                              **"<<endl;
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
		    bubble_sort(arr,size);
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
		    quick_sort(arr,0,size-1);
		    traversal(arr,size);
		    break;
		    //exit
		    case 6:
		    cout<<"EXITED SUCESSFULLY"<<endl;
		    exit(0);
		    default: cout<<"ENTER VALID CHOICE"<<endl;
		}
	}while(choice!=6);

return 0;
}
