#include<iostream>
#include<vector>
using namespace std;

vector<int> productArray(vector<int>&nums){
    int n = nums.size();

    //productArray[i] = (product of nums)/(nums[i])
    //if the array has one 0 then all other elements except the nums[i] will be 0
    //if the array has two 0 then all elements will be 0 of product array
    int count0=0;
    int totalProd1 = 1,totalProd2=1;

    for(int i=0;i<n;i++){
        if(nums[i]==0)
        count0++;

        totalProd1*=nums[i];
    }

    if(count0==0){
        for(int i=0;i<n;i++)
            nums[i] = totalProd1/nums[i];
    }
    else if(count0==1){
        //find total product of array
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            totalProd2*=nums[i];
        }

        //modify the array
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            nums[i] = totalProd2;

            else
            nums[i]=0;
        }
    }
    else{
        for(int i=0;i<n;i++)
        nums[i]=0;
    }
    return nums;
}

int main()
{
    vector<int> nums{-1,1,0,-3,3};
    vector<int> ans = productArray(nums);

    for(auto x:ans)
    cout<<x<<" ";

    return 0;
}