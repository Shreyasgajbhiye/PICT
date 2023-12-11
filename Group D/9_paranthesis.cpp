#include<iostream>
using namespace std;
class Stackk{
    public:
    int top;
    char stack[20];
    Stackk(){
        top = -1;
    }

    void check(){
        char expr[20],ch;
        cout << "Enter the expression : \n";
        cin >> expr;
        int flag =0;
        for(int i=0; expr[i] != '\0'; i++){
            if (expr[i] == '{' || expr[i] == '[' ||expr[i] == '(' ){
                top++;
                stack[top] = expr[i];
            }
            else if(expr[i] == '}' || expr[i] == ']' ||expr[i] == ')'){
                ch = stack[top];
                top--;
                switch (expr[i])
                {
                case ')' : {
                        if (ch == '{' || ch =='['){
                        flag = 1;
                    }
                    break;
                }
                case ']' : {
                        if (ch == '{' || ch =='('){
                        flag = 1;
                    }
                    break;
                }
                case '}' : {
                        if (ch == '[' || ch =='('){
                        flag = 1;
                    }
                    break;
                }
                                
                default:
                    break;
                }
            }
            if (flag ==1){
                break;
            }

        }
        if(top != -1){
            flag = 1;
        }

        if(flag == 0){
            cout << "WELL";

        }
        else{
            cout << "NOOOO";
        }
    }
};

int main()
{
    Stackk a;
    a.check();
    return 0;
}