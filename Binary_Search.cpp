#include<iostream>
#include<algorithm>
using namespace std;
//binary search function using recursion
void Binary_search(int *arr,int start,int End,int value){
	//base case
	if (start>End){
		cout<<value<<" IS NOT PRESENT IN THE ARRAY"<<endl;
		return;
	}
	//calculating mid index
	int mid=(start+End)/2;
	//checking if value is equal to element at mid index
	if (arr[mid]==value){
		cout<<value<<" IS AT "<<mid<<" INDEX IN THE ARRAY "<<endl;
		return;
	}
	//if value is less then arr[mid],then it may be found at left subarray
	else if(arr[mid]>value){
		Binary_search(arr,start,mid-1,value);
	}
	//if value is greater then arr[mid],the it may be found at right subarray
	else{
		Binary_search(arr,mid+1,End,value);
	}


}
//main function
int main(){
	cout<<"******ADITYA_SHARMA*******"<<endl;
	cout<<"*******01916412819********"<<endl;
	//taking input size
	int size;
	cout<<"ENTER THE SIZE OF AN ARRAY"<<endl;
	cin>>size;
	//taking input element of array
	cout<<"ENTER THE ELEMENTS OF AN ARRAY IN SORTED MANNER"<<endl;
	int arr[100];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	//CHECKING THAT ARRAY IS SORTED OR NOT
    if(!is_sorted(arr,arr+size)){
    cout<<"ERROR: ARRAY IS NOT SORTED"<<endl;
    return 0;
    }
	//taking input element user want to search
	cout<<"ENTER THE ELEMENT YOU WANT TO SEARCH IN ARRAY"<<endl;
	int element;
	cin>>element;
	//calling binary search function
	Binary_search(arr,0,size-1,element);

}
