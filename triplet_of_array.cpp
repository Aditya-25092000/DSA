#include <iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    int non_zero=0;
    int triplet[(m*n)/4][3];
    triplet[0][0]=m;
    triplet[0][1]=n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0){
                non_zero+=1;
                triplet[non_zero][0]=i;
                triplet[non_zero][1]=j;
                triplet[non_zero][2]=arr[i][j];
            }
        }
    }
triplet[0][2]=non_zero;
for(int i=0;i<non_zero+1;i++){
    for(int j=0;j<3;j++){
        cout<<triplet[i][j]<<" ";
    }
    cout<<endl;
}


}
