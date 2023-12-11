class student:
    n = int(input("Enter the number of students : "))
    arr=[]
    def inp(self):
        for i in range(self.n):
            x = int(input("Enter the roll no. : "))
            self.arr.append(x)
    
    
    def linear_search(self): #o(n)                                                                    # O(N)
        cnt =0
        print("leng ", len(self.arr))
        i=0
        ser = int(input("Element to search. : "))
        while(i < len(self.arr)):
            if self.arr[i]  == ser:
                print("found  at ",i+1)
                print("COmparision : " ,i)
                break
            else:
                i+=1
    
    def sentinal_search(self):
        key = int(input("Enter the key : "))                                                    # o(N) with less comparision
        size = len(self.arr)
        last = self.arr[size-1]
        self.arr[size-1] = key
        i=0
        while self.arr[i] != key:
            i+=1
        
        if (i < size-1 or key == last):
            print ("Found at ", i+1)
            print("Comparision : ", i+1)


    def binary_search(self):
        arr1 = [10,20,30,40,50]

        size = len(arr1)
        low =0
        high = size-1
        key = int(input("enter the key"))
        while(low<=high):
            mid = int((low+high)/2)                                             #  o(log n)

            if (arr1[mid] == key):
                print("Found at ", mid)
                break
            elif(key < arr1[mid]):
                high = mid-1
            elif (key > arr1[mid]):
                low = mid +1
        if low>high:
            print("Not found")

   


a = student()
# a.inp()

arrr = [10,20,30,40,50]
x = 20
a.binary_search()