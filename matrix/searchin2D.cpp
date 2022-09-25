#include<iostream>
#include<vector>
using namespace std;

//O(m*logn)
int binarySearch(vector<int>&helper,int key){
    int s = 0,e = helper.size()-1;

    int mid;
    while(s<=e){
        mid = s + (e-s)/2;

        if(helper[mid]==key)
        return mid;

        if(key>helper[mid])
        s = mid+1;

        else
        e = mid-1;
    }
    return -1;
}

bool searchMatrix(vector<vector<int>> &nums,int target){
    int m = nums.size(), n = nums[0].size();

    bool flag=0;
    int foundAtIndex;
    for(int i=0;i<m;i++){
        foundAtIndex = binarySearch(nums[i],target);
        if(foundAtIndex!=-1)
        flag =1;
    }
    if(flag==1)
    return true;

    return false;
}

int main()
{
    vector<vector<int>> nums{{1,3,5,7},{10,11,16,20},{20,30,34,60}};
    int target = 3;
    searchMatrix(nums,target);
    return 0;
}