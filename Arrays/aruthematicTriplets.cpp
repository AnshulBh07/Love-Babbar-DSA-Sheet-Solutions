#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findTriplets(vector<int>&nums,int diff){
    unordered_map<int,bool> mp;

    for(int i=0;i<nums.size();i++){
        mp[nums[i]] = true;
    }

    int count=0;
    for(int i=0;i<nums.size();i++){
        if(mp[nums[i]+diff] && mp[nums[i]-diff])
        count++;
    }
    return count;
}

int main()
{
    vector<int> nums{0,1,4,6,7,10};
    cout<<findTriplets(nums,3);
    return 0;
}