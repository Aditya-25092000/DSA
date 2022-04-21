#include<iostream>
using namespace std;
//display function
void display(int *arr,int front,int rear){
	for(int i=rear;i>=front;i--){
		cout<<"*  "<<arr[i]<<"  *"<<endl;
	}
}
//if full function
bool isfull(int front,int rear){
	return front>rear;
}
// is emty function
bool isempty(int index){
	return index==0;
}
// enqueue function
void enqueue(int *arr,int &index){
	if(isfull(index)){
		cout<<"QUEUE IS FULL CAN'T ENQUEUE"<<endl;
		return;
	}
	int value;
	cout<<"ENTER THE VALUE YOU WANT TO ENQUEUE"<<endl;
	cin>>value;
	arr[index]=value;
	index++;
}
// dequeue function
void dequeue(int *arr,int &index){
	if(isempty(index)){
		cout<<"QUEUE IS EMPTY CAN'T DEQUEUE"<<endl;
		return;
	}
	cout<<arr[0]<<" DEQUEUED SUCESSFULLY "<<endl;
    index
}
// front function
void front(int*arr,int index){
	if(isempty(index)){
		cout<<"QUEUE IS EMPTY"<<endl;
		return;
	}
	cout<<arr[0]<<" IS AT FRONT OF QUEUE"<<endl;
}
int main(){
	cout<<"*******ADITYA_SHARMA********"<<endl;
	cout<<"********01916412819*********"<<endl;
	int arr[5];
	int index=0;
	int choice;
	do{
		cout<<" ***************************************"<<endl;
        cout<<" **     ENTER 1 FOR ENQUEUE           **"<<endl;
        cout<<" **     ENTER 2 FOR DEQUEUE           **"<<endl;
        cout<<" **     ENTER 3 FOR  FRONT            **"<<endl;
        cout<<" **     ENTER 4 TO CHECK IS FULL      **"<<endl;
        cout<<" **     ENTER 5 TO CHECK IS EMPTY     **"<<endl;
        cout<<" **     ENTER 6 TO EXIT               **"<<endl;
		cout<<" ***************************************"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				enqueue(arr,index);
				break;
			case 2:
				dequeue(arr,index);
				break;
			case 3:
				front(arr,index);
				break;
			case 4:
				if(isfull(index)){
					cout<<"QUEUE IS FULL"<<endl;
				}
				else{
					cout<<"QUEUE IS NOT FULL"<<endl;
				}
				break;
			case 5:
				if(isempty(index)){
					cout<<"QUEUE IS EMPTY"<<endl;
				}
				else{
					cout<<"QUEUE IS NOT EMPTY"<<endl;
				}
				break;
			case 6:
				cout<<"EXITED SUCESSFULLY"<<endl;
				exit(0);
			default:
				cout<<"ERROR: ENTER VALID CHOICE"<<endl;
		}
	}while(choice!=6);
}
