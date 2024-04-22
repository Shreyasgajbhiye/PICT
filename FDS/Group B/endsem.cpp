#include<iostream>

using namespace std;

int FibonacciGenerator(int n) {
    if (n < 1) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return FibonacciGenerator(n - 1) + FibonacciGenerator(n - 2);
    }
}

int FibonacciSearch(int arr[], int size, int x) {
    int m = 0;
    while (FibonacciGenerator(m) < size) {
        m = m + 1;
    }
    int offset = -1;
    while (FibonacciGenerator(m) > 1) {
        int i = min(offset + FibonacciGenerator(m - 2), size - 1);

        if (x > arr[i]) {
            m = m - 1;
            offset = i;
        } else if (x < arr[i]) {
            m = m - 2;
        } else {
            return i;
        }
    }

    if (FibonacciGenerator(m - 1) && arr[offset + 1] == x) {
        return offset + 1;
    } else {
        return -1;
    }
}

int main() {
    // The search array
    int arr[] = {10, 22, 30, 44, 56, 58, 60, 70, 100, 110, 130};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 44;
    
    cout << FibonacciSearch(arr, size, x) << endl;

    return 0;
}
