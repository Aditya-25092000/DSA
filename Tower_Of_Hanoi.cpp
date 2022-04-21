#include<iostream>
using namespace std;
//tower of hanoi recursion
void tower_of_hanoi_recursion(int n,char source,char auxiliary,char destination,int &step){
	//base case
	if(n==0){
		step++;
		return;
	}
	//moving n-1 disks from source to auxiliary
	tower_of_hanoi_recursion(n-1,source,destination,auxiliary,step);
	//moving last disk from source to destination
	cout<<"STEP "<<step<<" :";
	cout<<"MOVE DISK "<<n<<" FROM "<<source<<"-->"<<destination<<endl;
	//moving n-1 disks from auxiliary to destination
	tower_of_hanoi_recursion(n-1,auxiliary,source,destination,step);
}
//main function
int main(){
	cout<<"******ADITYA_SHARMA*******"<<endl;
	cout<<"*******01916412819********"<<endl;
	//taking input no of disks
	cout<<"ENTER NO OF DISKS"<<endl;
	int n;
	cin>>n;
	//calling tower of hanoi function
	//here A is source,B is auxiliary,C is destination rod
	cout<<"S IS SOURCE || "<<"A IS AUXILIARY || "<<"D IS DESTINATION"<<endl;
	int step=0;
	tower_of_hanoi_recursion(n,'S','A','D',step);
}
