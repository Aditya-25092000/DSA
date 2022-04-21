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
void traversal(node*head){
	if(head==NULL){
		cout<<"NULL"<<endl;
		return;
	}
	cout<<head->data<<"->";
	traversal(head->next);
}
// reverse linked list
node * reverse_linked_list(node * head){
	if(head->next==NULL){
		return head;
	}
	node* newhead=reverse_linked_list(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
}
// count node recusion
int  count_node(node * head){
	if(head==NULL){
		return 0;
	}
	return 1+ count_node(head->next);
}
// take_input_function
void take_input(node *& head){
	cout<<"ENTER DATA OF LINKED LIST AND ENTER -1 TO END"<<endl;
	int data;
	cin>>data;
	node *tail=head;
	while(data!=-1){
		node* newnode=new node(data);
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
//main function
int main(){
	node*head=NULL;
	take_input(head);
	int choice;
	do{ cout<<"********************************"<<endl;
		cout<<"* ENTER 1  TO COUNT NODE IN LL *"<<endl;
		cout<<"* ENTER 2 TO REVERSE THE LL    *"<<endl;
		cout<<"* ENTER 3 TO EXIT              *"<<endl;
		cout<<"********************************"<<endl;
		cin>>choice;
		switch(choice){
			case 1:{
			int ans=count_node(head);
			cout<<"THERE ARE "<<ans<<" NODES IN OUR LL"<<endl;
			break;
			}
			case 2:{
			cout<<"REVERSED LINKED LIST : ";
			if(head==NULL){
				cout<<"EMPTY LINKED "<<endl;
				break;
			}
			head=reverse_linked_list(head);
			traversal(head);
			break;
			}
			case 3:
			cout<<"EXITED SUCESSFULLY"<<endl;
			exit(0);
			default:
			cout<<"INVALID ENTRY"<<endl;
		}

	}while(choice!=3);
}
