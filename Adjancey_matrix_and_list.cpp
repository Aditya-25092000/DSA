#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*right;
    node*below;
     node(int data){
     this->data=data;
     right=NULL;
     below=NULL;
    }
};

//main function
int main(){
  int n;
  cout<<"ENTER NO OF VERTICES"<<endl;
  cin >> n ;

  cout<<"ADJ. MATRIX"<<endl;
  // creating a adjancey matrix of n*n size
  int edges[n][n];
  for(int i=0;i<n; i++){
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  for(int i=0; i<e; i++){
  int f,s;
  cout<<"ENTER THE VERTICES(0 to "<<n-1<< ") BETWEEN WHICH THERE IS A EDGE"<<endl;
  cin >> f >> s;
  edges[f][s]=1;
  edges[s][f]=1;
  }
  cout<<endl;
  cout<<"  ";
  for(int k=0;k<n;k++){
    cout<<k<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++){
   cout<<i<<" ";
   for(int j=0;j<n;j++){
    cout<<edges[i][j]<<" ";
   }
   cout<<endl;
  }

  cout<<"*** ADJ. LIST ***"<<endl;
  node*start;
  node*temp;
  for(int i=0;i<n;i++){
    cout<<"ENTER VERTEX PRESENT IN GRAPH "<<endl;
    int data;
    cin>>data;
    node*y=new node(data);
    if(i==0){
      start=y;
      temp=y;
    }
    else{
        temp->below=y;
        temp=temp->below;
    }
    cout<<"ENTER VERTICES WHICH IS CONNECTED TO "<<y->data<<" AND ENTER -1 TO END"<<endl;
    int data1;
    cin>>data1;
    node*x=y;
    while(true){
        if(data1==-1){
            break;
        }
        node*z=new node(data1);
        x->right=z;
        x=z;
        cin>>data1;
    }
  }
  while(start!=NULL){
    cout<<start->data<<"->";
    node*temp=start->right;
    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp=temp->right;
    }
    cout<<"NULL"<<endl;
    cout<<"|"<<endl;
    cout<<"v"<<endl;
    start=start->below;
  }
  cout<<"NULL"<<endl;


  return 0;
}
