#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>&nums,int k){
    vector<vector<int>> ans;
    vector<int> temp;
    int sum,start,end;
    int n =nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
        start = end-1, end=n-1;
        while(start<end){
            sum = nums[i]+nums[start]+nums[end];
            if(sum<k){
                temp.push_back(nums[i]);
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);

                ans.push_back(temp);
                temp.clear();
                end--;
            }
            if(sum>=k){
                start--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{5,1,3,4,7};
    int k=12;
    vector<vector<int>> ans = threeSum(nums,k);
    for(vector<int> x:ans){
        for(int i:x)
        cout<<i<<" ";

        cout<<endl;
    }
    return 0;
}