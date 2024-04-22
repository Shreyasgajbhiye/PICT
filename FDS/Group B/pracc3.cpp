#include<iostream>
using namespace std;
int ind(int arr[],int s,int num){
    int size  = 12;
    int numarr[size], indarr[size], i,ind=0;
    int found=0,maybe=0,start,end;
     for(i=0;i<s;i+=3){
        numarr[ind] = arr[i];
        indarr[ind] = i;
        ind++;
     }
     if(num< numarr[0]){
        return found;
     }
     for(i=0;i<ind;i++){
        if(num <= numarr[i]){
            start = indarr[i-1];
            end = indarr[i];
            maybe = 1;
            break;
        }
     }

     if(maybe==0){
        start = i;
        end = s;
     }
     for(i=start;i<= end;i++){
        if(arr[i] == num){
            found = 1;
        }
     }
     return found;
}
int main()
{
    int arr[] = {10, 22, 30, 44, 56, 58, 60, 70, 100, 110, 130};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x1 = 130;
    int a = ind(arr,size,x1);
    if(a==1){
        cout << "FOUND";
    }
    else{
        cout << "NOT FOUND";
    }
    return 0;
}