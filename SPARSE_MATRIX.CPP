#include <iostream>
using namespace std;
//input function for sparse matrix
void take_input(int arr[][100],int &row,int &col){
    cout<<"ENTER NO OF ROWS OF SPARSE MATRIX"<<endl;
    cin>>row;
    cout<<"ENTER NO OF COLS OF SPARSE MATRIX"<<endl;
    cin>>col;
    cout<<"ENTER 2D INTEGER ARRAY ROW WISE"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
            }
        }
}
//traversal function for triplet
void traversal_triplet(int arr[][3],int row ,int col){
    cout<<"**************************************"<<endl;
    cout<<"triplet of the given sparse matrix is"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
//function for sparse to triplet
void convert_sparse_to_triplet(int arr[][100],int row,int col,int triplet[][3],int &non_zero){
    triplet[0][0]=row;
    triplet[0][1]=col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]!=0){
                non_zero+=1;
                triplet[non_zero][0]=i;
                triplet[non_zero][1]=j;
                triplet[non_zero][2]=arr[i][j];
            }
        }
    }
    triplet[0][2]=non_zero;
}
int main(){
    int row=0,col=0;
    cout<<"*******ADITYA SHARMA********"<<endl;
    cout<<"********01916412819*********"<<endl;
    cout<<endl;
    //sparse matrix
    int sparse_mat[100][100l];
    //taking input
    take_input(sparse_mat,row,col);
    //triplet
    int triplet[row*col/2][3];
    //no of non zero elements
    int non_zero=0;
    // converting sparse to triplet
    convert_sparse_to_triplet(sparse_mat,row,col,triplet,non_zero);
    //checking if sparse or not
    if(non_zero>((row*col)/4)){
        cout<<"This is not a Sparse Matrix"<<endl;
    }
    //if sparse printing triplet
    else{
    traversal_triplet(triplet,non_zero+1,3);
    }
    return 0;
}
