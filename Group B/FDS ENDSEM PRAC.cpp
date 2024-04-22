#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {10,20,66,9,8};
    int n;
    cout << "ENter the element \n";
    for(int i=0;i<5;i++){
        if(arr[i] == n){
            cout << "found at " << i << endl;
            break;
        }
        else{
            cout << "Not found \n";
        }
    }
    return 0;
}