n = len(arr)
# def bubble():
#     for i in range(n):
#         for j in range(n-i-1):
#             if arr[j] > arr[j+1]:
#                 arr[j],arr[j+1] =arr[j+1],arr[j]
#     print(arr)

# def selection():
#     for i in range(n-1):
#         min  = i 
#         for j in range(i+1,n):
#             if (arr[j] < arr[min]):
#                 min = j
#                 arr[i],arr[min] = arr[min], arr[i]
#     print(arr)

# def insertionSort():
#     for i in range(1,n):
#         key = arr[i]
#         j = i-1
#         while j>=0 and arr[j] > key:
#             arr[j+1] = arr[j]
#             j -=1
#         arr[j+1] = key 
#     print(arr)

# def shellSort():
#     n = len(arr)
#     gap = n//2
#     while gap >0:
#         for i in range(gap,n):
#             current_ele = arr[i]
#             pos = i
#             while pos >= gap and current_ele < arr[pos-gap]:
#                 arr[pos] = arr[pos-gap]
#                 pos = pos-gap
#             arr[pos] = current_ele
#         gap = gap//2
#     print(arr)

