#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*next;
	node(int data){
		this->data=data;
		this->next=NULL;
	}
};
//using recursion
void display(node*head){
	if(head==NULL){
		cout<<"NULL"<<endl;
		return;
	}
	cout<<head->data<<"->";
	display(head->next);
}
//take input
void take_input(node*&head){
	cout<<"ENTER ELEMENTS OF LINKED LIST AND ENTER -1 TO END TAKING INPUT"<<endl;
	int data;
	cin>>data;
	node*tail=head;
	while(data!=-1){
		node * newnode=new node(data);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=tail->next;
		}
		cin>>data;
	}
}
//linear search recursive method
void linear_search(node*head,int count,int data){
	if(head==NULL){
		cout<<"THIS ELEMENT IS NOT PRSENT IN LINKED LIST"<<endl;
		return;
	}
	if(head->data==data){
		cout<<"THIS ELEMENT IS PRESENT AT "<<count<<" POSITION IN LINKED LIST"<<endl;
		return;
	}
	linear_search(head->next,count+1,data);
}
//selection sort
void selection_sort(node*&head){
	if(head==NULL){
		cout<<"CAN'T SORT,LINKED LIST IS EMPTY"<<endl;
		return;
	}
	if(head->next==NULL){
		cout<<"SINGLE ELEMENT ALREADY SORTED"<<endl;
		return;
	}
	node* temp=head;
	while(temp!=NULL){
		node* min=temp;
		node* temp1=temp->next;
		while(temp1!=NULL){
			if(min->data>temp1->data){
				min=temp1;
			}
			temp1=temp1->next;
		}
		//swaping nodes
		int temp_data=temp->data;
		temp->data=min->data;
		min->data=temp_data;
		temp=temp->next;
	}
}
//main function
int main(){
	node*head=NULL;
	take_input(head);
	display(head);
	int choice;
	do{
        cout<<"ENTER 1 FOR LINEAR SEARCH/ 2 FOR SELECTION SORT/ 3 FOR EXIT"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            int data;
            cout<<"ENTER DATA YOU WANT TO SEARCH"<<endl;
            cin>>data;
            linear_search(head,1,data);
            break;
        case 2:
            selection_sort(head);
            cout<<"SORTED LINKED LIST "<<endl;
            display(head);
            break;
        case 3:
            exit(0);
        default:
            cout<<"ENTER VALID CHOICE"<<endl;

        }
	}while(choice!=3);
}
