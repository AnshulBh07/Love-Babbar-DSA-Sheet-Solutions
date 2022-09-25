#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortMatrix(vector<vector<int>>&nums){
    vector<int> helper;
    int m=nums.size(),n=nums[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            helper.push_back(nums[i][j]);
        }
    }
    sort(helper.begin(),helper.end());
    int j=0;
    vector<int> temp;
    for(int i=0;i<m;i++){

        while(n--){
            temp.push_back(helper[j]);
            j++;
        }
        j+=n;
        nums[i] = temp;
        temp.clear();
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> nums{{10,20,30,40},{15,25,35,35},{27,29,37,48},{32,33,39,50}};
    sortMatrix(nums);
    return 0;
}