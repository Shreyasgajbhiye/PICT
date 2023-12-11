#include<iostream>
using namespace std;
class stk{
    public:
    char stack[20];
    int top;

    stk(){
        top = -1;
    }

    void check(){
        char expr[20];
        cout << "Enter the expression : \n";
        cin >> expr;
        int flag = 0;
        for(int i=0;expr[i] != '\0';i++){
            if(expr[i] == '(' || expr[i] == '{' || expr[i] == '['){
                top++;
                stack[top] = expr[i];
            }
            else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']'){
                char ch = stack[top];
                top--;
                switch (expr[i])
                {
                case ')':
                    if(ch == '{' || ch == '['){
                        flag = 1;
                    }
                    break;
                case ']':
                    if(ch == '{' || ch == '('){
                        flag = 1;
                    }
                    break;
                case '}':
                    if(ch == '(' || ch == '['){
                        flag = 1;
                    }
                    break;
                
                default:
                    break;
                }
            }
            if(flag == -1){
                break;
            }
        }
        if (top != -1){
            flag = 1;
        }
        if(flag == 0){
            cout << "YESSS";
        }
        else{
            cout << "NOOO";
        }
    }
};
int main()
{
    stk a;
    a.check();
    return 0;
}