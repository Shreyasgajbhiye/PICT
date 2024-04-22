#include<iostream>
using namespace std;
void bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<  " " ;
    }
    cout << endl;
}

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[i] ){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<  " " ;
    }
    cout << endl;
}

void insertion(int arr[],int n){
    for(int i =1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
     for(int i=0;i<n;i++){
        cout << arr[i] <<  " " ;
    }
    cout << endl;
}
int main()
{
    int arr[]  = {2,1,3,4,9};
    insertion(arr,5);
    return 0;
}