#include<iostream>
#include<stack>
#include<cstring>
#include<math.h>
using namespace std;
bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch == '^');
}
int postfixEvaluate(string S){
    int l=S.length();
    stack<int> s;
    for(int i=0;i<l;i++){
        if(isOperator(S[i])){
            int val2=s.top();   
            s.pop();
            int val1=s.top();    
            s.pop();
            int ans=0;
            if(S[i]=='+')
            ans = val1 + val2;
            else if(S[i]=='-')
            ans = val1 - val2;
            else if(S[i]=='*')
            ans = val1 * val2;
            else if(S[i]=='/')
            ans = val1 / val2;
            else if(S[i]=='^')
            ans = pow(val1,val2);
            s.push(ans);
        }
        else
        s.push(S[i]-'0');
    }
    return s.top();
}

int main(){
	cout<<"******ADITYA_SHARMA*******"<<endl;
	cout<<"*******01916412819********"<<endl;
	cout<<"ENTER POSTFIX EXP"<<endl;
	string postfix_exp;
	cin>>postfix_exp;
	cout<<"EVALUATED VALUE OF "<<postfix_exp<<" is "<<postfixEvaluate(postfix_exp)<<endl;
}
