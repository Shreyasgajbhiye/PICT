#include<iostream>
using namespace std;

// Function prototype
int partition(int arr[], int x, int y);

void quick(int arr[], int x, int y) {
    if (x < y) {
        int par = partition(arr, x, y);
        quick(arr, x, par - 1);
        quick(arr, par + 1, y);
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int x, int y) {
    int p = arr[x];
    int i = x + 1;
    int j = y;
    while (true) {
        while (i <= j && arr[i] <= p) {
            i++;
        }
        while (i <= j && arr[j] >= p) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            break;
        }
    }

    int temp = arr[x];
    arr[x] = arr[j];
    arr[j] = temp;

    return j;
}


void  shell(int arr[],int n){
    int gap = n /2;
    while(gap > 0){
        for(int i=gap;i<n;i++){
            int current = arr[i];
            int pos = i;
            while(pos>=gap && current < arr[pos-gap]){
                arr[pos] = arr[pos-gap];
                 pos = pos-gap;
            }
            arr[pos] = current;
        }
        gap  = gap/2;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
int main() {
    int arr[] = {9, 2, 3, 1, 3};
    int size = 5;
    shell(arr, 5);
    return 0;
}
