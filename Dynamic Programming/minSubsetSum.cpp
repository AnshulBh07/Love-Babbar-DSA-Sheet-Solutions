#include<iostream>
#include<vector>
using namespace std;

int minSubsetSumDiff(int *nums){
    int n = sizeof(nums)/sizeof(nums[0]);
    int range=0; //range is sum of array
    for(int i=0;i<n;i++){
        range+=nums[i];
    }
    bool t[n+1][range+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<range+1;j++){
            if(i==0)
            t[i][j] = false;
            if(j==0)
            t[i][j] = true;
        }
    }

    //choice diagram
    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){
            if(nums[i-1]<=j)
            t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
            
            else
            t[i][j] = t[i-1][j];
        }
    }

    vector<int> candidates;
    for(int i=0;i<range/2+1;i++){
        if(t[n][i]==true){
            candidates.push_back(i); // i is range here
        }
    }

    //check for candidate with minimum difference
    int mn = INT16_MAX;
    for(int i=0;i<candidates.size();i++){
        mn = min(mn,range-2*candidates[i]);
    }
    return mn;
}

int main()
{
    int nums[]={3,9,7,3};
    cout<<minSubsetSumDiff(nums);
    return 0;
}