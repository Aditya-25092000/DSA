#include<iostream>
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
// SEARCH SMALLEST IN BST
void search_small(node*root){
	if(root->left==NULL){
		cout<<root->data<<" IS SMALLEST IN BST"<<endl;
		return;
	}
	search_small(root->left);
}
// SEARCH LARGEST IN BST
void search_larg(node*root){
	if(root->right==NULL){
		cout<<root->data<<" IS LARGEST IN BST"<<endl;
		return;
	}
	search_larg(root->right);
}
// SEARCH PARTICULAR ELEMENT IN BST
bool search_particular(node*root,int data){
	if(root==NULL){
		return false;
	}
	if(root->data==data){
		return true;
	}
	// IF ROOT->DATA IS LESS THEN DATA
	if(root->data<data){
		return search_particular(root->right,data);
	}
	// IF ROOT->DATA IS GREATER THEN DATA
	else{
		return search_particular(root->left,data);
	}
}
// INORDER FUNCTION (LEFT-ROOT-RIGHT)
void inorder(node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
// PREORDER FUNCTION (ROOT-LEFT-RIGHT)
void  preorder(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
//POSTORDER FUNCTION (LEFT-RIGHT-ROOT)
void postorder(node*root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main(){
int choice;
node*root=NULL;
do{
	cout<<"***********************************"<<endl;
	cout<<"* ENTER 1 FOR INSERTION IN BST    *"<<endl;
	cout<<"* ENTER 2 FOR DELETION IN BST     *"<<endl;
	cout<<"* ENTER 3 TO SEARCH IN BST        *"<<endl;
	cout<<"* ENTER 4 FOR INORDER TRAVERSAL   *"<<endl;
	cout<<"* ENTER 5 FOR PREORDER TRAVERSAL  *"<<endl;
	cout<<"* ENTER 6 FOR POSTORDER TRAVERSAL *"<<endl;
	cout<<"* ENTER 7 TO EXIT                 *"<<endl;
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
		if(!search_particular(root,data1)){
            cout<<"ERROR: DATA YOU ENTERED IN NOT PRESENT"<<endl;
            break;
		}
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
            cout<<"ERROR : CAN'T SEARCH BST IS EMPTY"<<endl;
            break;
        }
		int choice2;
		cout<<"**************************************"<<endl;
		cout<<"ENTER 1 TO SEARCH SMALLEST IN BST    *"<<endl;
		cout<<"ENTER 2 TO SEARCH LARGEST IN BST     *"<<endl;
		cout<<"ENTER 3 TO SEARCH PARTICULAR ELEMENT *"<<endl;
		cout<<"**************************************"<<endl;
		cin>>choice2;
		switch(choice2){
			case 1:
			search_small(root);
			break;
			case 2:
			search_larg(root);
			break;
			case 3:
			int data2;
			cout<<"ENTER ELEMENT YOU WANT TO SEARCH"<<endl;
			cin>>data2;
			if(search_particular(root,data2)){
				cout<<"YES !! THIS ELEMENT IS PRESENT IN BST"<<endl;
			}
			else{
				cout<<"NO !! THIS ELEMENT IS NOT PRESENTIN BST"<<endl;
			}
			break;
		}
		break;
		case 4:
        if(root==NULL){
            cout<<"ERROR : CAN'T TRAVERSE BST IS EMPTY"<<endl;
            break;
        }
		inorder(root);
		cout<<endl;
		break;
		case 5:
        if(root==NULL){
            cout<<"ERROR : CAN'T TRAVERSE BST IS EMPTY"<<endl;
            break;
        }
		preorder(root);
		cout<<endl;
		break;
		case 6:
        if(root==NULL){
            cout<<"ERROR : CAN'T TRAVERSE BST IS EMPTY"<<endl;
            break;
        }
		postorder(root);
		cout<<endl;
		break;
		case 7:
		cout<<"EXITED SUCESSFULLY !!"<<endl;
		exit(0);
		default:
		cout<<"ERROR : ENTER VALID CHOICE !!"<<endl;
		}
	}while(choice!=7);
}
