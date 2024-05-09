#include<iostream>
using namespace std;
#define size 10
class Node
{
    public:
    string name;
    long phoneno;
    Node()
    {
        name="";
        phoneno=0;
    }
};
class Hashing
{
    public:
    Node HT[size];
    
    int hash(long num)
    {
        return num%size;
    }
    
    void insertWithoutReplacement(string n,long num)
    {
        int index=hash(num);
        if(HT[index].phoneno==0)
        {
            HT[index].name=n;
            HT[index].phoneno=num;
            return;
        }
        index=probe(num);
        if(index!=-1)
        {
            HT[index].name=n;
            HT[index].phoneno=num;
        }
        else
        {
            cout<<"\nHash Table is full";
        }   
    }
    int search(long num)
    {
        int index=hash(num);
        if(HT[index].phoneno==num)
            return index;
        int i=1;
        while(true)
        {
            index=(index+i)%size;
            if(HT[index].phoneno==num)
                return index;
            else if(HT[index].phoneno==(long)0)
                return -1;
            i++;
        }
    }
    void display()
    {
        cout<<"\nIndex \tName \tPhoneNum"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<"\n"<<i<<" : "<<HT[i].name<<"   "<<HT[i].phoneno;
        }
    }
    int probe(long phone)
    {
        int index=hash(phone);
        int original=index;
        while(true)
        {
            index=(index+1)%size;
            // if(phone==66746268)
            // {
            //     cout<<index<<endl;
            // }
            if(HT[index].phoneno==0)
                return index;
            if(index==original)
                return -1;
        }   
    }
    void insertWithReplacement(string n,long num)
    {
        int index=hash(num);
        if(HT[index].phoneno==0)
        {
            HT[index].name=n;
            HT[index].phoneno=num;
            return;
        }
        else
        {
            int index2=hash(HT[index].phoneno);
            // cout<<"\nIndex2:"<<index2;
            if(index==index2)
            {
                index=probe(num);
                if(index!=-1){
                    HT[index].name=n;
                    HT[index].phoneno=num;
                }
                else
                {
                    cout<<"\nHash Table is full";
                }
                return;
            }
            else
            {
                Node temp=HT[index];
                HT[index].name=n;
                HT[index].phoneno=num;
                index2=probe(temp.phoneno);
                if(index2!=-1){
                    HT[index2].name=temp.name;
                    HT[index2].phoneno=temp.phoneno;
                }
                else
                {
                    cout<<"\nHash Table is full";
                }
                return;
            }
        }
    }
    void Delete(long num)
    {
        int sample=0;
        int index=search(num);
        cout<<"\nIndex:"<<index;
        if(index==-1)
        {
            cout<<"\nRecord not found!!!";
            return;
        }
        HT[index].phoneno=0;
        HT[index].name="";
        int i=(index+1)%size;
        int hash2=hash(HT[i].phoneno);
        while(HT[i].phoneno!=0)
        {
            if(hash2==i)
                return;
            // cout<<"\ni:"<<i<<"   Hash:"<<hash2<<endl;
            sample=(i+9)%size;
            HT[sample].name=HT[i].name;
            HT[i].name="";
            HT[sample].phoneno=HT[i].phoneno;
            HT[i].phoneno=0;
            i=(i+1)%size;
            hash2=hash(HT[i].phoneno);
        }  
    }
};

int main()
{
    Hashing obj;
    int x;
    string B[]= {"Abhi",  "ABC",   "Sample", "Ganesh", "Pankaj", "Viraj",  "Shreyas", "PQR",    "Gopal"};
    int A[] = {14895496, 13238342, 25454435, 34439239, 12345676, 14321822, 547855625, 66746268, 76857335};
    for(int i=0;i<size-1;i++)
    {
                
        obj.insertWithReplacement(B[i],A[i]);
    }
    obj.display();
    cout << endl;
    x = obj.search(1);
    return 0;
}