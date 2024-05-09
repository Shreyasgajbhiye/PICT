#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2 +1;
    int right = i*2 +2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n){
    for(int i=n/2-1 ; i>=0;i--){
        heapify(arr, n,i);
    }

    for(int i=n-1; i>=0;i--){
        swap(arr[0], arr[i]);

        heapify(arr, i,0);
    }

}
int main()
{

    int arr[] = {10,30,40,20,50,90};
    int n=6;
    for(int i=n/2-1 ; i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}