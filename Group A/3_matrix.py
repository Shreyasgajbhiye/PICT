class Mat:
    l1=[]
    l2=[]
    l3=[[0,0],[0,0]]

    

    def ip1(self):
        row = int(input("Enter the number of rows : "))
        col = int(input("Enter the no. of column : "))
        for i in range(row):
            temp=[]
            for j in range(col):
                a = int(input("ENtre the value of lst1[{i}][{j}] : "))
                temp.append(a)
            self.l1.append(temp)
    def ip2(self):
        row = int(input("Enter the number of rows : "))
        col = int(input("Enter the no. of column : "))
        for i in range(row):
            temp=[]
            for j in range(col):
                a = int(input("ENtre the value of lst1[{i}][{j}] : "))
                temp.append(a)
            self.l2.append(temp)

    def display(self):
        print(self.l1)
        print(self.l2)

    def addition(self):
        for i in range(2):
            for j in range(2):
                self.l3[i][j] = self.l1[i][j] + self.l2[i][j]

    def mul(self):
        for i in range(2):
            for j in range(2):
                for k in  range(2):
                    self.l3[i][j] += self.l1[i][k] * self.l2[k][k]
    def res(self):
        print(self.l3)


a = Mat()
a.ip1()
a.ip2()
# a.display()
a.addition()
a.res()