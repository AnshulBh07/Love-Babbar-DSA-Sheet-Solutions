#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>&intervals,int m,int n){
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(auto i:intervals){
        if(i[0]>ans.back()[1]){
            ans.push_back(i);
        }
        else{
            ans.back()[1]=max(ans.back()[1],i[1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    int m = intervals.size();
    int n = intervals[0].size();
    vector<vector<int>> ans = mergeIntervals(intervals,m,n);
    for(auto x:ans){
        for(auto print:x){
            cout<<print<<" ";
        }
        cout<<endl;
    }
    return 0;
}