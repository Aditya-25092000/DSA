
#include <iostream>
using namespace std;

int queue[100], n = 5, front = - 1, rear = -1;

void isEmpty(){
    if(front==-1 || front>rear)
        cout<<"  QUEUE IS EMPTY."<<endl;
    else
        cout<<"  NO."<<endl;
    return;
}

void isFull(){
    if(rear==n-1)
        cout<<  "  QUEUE IS FULL."<<endl;
     else
        cout<<"  NO."<<endl;
    return;
}

void Insert() {
   int val;
   if (rear == n - 1)
   cout<<"  QUEUE OVERFLOW"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"  INSERT ELEMENT IN QUEUE : ";
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}
void Delete() {
   if (front == - 1 || front > rear) {
      cout<<"  QUEUE UNDERFLOW."<<endl;
      return ;
   } else {
      cout<<"  ELEMENT DELETED FROM QUEUE : "<< queue[front] <<endl;
      front++;;
   }
}

void Display() {
   if (front == - 1)
   cout<<"  QUEUE IS EMPTY."<<endl;
   else {
      cout<<"  ELEMENTS ARE : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
    }
}
int main() {
   int ch;
   cout<<"  QUEUE USING ARRAYS (CYCLIC WAY)"<<endl;
   do {
         cout<<"\n  1) INSERT ELEMENT IN QUEUE"<<endl;
         cout<<"  2) DELETE ELEMENT IN QUEUE"<<endl;
         cout<<"  3) CHECK IF QUEUE IS EMPTY"<<endl;
         cout<<"  4) CHECK IF QUEUE IS FULL"<<endl;
         cout<<"  5) EXIT"<<endl;
         cout<<"  ENTER YOUR CHOICE : ";
      cin>>ch;
      switch (ch) {
         case 1: Insert();
         Display();
         break;
         case 2: Delete();
         Display();
         break;
         case 3: isEmpty();
         break;
         case 4: isFull();
         break;
         case 5: cout<<"  EXIT."<<endl;
         break;
         default: cout<<"  INVALID INPUT."<<endl;
      }
   } while(ch!=5);
   return 0;
}
