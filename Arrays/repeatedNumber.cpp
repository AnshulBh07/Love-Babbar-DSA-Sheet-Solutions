#include<iostream>
#include<algorithm>
using namespace std;

int getRepeated(int *arr,int n){
    sort(arr,arr+n);
    int ans;
    for(int i=1;i<=n;i++){
        if(arr[i]==arr[i-1])
        ans=arr[i];
    }
    return ans;
}

int main()
{
    int arr[]={3,9,12,16,20,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getRepeated(arr,n);
    return 0;
}