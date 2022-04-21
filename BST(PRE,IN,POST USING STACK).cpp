#include<iostream>
#include<stack>
using namespace std;
// BST NODE CLASS
class node{
public:
	int data;
	node*left;
	node*right;
	node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};
// INSERT FUNCTION IN BST
node* insert(node*root,int data){
	//BASE CASE
	if(root==NULL){
		node* newnode=new node(data);
		root=newnode;
		return root;
	}
	// IF DATA IS SMALLER THEN ROOT DATA
	if(data<root->data){
		root->left=insert(root->left,data);
	}
	//IF DATA IS GREATER OR EQUAL TO  ROOT DATA
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
//DISPLAY FUNCTION IN BST
void display(node*root){
    //BASE CASE
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<"LEFT CHILD -> "<<root->left->data<<" ,";
    }
    if(root->right){
        cout<<"RIGHT CHILD -> "<<root->right->data;
    }
    cout<<endl;
    display(root->left);
    display(root->right);
}
//DELETE FUNCTION IN BST
node* del_node(node*root,int data){
	if(root==NULL){
		return NULL;
	}
	if(root->data>data){
		root->left=del_node(root->left,data);
		return root;
	}
	else if(root->data<data){
		root->right=del_node(root->right,data);
		return root;
	}
	//WHEN DATA=ROOT->DATA
	else{
		if(!root->left && !root->right){
			delete root;
			return NULL;
		}
		else if(!root->left){
			node*temp=root->right;
			root->right=NULL;
			delete root;
			return temp;
		}
		else if(!root->right){
			node*temp=root->left;
			root->left=NULL;
			delete root;
			return temp;
		}
		else{
			node* left_max=root->left;
			while(left_max->right){
				left_max=left_max->right;
			}
			//SWAPING LEFT_MAX AND ROOT DATA
			root->data=root->data^left_max->data;
			left_max->data=root->data^left_max->data;
			root->data=root->data^left_max->data;

			root->left=del_node(root->left,data);
			return root;
		}
	}
}

// INORDER FUNCTION (LEFT-ROOT-RIGHT)
void inorder(node*root){
   stack<node*>s;
   node*ptr=root;
   while(ptr!=NULL || !s.empty()){
   	if(ptr!=NULL){
        s.push(ptr);
        ptr=ptr->left;
        }

   	else if(ptr==NULL){
   	    node*temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
   		if(temp->right!=NULL){
   			ptr=temp->right;
   		}
   	}
   }
}
// PREORDER FUNCTION (ROOT-LEFT-RIGHT)
void  preorder(node*root){
	node*ptr=root;
	// creating an stack of type node * using stack
	stack<node*>s;
	s.push(root);
	while(!s.empty()){
		node*temp=s.top();
		s.pop();
		//traversing left wards and pushing right child if not null
		while(temp!=NULL){
			cout<<temp->data<<" ";
			if(temp->right!=NULL){
				s.push(temp->right);
			}
			temp=temp->left;
		}
	}
}
//POSTORDER FUNCTION (LEFT-RIGHT-ROOT)
void postorder(node*root){
	stack<node*>s;
	node*ptr=root;
	while(ptr!=NULL || !s.empty()){
		s.push(ptr);
		if(ptr->right!=NULL){
			//to differentiate right node we have added extra null in stack
			s.push(ptr->right);
			s.push(NULL);
		}
		ptr=ptr->left;
		if(ptr==NULL){
			while(s.top()!=NULL){
				cout<<s.top()->data<<" ";
				s.pop();
				//for last element of stack i.e root node
				if(s.empty()){
                    return;
				}
			}
			s.pop();
			ptr=s.top();
			s.pop();
		}
	}
}
int main(){
int choice;
node*root=NULL;
do{
	cout<<"***********************************"<<endl;
	cout<<"* ENTER 1 FOR INSERTION IN BST    *"<<endl;
	cout<<"* ENTER 2 FOR DELETION IN BST     *"<<endl;
	cout<<"* ENTER 3 FOR INORDER TRAVERSAL   *"<<endl;
	cout<<"* ENTER 4 FOR PREORDER TRAVERSAL  *"<<endl;
	cout<<"* ENTER 5 FOR POSTORDER TRAVERSAL *"<<endl;
	cout<<"* ENTER 6 TO EXIT                 *"<<endl;
	cout<<"***********************************"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
		int data;
		cout<<"ENTER DATA YOU WANT TO INSERT"<<endl;
		cin>>data;
		root=insert(root,data);
		cout<<"******BST******"<<endl;
		display(root);
		break;
		case 2:
        if(root==NULL){
            cout<<"ERROR : TREE IS EMPTY"<<endl;
            break;
        }
		int data1;
		cout<<"ENTER DATA YOU WANT TO DELETE"<<endl;
		cin>>data1;
		root=del_node(root,data1);
		cout<<data1<<" IS DELETED FORM BST"<<endl;
		cout<<"******BST******"<<endl;
		if(root==NULL){
            cout<<"NOW BST IS EMPTY !! "<<endl;
            break;
		}
		display(root);
		break;
		case 3:
        if(root==NULL){
            cout<<"ERROR : CAN'T TRAVERSE BST IS EMPTY"<<endl;
            break;
        }
		inorder(root);
		cout<<endl;
		break;
		case 4:
        if(root==NULL){
            cout<<"ERROR : CAN'T TRAVERSE BST IS EMPTY"<<endl;
            break;
        }
		preorder(root);
		cout<<endl;
		break;
		case 5:
        if(root==NULL){
            cout<<"ERROR : CAN'T TRAVERSE BST IS EMPTY"<<endl;
            break;
        }
		postorder(root);
		cout<<endl;
		break;
		case 6:
		cout<<"EXITED SUCESSFULLY !!"<<endl;
		exit(0);
		default:
		cout<<"ERROR : ENTER VALID CHOICE !!"<<endl;
		}
	}while(choice!=6);
}
