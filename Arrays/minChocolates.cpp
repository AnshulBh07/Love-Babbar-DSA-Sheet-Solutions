#include<iostream>
#include<algorithm>
using namespace std;

long long findMinDiff(int *arr,int n,int m){
    sort(arr,arr+n);
    long long minDiff=INT16_MAX,diff;
    for(int i=0;i<=n-m;i++){
        diff = arr[i+m-1]-arr[i];
        minDiff = min(minDiff,diff);
    }
    return minDiff;
}

int main()
{
    int arr[]={7,3,2,4,9,12,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 5;
    cout<<findMinDiff(arr,n,m);
    return 0;
}