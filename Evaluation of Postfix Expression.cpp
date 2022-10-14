// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function that returns value of a given postfix expression
int evaluatePostfix(string &str)
{
    // Your code here
    int res=0;
    stack<int> s;
    for(int i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            s.push(str[i]-'0');
        }
        else
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            if(str[i]=='^')
                s.push(op1^op2);
            else if(str[i]=='*')
                s.push(op1*op2);
            else if(str[i]=='/')
                s.push(op1/op2);
            else if(str[i]=='+')
                s.push(op1+op2);
            else if(str[i]=='-')
                s.push(op1-op2);
        }
    }
    res=s.top();
    return res;
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
    
    cout<<evaluatePostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
