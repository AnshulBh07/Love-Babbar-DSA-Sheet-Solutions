#include<iostream>
using namespace std;

int maxSum(int *arr,int n){
    int maxSumarray=INT16_MIN,currSum=0;

    for(int i=0;i<n;i++){
        currSum+=arr[i];

        if(currSum>maxSumarray)
        maxSumarray=currSum;
    }
    return maxSumarray;
}

int main()
{
    int arr[]={-1,-2,-3,-4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum of sub array is : "<<maxSum(arr,n)<<endl;
    return 0;
}