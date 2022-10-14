#include<iostream>
using namespace std;

/*
//Recursive
bool equalSumPartition(int *arr,int n,int arraySum){
    //base cases
    if(arraySum%2!=0)   return false;

    else if(arraySum%2==0){
        if(n==0 && arraySum/2 == 0) return true;

        else if(n==0)    return false;
        else if(arraySum/2==0)  return true;

        if(arr[n-1]<=arraySum/2){
            return equalSumPartition(arr,n-1,arraySum/2-arr[n-1]) || equalSumPartition(arr,n-1,arraySum/2);
        }
        else if(arr[n-1]>arraySum/2)
        return equalSumPartition(arr,n-1,arraySum/2);
    }
}*/

bool equalSumPartition(int *arr,int n,int arraySum){
    if(arraySum%2!=0)   return false;

    int t[n+1][arraySum/2+1];
    if(arraySum%2==0){

        for(int i=0;i<n+1;i++){
            for(int j=0;j<arraySum/2+1;j++){
                if(i==0)
                t[i][j] = false;
                if(j==0)
                t[i][j]=true;
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<arraySum/2+1;j++){
                if(arr[i-1]<=arraySum/2)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                t[i][j] = t[i-1][j]; 
            }
        }
        return t[n][arraySum/2];
    }
}

int main()
{
    int arr[]={1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int arraySum=0;
    for(int i=0;i<n;i++){
        arraySum+=arr[i];
    }

    cout<<equalSumPartition(arr,n,arraySum);
    return 0;
}