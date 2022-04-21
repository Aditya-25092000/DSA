#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int data){
this->data=data;
this->next=NULL;
}
};
void display_sll(Node*&head){
	cout<<"SINGLY LINKED LIST: ";
	Node*temp=head;
	while(temp->next!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<"->";
	cout<<"NULL";
	cout<<endl;
}
void display_csll(Node*&head){
	cout<<"CIRCULAR SINGLY LINKED LIST: ";
	Node*temp=head;
	while(temp->next!=head){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}
// insert at begin for SLL
void insert_at_begin_sll(Node*&head,int data){
	Node* newnode=new Node(data);
	newnode->next=head;
	head=newnode;
	display_sll(head);
}
//insert at end for SLL
void insert_at_end_sll(Node*&head,int data){
	Node*newnode=new Node(data);
	Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	display_sll(head);
}
//insert at loc for sll
void insert_at_loc_sll(Node*&head,int data){
	int loc_data;
	display_sll(head);
	cout<<"ENTER DATA OF LOCATION WHERE YOU WANT TO INSERT"<<endl;
	cin>>loc_data;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp=temp->next;
		if(temp==NULL){
            cout<<"LOCATION YOU ENTERED IS NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==NULL){
        cout<<"CAN,T INSERT CHOOSE INSERT AT END"<<endl;
        return;
	}
	Node*newnode=new Node(data);
	newnode->next=temp->next;
	temp->next=newnode;
	display_sll(head);
}
//delete at begin sll
void delete_at_begin_sll(Node*&head){
	Node*temp=head;
	head=head->next;
	delete temp;
	display_sll(head);
}
//delete at end sll
void delete_at_end_sll(Node*&head){
	Node*temp=head;
	Node*temp_prev=head;
	while(temp->next!=NULL){
		temp_prev=temp;
		temp=temp->next;
	}
	temp_prev->next=NULL;
	delete temp;
	display_sll(head);
}
//delete at loc in sll
void delete_at_loc_sll(Node*&head){
	display_sll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU WANT TO DELETE"<<endl;
	cin>>loc_data;
	Node*temp=head;
	Node*temp_prev=head;
	while(temp->data!=loc_data){
		temp_prev=temp;
		temp=temp->next;
		if(temp==NULL){
            cout<<"LOCATION YOU ENTERED IS NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==NULL){
        cout<<"CAN'T DELETE CHOOSE DELETE AT END"<<endl;
        return;
	}
	temp_prev->next=temp->next;
	delete temp;
	display_sll(head);
}
//insert at begin at CSLL
void insert_at_begin_csll(Node*&head,int data){
	Node*temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	Node*newnode=new Node(data);
	newnode->next=head;
	head=newnode;
	temp->next=newnode;
	display_csll(head);
}
//insert at end in Csll
void insert_at_end_csll(Node*&head,int data){
	Node*tail=head;
	while(tail->next!=head){
		tail=tail->next;
	}
	Node*newnode=new Node(data);
	newnode->next=head;
	tail->next=newnode;
	display_csll(head);
}
// insert at loc in csll
void insert_at_loc_csll(Node*&head,int data){
	display_csll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU WANT TO INSERT"<<endl;
	cin>>loc_data;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp=temp->next;
		if(temp==head){
            cout<<"LOCATION YOU ENTERED IS NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==head){
        cout<<"CAN'T INSERT CHOOSR INSERT AT END"<<endl;
        return;
	}
	Node*newnode=new Node(data);
	newnode->next=temp->next;
	temp->next=newnode;
	display_csll(head);
}
//delete at begin in csll
void delete_at_begin_csll(Node*&head){
	Node*tail=head;
	while(tail->next!=head){
		tail=tail->next;
	}
	tail->next=head->next;
	Node*temp=head;
	head=head->next;
	delete temp;
	display_csll(head);
}
//delete at end in csll
void delete_at_end_csll(Node*&head){
	Node*tail=head;
	Node*tail_prev=head;
	while(tail->next!=head){
		tail_prev=tail;
		tail=tail->next;
	}
	tail_prev->next=head;
	delete tail;
	display_csll(head);
}
//delete at loc csll
void delete_at_loc_csll(Node*&head){
	display_csll(head);
	int loc_data;
	cout<<"ENTER DATA OF LOCATION AT WHICH YOU WANT TO DELETE"<<endl;
	cin>>loc_data;
	Node*temp_prev=head;
	Node*temp=head;
	while(temp->data!=loc_data){
		temp_prev=temp;
		temp=temp->next;
		if(temp==head){
            cout<<"LOCATION YOU ENTERED IS NOT PRESENT IN LL"<<endl;
            return;
		}
	}
	if(temp->next==head){
        cout<<"CAN'T DELETE CHOOSE DELETE AT END"<<endl;
        return;
	}
	temp_prev->next=temp->next;
	delete temp;
	display_csll(head);
}

//main function
int main(){
    cout<<"*******ADITYA_SHARMA********"<<endl;
	cout<<"********01916412819*********"<<endl;
	Node*head=NULL;
	int choice;
	cout<<"ENTER 1 FOR SINGLY LINKED LIST"<<endl;
	cout<<"ENTER 2 FOR CIRCULAR SINGLY LINKED LIST"<<endl;
	cin>>choice;
	if(choice==1 || choice==2){
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
			if(head==NULL){
				int data;
				cout<<"INSERT FIRST ELEMENT OF LL"<<endl;
				cin>>data;
				Node*newnode=new Node(data);
				head=newnode;
				if(choice==2){
                    head->next=head;
				}
				cout<<"LINKED LIST IS :"<<head->data<<endl;
				break;
			}
			int choice2;
			cout<<"ENTER 1 FOR INSERT AT BEGIN"<<endl;
			cout<<"ENTER 2 FOR INSERT AT END"<<endl;
			cout<<"ENTER 3 FOR INSERT AT LOCATION"<<endl;
			cin>>choice2;
			if(choice2>3 || choice2<=0){
                cout<<"ERROR: ENTER VALID CHOICE"<<endl;
                break;
			}
			int data;
			cout<<"ENTER DATA YOU WANT TO INSERT"<<endl;
			cin>>data;
            if(choice2==1){
				if(choice==1){ insert_at_begin_sll(head,data);}
				else if(choice==2){insert_at_begin_csll(head,data);}
			}
			else if(choice2==2){
				if(choice==1){ insert_at_end_sll(head,data);}
				else if(choice==2){ insert_at_end_csll(head,data);}
			}
			else if(choice2==3){
				if(choice==1){ insert_at_loc_sll(head,data);}
				else if(choice==2){ insert_at_loc_csll(head,data);}
			}
			break;
			case 2:
			if(head==NULL){
				cout<<"CAN'T DELETE,LL IS EMPTY"<<endl;
				break;
			}
			if(head->next==NULL||head->next==head){
                Node*temp=head;
                head=NULL;
                delete temp;
                cout<<"NOW LL IS EMPTY"<<endl;
                break;
			}
			int choice3;
			cout<<"ENTER 1 FOR DELETE AT BEGIN"<<endl;
			cout<<"ENTER 2 FOR DELETE AT END"<<endl;
			cout<<"ENTER 3 FOR DELETE AT LOCATION"<<endl;
			cin>>choice3;
			if(choice3>3 || choice3<=0){
                cout<<"ERROR: ENTER VALID CHOICE"<<endl;
                break;
			}
			if(choice3==1){
				if(choice==1){ delete_at_begin_sll(head);}
				else if(choice==2){delete_at_begin_csll(head);}
			}
			else if(choice3==2){
				if(choice==1){ delete_at_end_sll(head);}
				else if(choice==2){ delete_at_end_csll(head);}
			}
			else if(choice3==3){
				if(choice==1){ delete_at_loc_sll(head);}
				else if(choice==2){ delete_at_loc_csll(head);}
			}
			else{
				cout<<"ENTER VALID ENTRY"<<endl;
			}
			break;
			case 3:
			cout<<"EXITED SUCESSFULLY"<<endl;
			exit(0);
			default:
			cout<<"ERROR: ENTER VALID CHOICE"<<endl;
		}
	}while(choice1!=3);
	}
	else{
        cout<<"ERROR:INVALID ENTRY"<<endl;
	}

}
