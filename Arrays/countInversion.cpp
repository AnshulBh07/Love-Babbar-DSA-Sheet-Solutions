#include<iostream>
using namespace std;

bool isSorted(int *arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}

int countInversion(int *arr,int n){
    int count = 0;
    if(isSorted(arr,n)){
        return count;
    }
    else{
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j] && i<j)
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[]={4,7,1,2,4,6,9,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countInversion(arr,n);
    return 0;
}