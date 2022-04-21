#include<iostream>
using namespace std;
class node{
    public:
	int data;
	node*next;
	//constructor
	node( int data){
		this->data=data;
		this->next=NULL;
	}
	//destructor
};
//display function for stack
void display_stack(node*head){
	if(head==NULL){
		return;
	}
	display_stack(head->next);
	cout<<"*  "<<head->data<<"  *"<<endl;
}
//display function for queue
void display_queue(node*head){
	if(head==NULL){
		return;
	}
	display_queue(head->next);
	cout<<"*  "<<head->data<<"  *"<<endl;
}
// push function for stack
void push_in_stack(node*&head,node*&tail){
	int data;
	cout<<"ENTER DATA YOU WANT PUSH IN STACK"<<endl;
	cin>>data;
	node*newnode=new node(data);
	if(head==NULL && tail==NULL){
		head=newnode;
		tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=tail->next;
	}
	cout<<data<<" IS PUSHED IN STACK"<<endl;
	cout<<endl;
	display_stack(head);
	cout<<"********"<<endl;
}
//pop function for stack
void pop_in_stack(node*&head,node*&tail){
	if(head==NULL){
		cout<<"CAN'T POP NO ELEMENT IN STACK"<<endl;
		return;
	}
	if(head->next==NULL){
        delete head;
        head=NULL;
        tail=NULL;
        cout<<" LAST ELEMENT IS POPED ,NOW STACK IN EMPTY"<<endl;
        return;
	}
	node*tail_prev=head;
	while(tail_prev->next!=tail){
		tail_prev=tail_prev->next;
	}
	cout<<tail->data<<" IS POPED FROM STACK"<<endl;
	tail_prev->next=NULL;
	delete tail;
	tail=tail_prev;
	cout<<endl;
	display_stack(head);
	cout<<"********"<<endl;
}
// enqueue for queue
void enqueue(node*&head,node*&tail){
	int data;
	cout<<"ENTER DATA YOU WANT ENQUEUE IN QUEUE"<<endl;
	cin>>data;
	node* newnode=new node(data);
	if(head==NULL && tail==NULL){
		tail=newnode;
		head=newnode;
	}
	else{
		tail->next=newnode;
		tail=tail->next;
	}
	cout<<data<<" IS ENQUEUED IN QUEUE"<<endl;
	cout<<endl;
	display_queue(head);
}
void deqeue(node*&head,node*&tail){
	if(head==NULL){
		cout<<"CAN'T DEQUEUE, NO ELEMENT IN QUEUE"<<endl;
		return;
	}
	if(head->next==NULL){
        head=NULL;
        tail=NULL;
        cout<<"LAST ELEMENT DEQUEUED"<<endl;
        return;
	}
	cout<<head->data<<" IS DEQUEUED FROM QUEUE"<<endl;
	head=head->next;
	display_queue(head);
}
//main function
int main(){
cout<<"******ADITYA_SHARMA******"<<endl;
cout<<"*******01916412819*******"<<endl;
node*head=NULL;
node*tail=NULL;
// choice for stack and queue
int choice;
cout<<"ENTER 1 FOR STACK/ 2 FOR QUEUE"<<endl;
cin>>choice;
if(choice==1){
	int choice1;
	do {
		cout<<"********************"<<endl;
		cout<<"* ENTER 1 FOR PUSH *"<<endl;
		cout<<"* ENTER 2 FOR POP  *"<<endl;
		cout<<"* ENTER 3 FOR EXIT *"<<endl;
		cout<<"********************"<<endl;
		cin>>choice1;
			switch(choice1){
			case 1:
			push_in_stack(head,tail);
			break;
			case 2:
			pop_in_stack(head,tail);
			break;
			case 3:
			cout<<"EXITED SUCESSFULLY"<<endl;
			exit(0);
			default:
			cout<<"ERROR : ENTER VALID CHOICE"<<endl;
				}
	}while(choice1!=3);
}
else if(choice==2){
	int choice1;
	do {
		cout<<"***********************"<<endl;
		cout<<"* ENTER 1 FOR ENQUEUE *"<<endl;
		cout<<"* ENTER 2 FOR DEQUEUE *"<<endl;
		cout<<"* ENTER 3 FOR EXIT    *"<<endl;
		cout<<"***********************"<<endl;
		cin>>choice1;
			switch(choice1){
			case 1:
			enqueue(head,tail);
			break;
			case 2:
			deqeue(head,tail);
			break;
            case 3:
			cout<<"EXITED SUCESSFULLY"<<endl;
			exit(0);
			default:
			cout<<"ERROR : ENTER VALID CHOICE"<<endl;
				}
	}while(choice1!=4);
}
else{
	cout<<"ERROR: INVALID ENTRY"<<endl;
}

}
