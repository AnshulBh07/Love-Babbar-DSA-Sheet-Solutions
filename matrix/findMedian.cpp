#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//time : O(n*n), space : O(n)
int findMedian(vector<vector<int>>&nums){
    int m = nums.size(),n = nums[0].size();

    vector<int> helper;
    vector<int> temp;
    for(int i=0;i<m;i++){
        temp = nums[i];
        for(int j=0;j<n;j++){
            helper.push_back(temp[j]);
        }
    }
    
    sort(helper.begin(),helper.end());
    int median;
    if(helper.size()%2==0){
        int x = helper.size()/2;
        median = helper[x-1];
    }
    else{
        int x = helper.size()/2 + 1;
        median = helper[x-1];
    }
    return median;
}

int main()
{
    vector<vector<int>> nums{{1,3,5},{2,6,9},{3,6,9}};
    cout<<findMedian(nums);
    return 0;
}