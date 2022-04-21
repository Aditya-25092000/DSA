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
void display(node*head){
	if(head==NULL){
		cout<<"->NULL"<<endl;
		return;
	}
	cout<<head->data<<"->";
	display(head->next);
}
void take_input(node *& head){
	cout<<"ENTER ELEMENTS OF LINKED LIST AND ENTER -1 TO END"<<endl;
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
node* merge_two_sorted_linked_list(node*head1,node*head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	node*newhead;
	if(head1->data>head2->data){
		newhead=head2;
		newhead->next=merge_two_sorted_linked_list(head1,head2->next);
	}
	if(head2->data>=head1->data){
		newhead=head1;
		newhead->next=merge_two_sorted_linked_list(head1->next,head2);
	}
	return newhead;
}
bool is_sorted(node*head){
	if(head==NULL||head->next==NULL){
		return true;
	}
	if(head->data>head->next->data){
		return false;
	}
	return is_sorted(head->next);
}
int main(){
node*head1=NULL;
node*head2=NULL;
node*head3=NULL;
cout<<"TAKING INPUT FOR FIRST LINKED LIST"<<endl;
take_input(head1);
if(!is_sorted(head1)){
	cout<<"ERROR : LINKED LIST IS NOT SORTED"<<endl;
	return 0;
}
take_input(head2);
if(!is_sorted(head2)){
	cout<<"ERROR : LINKED LIST IS NOT SORTED"<<endl;
	return 0;
}
head3=merge_two_sorted_linked_list(head1,head2);
cout<<"MERGED LINKED LIST : ";
display(head3);
}
