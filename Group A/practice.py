# def bubble():
#     arr=[30,10,20,80,3]
#     n = len(arr)
#     for i in range(n):
#         for j in range(n-i-1):
#             if (arr[j] > arr[j+1]):
#                 arr[j],arr[j+1] = arr[j+1],arr[j]
#     print(arr)

# def selection():
#     arr=[30,10,20,80,3]
#     n = len(arr)
#     for i in range(n-1):
#         min = i
#         for j in range(i+1,n):
#             if (arr[j] < arr[min]):
#                 min = j
#                 arr[i],arr[min] = arr[min],arr[i]
#     print(arr)

# def insertion():
#     arr=[30,10,20,80,3]
#     n = len(arr)
#     for i in range(1,n):
#         key = arr[i]
#         j = i-1
#         while j>= 0 and key< arr[j] :
#             arr[j+1] = arr[j]
#             j -=1
#         arr[j+1] = key
#     print(arr)

# def shell():
#     arr=[30,10,20,80,3]
#     n = len(arr)
#     gap = n//2
#     while gap > 0:
#         for i in range(gap,n):
#             current_ele = arr[i]
#             pos = i 
#             while pos>= gap and current_ele < arr[pos-gap]:
#                 arr[pos] = arr[pos-gap]
#                 pos = pos-gap
#             arr[pos] = current_ele
#         gap = gap//2
#     print(arr)

def partition(arr,low,high):
    pivot = arr[low]
    i  = low+1
    j = high
    
    while(True):
        while i<=j and arr[i] <= pivot:
            i+=1
        while i<=j and arr[j] >= pivot:
            j-=1
        if i<=j:
            arr[i],arr[j] = arr[j],arr[i]
        else:
            break
    arr[low],arr[j] = arr[j],arr[low]
    return j



def quick(arr,low,high):
    if low<high:
        part = partition(arr,low,high)
        quick(arr,part+1,high)
        quick(arr,low,part-1)
arr=[30,10,20,80,3]
n = len(arr)
quick(arr,0,n-1)
print(arr)