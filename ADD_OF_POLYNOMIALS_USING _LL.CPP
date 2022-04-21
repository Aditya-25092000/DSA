#include<iostream>
using namespace std;
class node{
public:
	int coffecient;
	int power;
	node*next;
	node(int coffecient,int power){
		this->coffecient=coffecient;
		this->power=power;
		this->next=NULL;
	}
};
void display(node*poly){
	cout<<"POLYNOMIAL IS : ";
	node*temp=poly;
	while(temp!=NULL){
		int coff=temp->coffecient;
		int power=temp->power;
		if(coff==0){
            temp=temp->next;
            continue;
		}
		if(coff>0){
			cout<<"+";
		}
		cout<<coff;
		if(power!=0){
			cout<<"X^"<<power;
		}
        temp=temp->next;
	}
	cout<<endl;
}
void take_input(node*&poly){
	int coff;
	int degree;
	cout<<"ENTER DEGREE OF YOUR POLYNOMIAL"<<endl;
	cin>>degree;
	node*temp=poly;
	while(degree>=0){
		cout<<"ENTER COFFECIENT OF X^"<<degree<<" : "<<endl;
		cin>>coff;
		node*newnode=new node(coff,degree);
		if(temp==NULL){
			poly=newnode;
			temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=temp->next;
		}
		degree--;
	}
}
// add function
void add_poly(node*poly1,node*poly2,node*&poly){
	int coff;
	int power;
	node* poly_tail=NULL;
	while(poly1 && poly2){
		if(poly1->power>poly2->power){
			coff=poly1->coffecient;
			power=poly1->power;
			poly1=poly1->next;
		}
		else if(poly1->power<poly2->power){
			coff=poly2->coffecient;
			power=poly2->power;
			poly2=poly2->next;
		}
		else{
			coff=poly1->coffecient+poly2->coffecient;
			power=poly1->power;
			poly1=poly1->next;
			poly2=poly2->next;
		}
		node*newnode= new node(coff,power);
		if(poly==NULL){
			poly=newnode;
			poly_tail=newnode;
		}
		else{
			poly_tail->next=newnode;
			poly_tail=poly_tail->next;
		}
	}

}
//main function
int main(){
node* poly1=NULL;
node* poly2=NULL;
node* poly=NULL;
//taking input
cout<<"TAKING INPUT FOR POLYNOMIAL ONE"<<endl;
take_input(poly1);
display(poly1);
cout<<"TAKING INPUT FOR POLYNOMIAL TWO"<<endl;
take_input(poly2);
display(poly2);
cout<<"ADDITION OF TWO POLYNOMIALS "<<endl;
add_poly(poly1,poly2,poly);
display(poly);

}
