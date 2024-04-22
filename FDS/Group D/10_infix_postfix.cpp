#include<iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include<C:\Users\User\OneDrive\Desktop\DSL MOCK\Group D\stck.cpp>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixtopostfix(string s){
    //stack<char> st;
    stackADT st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z' )||(s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.isEmpty() && st.peek()!='('){
                res+=st.pop();
               // st.pop();
            }
            if(!st.isEmpty()){
                st.pop();
            }
        }
         else{
            while(!st.isEmpty() && prec(st.peek())>prec(s[i])){
                 res+=st.pop();
                //st.pop();
            }
            st.push(s[i]);
        
        }
    }
    while(!st.isEmpty()){
        res+=st.pop();
        //st.pop();
    }
    return res;
   
}

// string infixtoprefix( string s){
//     reverse(s.begin(),s.end());
//     stack<char> st;
//     string res;
//     for(int i=0;i<s.length();i++){
//         if((s[i]>='a'&&s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
//             res+=s[i];
//         }
//         else if(s[i]=='('){
//             st.push(s[i]);
//         }
//         else if(s[i]==')'){
//             while (!st.empty()&&st.top()!='(')
//             {
//                 res+=st.top();
//                 st.pop();
//             }
//             if(!st.empty()){
//                 st.pop();
//             }
//             else{
//                 while(!st.empty()&& prec(st.top()>=prec(s[i])))
//                 {
//                     res+=st.top();
//                     st.pop();
//                 }
//                 st.push(s[i]);
//             }
            
//         }
//     }
//     while(!st.empty()){
//         res+=st.top();
//         st.pop();
//     }

//     reverse(res.begin(),res.end());
//     return res;
// }

// int postfixEvalution(string s) {
//     stack<int> st;
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] >= '0' && s[i] <= '9') {
//             st.push(s[i] - '0');
//         } else if (s[i] != ' ') {
//             int op2 = st.top();
//             st.pop();
//             int op1 = st.top();
//             st.pop();

//             switch (s[i]) {
//                 case '+':
//                     st.push(op1 + op2);
//                     break;
//                 case '-':
//                     st.push(op1 - op2);
//                     break;
//                 case '*':
//                     st.push(op1 * op2);
//                     break;
//                 case '/':
//                     st.push(op1 / op2);
//                     break;
//                 case '^':
//                     st.push(pow(op1, op2));
//                     break;
//                 default:
//                     break;
//             }
//         }
//     }
//     return st.top();
// }

int main() {

    cout << infixtopostfix("(a-b/c)*(a/k-l)") << endl;
}



// int main(){
//     //cout<<infixtopostfix("(a-b/c)*(a/k-l)")<<endl;
//    // cout<<infixtoprefix("(a-b/c)*(a/k-l)")<<endl;
//     cout<<postfixEvalution("46+2/5*7+")<<endl;
// }