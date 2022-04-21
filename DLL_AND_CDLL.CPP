
#include<iostream>
using namespace std;
class Node{
    public:
	int data;
	Node*prev;
	Node*next;
	Node(int data){
		this->data=data;
		this->prev=NULL;
		this->next=NULL;
	}
};
//display functions
void display_dll(Node*head){
	cout<<"DOUBLY LINKED LIST : ";
	Node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"<-->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void display_cdll(Node*head){
	cout<<"CIRCULAR DOUBLY LINKED LIST : ";
	Node*temp=head;
	while(temp->next!=head){
		cout<<temp->data<<"<-->";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}
//insert at begin for dll
void insert_at_beg_dll(Node*&head,int data){
	Node*newnode=new Node(data);
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
	display_dll(head);
}
//insert at end for dll
void insert_at_end_dll(Node*&head,int data){
	Node*tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	Node*newnode=new Node(data);
	tail->next=newnode;
	newnode->prev=tail;
	display_dll(head);
}
//insert at loc in dll
void insert_at_loc_dll(Node*&head,int data){
    display_dll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU TO INSERT"<<endl;
	cin>>loc_data;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp=temp->next;
		if(temp==NULL){
            cout<<"ERROR: LOCATION YOU ENTERED IS  NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==NULL){
		cout<<"CAN'T INSERT CHOOSE INSERT AT END"<<endl;
		return;
	}
	Node*newnode=new Node(data);
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next->prev=newnode;
	temp->next=newnode;
	display_dll(head);
}
//delete at beg in dll
void delete_at_beg_dll(Node*&head){
	Node*temp=head;
	head->next->prev=NULL;
	head=head->next;
	delete temp;
	display_dll(head);
}
// delete at end in dll
void delete_at_end_dll(Node*&head){
	Node*tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->prev->next=NULL;
	delete tail;
	display_dll(head);
}
//delete at loc in dll
void delete_at_loc_dll(Node*&head){
    display_dll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU WANT TO DELETE"<<endl;
	cin>>loc_data;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp=temp->next;
		if(temp==NULL){
            cout<<"ERROR: LOCATION YOU ENTERED IS  NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==NULL){
		cout<<"CAN'T DELETE CHOOSE DELETE AT END"<<endl;
		return;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	delete temp;
	display_dll(head);
}
// insert at beg in cdll
void insert_at_beg_cdll(Node*&head,int data){
	Node*newnode=new Node(data);
	newnode->next=head;
	newnode->prev=head->prev;
	head->prev->next=newnode;
	head->prev=newnode;
	head=newnode;
	display_cdll(head);
}
//insert_at_end in cdll
void insert_at_end_cdll(Node*&head,int data){
	Node*newnode=new Node(data);
	newnode->next=head;
	newnode->prev=head->prev;
	head->prev=newnode;
	newnode->prev->next=newnode;
	display_cdll(head);
}
//insert at loc in cdll
void insert_at_loc_cdll(Node*&head,int data){
    display_cdll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU WANT TO INSERT"<<endl;
	cin>>loc_data;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp=temp->next;
		if(temp==head){
            cout<<"ERROR: LOCATION YOU ENTERED IS  NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==head){
		cout<<"CAN'T INSERT CHOOSE INSERT AT END"<<endl;
		return;
	}
	Node*newnode=new Node(data);
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next->prev=newnode;
	temp->next=newnode;
	display_cdll(head);
}
//delete at begin cdll
void delete_at_beg_cdll(Node*&head){
	Node*temp=head;
	head->prev->next=head->next;
	head->next->prev=head->prev;
	head=head->next;
	delete temp;
	display_cdll(head);
}
//delete at end in cdll
void delete_at_end_cdll(Node*&head){
	Node*temp=head->prev;
	temp->prev->next=head;
	head->prev=temp->prev;
	delete temp;
	display_cdll(head);
}
//delete at loc in cdll
void delete_at_loc_cdll(Node*&head){
    display_cdll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU WANT TO DELETE"<<endl;
	cin>>loc_data;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp=temp->next;
		if(temp==head){
            cout<<"ERROR: LOCATION YOU ENTERED IS  NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==head){
		cout<<"CAN'T DELETE CHOOSE DELETE AT END"<<endl;
		return;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	delete temp;
	display_cdll(head);
}
int main(){
Node*head=NULL;
cout<<"******ADITYA_SHARMA******"<<endl;
cout<<"*******01916412819*******"<<endl;
int choice;
cout<<"ENTER 1 FOR DOUBLY LINKED LIST"<<endl;
cout<<"ENTER 2 FOR CIRCULAR DOUBLY LINKED LIST"<<endl;
cin>>choice;
if(choice==1||choice==2){
	int choice1;
	do{
		cout<<"**************************"<<endl;
		cout<<"* ENTER 1 FOR  INSERTION *"<<endl;
		cout<<"* ENTER 2 FOR DELETION   *"<<endl;
		cout<<"* ENTER 3 FOR EXIT       *"<<endl;
		cout<<"**************************"<<endl;
		cin>>choice1;
		switch(choice1){
			case 1:
			// for first insertion
			if(head==NULL){
				int data;
				cout<<"ENTER FIRST ELEMENT OF LL"<<endl;
				cin>>data;
				Node*newnode=new Node(data);
				head=newnode;
				if(choice==2){
					head->prev=head;
					head->next=head;
					display_cdll(head);
					break;
				}
				display_dll(head);
				break;
			}
			int choice2;
			cout<<"ENTER 1 FOR INSERT AT BEGIN"<<endl;
			cout<<"ENTER 2 FOR INSERT AT END"<<endl;
			cout<<"ENTER 3 FOR INSERT AT A LOCATION"<<endl;
			cin>>choice2;
			if(choice2>3 || choice2<=0){
                cout<<"ERROR : INVALID ENTRY"<<endl;
                break;
			}
			int data;
			cout<<"ENTER DATA YOU WANT TO INSERT"<<endl;
			cin>>data;
			switch(choice2){
				case 1:
				if(choice==1){ insert_at_beg_dll(head,data);}
				else if(choice==2){ insert_at_beg_cdll(head,data);}
				break;
				case 2:
				if(choice==1){ insert_at_end_dll(head,data);}
				else if(choice==2){ insert_at_end_cdll(head,data);}
				break;
				case 3:
				if(choice==1){ insert_at_loc_dll(head,data);}
				else if(choice==2){ insert_at_loc_cdll(head,data);}
				break;
				default:
				cout<<"ERROR: INVALID ENTRY"<<endl;
			}
			break;
			case 2:
			if(head==NULL){
				cout<<"CAN'T DELETE LIST IS EMPTY"<<endl;
				break;
			}
			else if((head->next==NULL && head->prev==NULL)||(head->next==head && head->prev==head)){
				Node*temp=head;
				head=NULL;
				delete temp;
				cout<<"LAST ELEMENT DELETED"<<endl;
				break;
			}
			int choice3;
			cout<<"ENTER 1 FOR DELETE AT BEGIN"<<endl;
			cout<<"ENTER 2 FOR DELETE AT END"<<endl;
			cout<<"ENTER 3 FOR DELETE AT A LOCATION"<<endl;
			cin>>choice3;
			switch(choice3){
				case 1:
				if(choice==1){ delete_at_beg_dll(head);}
				else if(choice==2){ delete_at_beg_cdll(head);}
				break;
				case 2:
				if(choice==1){ delete_at_end_dll(head);}
				else if(choice==2){ delete_at_end_cdll(head);}
				break;
				case 3:
				if(choice==1){ delete_at_loc_dll(head);}
				else if(choice==2){ delete_at_loc_cdll(head);}
				break;
				default:
				cout<<"ERROR: ENTER VALID ENTRY"<<endl;
			}
			break;
			case 3:
			cout<<"EXITED SUCESSFULLY"<<endl;
			exit(0);
			default:
			cout<<"ERROR: ENTER VALID CHOICE"<<endl;
		}
	}while(choice!=3);
}
else{
	cout<<"ERROR:INVALID ENTRY"<<endl;
	}
}
