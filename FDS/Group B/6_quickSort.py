def quickSort(arr,low,high):
    if low < high:
        pivot_p = partition(arr,low,high)
        quickSort(arr,low,pivot_p-1)
        quickSort(arr,pivot_p+1,high)
def partition(arr,low,high):
    p = arr[low]
    i = low+1
    j = high
    while(True):
        while i<=j and arr[i] <= p:
            i+=1
        while i<=j and arr[j] >= p:
            j-=1
        if i<=j:
            arr[i],arr[j] = arr[j], arr[i]
        else:
            break
    arr[low],arr[j] = arr[j],arr[low]
    return j

arr = [2,3,1,3,4,5,7,9,6,5,35]
quickSort(arr,0,len(arr)-1) 
print(arr)