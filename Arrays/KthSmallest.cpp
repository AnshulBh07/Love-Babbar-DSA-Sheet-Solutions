#include<iostream>
#include<algorithm>
using namespace std;

int KthSmallest(int *arr,int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}

int main()
{
    int arr[]={7,10,4,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<k<<"th smallest element is : "<<KthSmallest(arr,n,k)<<endl;
    return 0;
}