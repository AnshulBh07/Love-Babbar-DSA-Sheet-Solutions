#include<iostream>
#include<algorithm>
using namespace std;

int getMinDiff(int *arr,int n,int k){
    sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];

    int largest=arr[n-1]-k;
    int smallest=arr[0]+k;

    for(int i=0;i<n-1;i++){
        int minimum = min(smallest,arr[i+1]-k);
        int maximum = max(largest,arr[i]+k);
        if(minimum<0)
        continue;
        ans=min(ans,maximum-minimum);
    }
    return ans;
}

int main()
{
    int arr[]={3,9,12,16,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout<<getMinDiff(arr,n,k);
    return 0;
}