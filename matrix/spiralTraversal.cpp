#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>>&nums){
    int m=  nums.size(),n = nums[0].size();
    int startcol = 0,startrow=0,endrow=m-1,endcol=n-1;

    vector<int> ans;
    while(startrow<endrow && startcol<endcol){

        for(int i=startcol;i<=endcol;i++){
            ans.push_back(nums[startrow][i]);
        }
        startrow++;

        for(int i=startrow;i<=endrow;i++){
            ans.push_back(nums[i][endcol]);
        }
        endcol--;

        for(int i=endcol;i>=startcol;i--){
            ans.push_back(nums[endrow][i]);
        }
        endrow--;

        for(int i=endrow;i>=startrow;i--){
            ans.push_back(nums[i][startcol]);
        }
        startcol++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> ans = spiralTraversal(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}