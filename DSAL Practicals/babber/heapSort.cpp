#include<iostream>
using namespace std;
class Heap{
    int arr[100];
    int size;
    public:
    Heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size;i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void deletefromHeap(){
        if(size == 0){
            cout << "Nothing to delete \n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(1<size){
            int left = i*2;
            int right = i*2+1;

            if(left<size && arr[left] > arr[i]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else  if(right<size && arr[right] > arr[i]){
                swap(arr[i], arr[right]);
                i = right;
            }
            else{
                return;
            }
        }
    }

    void heapify( int arr[], int n , int i){
        int largest = i;
        int left = 2*1;
        int right = i*2+1;

        if(left<= n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right<= n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n){
        int size = n;
        while(size > 1){
            swap(arr[size], arr[1]);
            size--;


            heapify(arr,size,1);
        }

    }
};
int main()
{
    Heap a;
    a.insert(50);
    a.insert(55);
    a.insert(53);
    a.insert(52);
    a.insert(54);
    a.print();
    a.deletefromHeap();
    a.print();
    int arr[6] = {-1, 54, 53 , 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0;i--){
        a.heapify(arr, 6, 1);
    }
    cout << "Printing heap" << endl;
    for(int i = 1; i<=n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    a.heapSort(arr, n);

    cout << "Sorted arr : " << endl;
    for(int i = 1; i<=n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}