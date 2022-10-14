#include<iostream>
using namespace std;

int countSubsetWithDiff(int *arr,int n,int targetSum){
    int t[n+1][targetSum+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<targetSum+1;j++){
            if(i==0)
            t[i][j] = 0;
            if(j==0)
            t[i][j] = 1;
        }
    }

    //choice diagram
    for(int i=1;i<n+1;i++){
        for(int j=1;j<targetSum+1;j++){
            if(arr[i-1]<=j)
            t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];

            else
            t[i][j] = t[i-1][j];
        }
    }
    return t[n][targetSum];
}

int main()
{
    int arr[] = {8,4,6,2,1,10,20,5};
    int diff = 2,sum=0; 
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int targetSum = (diff+sum)/2;
    cout<<countSubsetWithDiff(arr,n,targetSum);
    return 0;
}