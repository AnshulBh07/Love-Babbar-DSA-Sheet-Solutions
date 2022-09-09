#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void moreThanNbyK(vector<int>&arr,int n,int k){
    int x = n/k;
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(auto i:freq){
        if(i.second>x){
            cout<<i.first<<" ";
        }
    }
}

int main()
{
    vector<int> arr{3,1,2,2,1,2,3,3};
    int k=4;
    int n = arr.size();
    moreThanNbyK(arr,n,k);
    return 0;
}