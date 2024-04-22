#include<iostream>
#include<C:\Users\User\OneDrive\Desktop\DSL MOCK\Group D\stck.cpp>
using namespace std;
int pre(char x){
    if (x == '^'){
        return 3;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '+' || x == '-'){
        return 1;
    }
    else {
        return -1;
    }
}
string infix_to_postfix(string s){
    stackADT stk;
    string res;
    for(int i=0; i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            stk.push(s[i]);
        }
        else if(s[i]==')'){
            while(!stk.isEmpty() && stk.peek() != '('){
                res+= stk.pop();
            }
            if(!stk.isEmpty()){
                stk.pop();
            }
        }
        else{
            while(!stk.isEmpty() && pre(stk.peek()) > pre(s[i]) ){
                res+= stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.isEmpty()){
        res+=stk.pop();
    }
    return res;
}
int main()
{
    cout << infix_to_postfix("(a-b/c)*(a/k-l)") << endl;
}