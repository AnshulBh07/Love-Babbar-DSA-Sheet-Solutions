#include<iostream>
#include<vector>
using namespace std;

bool subArrayExists(vector<int> arr){
    int currSum=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0)
        return true;
    }
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            currSum+=arr[j];
            if(currSum==0){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr{4,2,0,1,9};
    cout<<subArrayExists(arr);
    return 0;
}