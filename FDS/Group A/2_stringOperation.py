class Sample:
    def Longest_str(self):
        str = input("Enter the string : ")
        split_str   = str.split()
        m = 0
        w =0
        for i in range(len(split_str)):
            if m < (len(split_str[i])):
                m = len(split_str[i])
                w = split_str[i]
        print("Longest word is : ", w, " and length is ", m)

    def freq_char(self):
        str = input("ENter the string : ")
        str_ch = input("ENter the char : ")
        a =0
        for i in range(len(str)):
            if str_ch == str[i]:
                a =a+1
        print("No of occurance is ", a)

    def is_palindrome(self):
        str = input("Enter the string to check wheather it is palindrome or not : ")
        temp = str
        if temp == str[::-1]:
            print ("YES, its palindrome !!")
        else:
            print("NO, its not palindrome !!")
    
    def first_occ(self):
        one = input("Enter the string : ")
        two = input("Enter the string  to be check : ")
        x = 0
        y =0
        flag = 0
        for i in range(len(one)):
            if two[y] == one[i]:
                flag = 1
                y = y+1
                if y == len(two):
                    x = i-(len(two) -1)
                    break
            else:
                flag = 0
                y =0
        print(x)
    
    def total_occ_char(self):
        str = input("Enter the string : ")
        count = dict()
        for word in str:
            if word not in count:
                count[word] = 1
            else:
                count[word] += 1
        
        print(count)

    def total_occ_word(self):
        str = input("Enter the string : ")
        count = dict()
        lst = str.split()
        for word in lst:
            if word not in count:
                count[word] = 1
            else:
                count[word] += 1
        
        print(count)
a = Sample()
a.total_occ_word()