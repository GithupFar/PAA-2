#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;

int m[1000];
int n=4;

int minTime(int arr[],int i,int isSkip){
    int q,r,s;
    if(i>=n) return 0;
    //if(m[i]!=-1) return m[i];
    if(isSkip==0){
       return m[i]=arr[i] + min(minTime(arr,i+1,1), minTime(arr,i+1,0));
    }
    else{
        return m[i]=minTime(arr,i+1,0);
    }

    return m[i];
}

int main(){
    int arr[8]={10,5,7,10};
    cout<<"result: "<<
    min(minTime(arr,0,0), minTime(arr,0,1));

    cout<<'\n';
    return 0;
}
