#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return true;
  } else {
    return false;
  }
}

bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '%':
    return true;
  }
  return false;
}

string PrefixToPostfix(string prefix) {
  stack < string > s;
  for (int i = prefix.length() - 1; i >= 0; i--) {
    if (isOperand(prefix[i])) {
      string op(1, prefix[i]);
      s.push(op);
    } else {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      s.push(op1 + op2 + prefix[i]);
    }
  }

  return s.top();
}
string PrefixToInfix(string pre_exp) {
	
  stack<string> s;
  int length = pre_exp.size();
 
  for (int i = length - 1; i >= 0; i--) {
 
    if (isOperator(pre_exp[i])) {
 
      string op1 = s.top();   
	  s.pop();
      string op2 = s.top();   
	  s.pop();
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";
      s.push(temp);
    }
    else {
      s.push(string(1, pre_exp[i]));
    }
  }
  return s.top();
}

int main(){
	string exp;
	char ans;
	int ch;
	do{
	   cout<<"\nMenu\n1.Input\n2.prefix to postfix\n3.prefix to infix\n4.exit\n";
	   cin>>ch;
	   switch(ch){
		case 1:
		{
		 cout<<"\nEnter the expression:";
		 cin>>exp;
		 
        }
		break;
		case 2:
		{
		 string result=PrefixToPostfix(exp);
		 cout<<"\nThe prefix expression: "<<exp;
	     cout<<"\nThe postfix expression: "<<result;
		 
		}
		break;
		case 3:
		{
		  string result=PrefixToInfix(exp);	
		  cout<<"\nThe prefix expression: "<<exp;
	      cout<<"\nThe infix expression: "<<result;
		}
		break;
		case 4:
		{
		 return 0;
				
		}
		}
		cout<<"\ndo you want to continue ";
  		cin>>ans;
		}while(ans=='y'||ans=='Y');
}
