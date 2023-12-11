def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

    print(arr)

def selectionSort(arr):  
    n = len(arr)
    for i in range(n-1): # 90 30 40 50 10   it will run until 50 (n-1)  = 4  and range (0,4) means 3 // arr[3] = 50 
        mini = i
        for j in range(i+1,n):
            if arr[j] < arr[mini]:
                mini = j
                arr[i],arr[mini] = arr[mini], arr[i] 
    print(arr)

def insertionSort(arr):
    n = len(arr)
    for i in range(1,n):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    print(arr)

def shellSort(arr):
    n = len(arr)
    gap = n//2                                      # // means truncate
    while gap > 0:
        for i in range(gap, n):
            current_ele = arr[i] 
            pos = i
            while pos>=gap and current_ele < arr[pos-gap]:
                arr[pos]  = arr[pos-gap]
                pos = pos-gap

            arr[pos] = current_ele
        gap = gap//2
    print (arr)


arr=[10,40,30,20,90,3,0]
shellSort(arr)