#include<iostream>
#include<algorithm>
using namespace std;

int brr[100];

int bu(int arr[],int n){
    int i,q,j,nincl,nexcl,incl,excl;
    if(n<=0) return 0;
    else{
        incl=arr[0];
        excl=0;
        for(i=1;i<n;i++){
            nincl=arr[i] + min(excl,incl);
            nexcl=incl;

            incl=nincl;
            excl=nexcl;
        }
        brr[excl]=min(incl,excl);
    }
    return brr[excl];
}

int main(){
    int arr[8]={10,5,2,4,8,6,7,10};
	int n=8;

	cout<<"hasil: "<<bu(arr,n)<<'\n';
	return 0;
}
