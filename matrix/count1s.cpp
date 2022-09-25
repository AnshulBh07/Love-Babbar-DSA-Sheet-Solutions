#include<iostream>
#include<vector>
using namespace std;

int countOne(vector<int>&helper){
    int count =0;
    for(int i=0;i<helper.size();i++){
        if(helper[i]==1)
        count++;
    }
    return count;
}

int findRowMax1(vector<vector<int>>&nums){
    int m = nums.size(),n = nums[0].size();

    int resRow;
    int currCount,maxCount=INT16_MIN;;
    for(int i=0;i<m;i++){
        currCount = countOne(nums[i]);
        if(currCount>maxCount){
            maxCount=currCount;
            resRow=i;
        }
    }
    return resRow;
}

int main()
{
    vector<vector<int>> nums{{0,1,1,1},{0,0,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};
    cout<<findRowMax1(nums);
    return 0;
}