#include<iostream>
#include<C:\Users\User\OneDrive\Desktop\DSL MOCK\practice\stackk.cpp>
using namespace std;
int prec(char c){
    if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infix(string s){
    string res;
    stackADT stk;
    for(int i=0;i<s.length();i++){
        if((s[i] >= 'a' && s[i]<='z') || (s[i] >= 'A' && s[i]<='Z')){
            res+= s[i];
        }
        else if(s[i] == '('){
            stk.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!stk.isEmpty() && stk.peek() != '('){
                res += stk.pop();
            }
            if(!stk.isEmpty()){
                stk.pop();
            }
        }
        else{
            if(!stk.isEmpty() and prec(stk.peek()) > prec(s[i])){
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
    cout << infix("(a-b/c)*(a/k-l)") << endl;
}