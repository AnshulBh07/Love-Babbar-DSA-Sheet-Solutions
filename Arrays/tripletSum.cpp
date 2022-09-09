//using binary search technique
#include<iostream>
#include<algorithm>
using namespace std;

bool find3numbers(int *arr, int n,int k){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int low = i+1,high=n-1,target = k-arr[i];
        while(low<high){
            if(arr[low]+arr[high]==target){
                return true;
            }
            else if(arr[low]+arr[high]>target)
            high--;
            else
            low++;
        }
    }
    return false;
}

int main()
{
    int arr[]={1,2,4,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=13;
    cout<<find3numbers(arr,n,k);
    return 0;
}