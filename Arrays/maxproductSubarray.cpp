#include<iostream>
using namespace std;

int maxProduct(int *arr,int n){
    int currprod=1,maxprod=INT16_MIN;

   for(int i=0;i<n;i++){
    currprod*=arr[i];
    maxprod=max(currprod,maxprod);
    if(currprod==0){
        currprod=1;
    }
   }

   currprod=1;
   for(int i=n-1;i>0;i--){
    currprod*=arr[i];
    maxprod=max(currprod,maxprod);
    if(currprod==0){
        currprod=1;
    }
   }
    return maxprod;
}

int main()
{
    int arr[]={2,3,4,5,-1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProduct(arr,n);
    return 0;
}