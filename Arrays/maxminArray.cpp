#include<iostream>
using namespace std;

struct Pair{
    int max;
    int min;
};

Pair findMaxMin(int *arr,int n){
    struct Pair minmax;
    minmax.max=INT16_MIN;
    minmax.min=INT16_MAX;
    if(n==0){
        minmax.max=0;
        minmax.min=0;
    }

    if(n==1){
        minmax.max=arr[0];
        minmax.min=arr[0];
    }

    for(int i=0;i<n;i++){
        if(arr[i]>minmax.max){
            minmax.max=arr[i];
        }
        if(arr[i]<minmax.min){
            minmax.min=arr[i];
        }
    }
    return minmax;
}

int main()
{
    int arr[]={856,825,7,8,10,2316,342,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Pair minmax = findMaxMin(arr,n);
    cout<<"Maximum element is : "<<minmax.max<<endl;
    cout<<"Minimum element is : "<<minmax.min<<endl;
    return 0;
}