#include<iostream>
#include<vector>
using namespace std;
/*
Recursive approach
bool subsetSum(vector<int>&arr,int sum,int n){
    //base case
    if(sum == 0 && n == 0) return true;
    if(sum==0)
    return true;
    if(n==0)
    return false;

    if(arr[n-1]<=sum)
    return subsetSum(arr,sum-arr[n-1],n-1) || subsetSum(arr,sum,n-1);

    else if(arr[n-1]>sum)
    return subsetSum(arr,sum,n-1);
}*/

bool subsetSum(vector<int>&arr,int sum,int n){
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0)
            t[i][j] = false;

            if(i==0)
            t[i][j]=true;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];

            else if(arr[i-1]>j)
            t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    vector<int> arr{2,3,7,8,10};
    int sum=12;
    int n = arr.size();

    cout<<subsetSum(arr,sum,n);
    return 0;
}