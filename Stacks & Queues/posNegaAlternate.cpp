#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> rearrangePosNeg(vector<int>&arr,int n){
    stack<int> s1,s2;
    vector<int> ans;
    reverse(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]<0)
        s1.push(arr[i]);
        else
        s2.push(arr[i]);
    }
    for(int i=0;i<min(s1.size(),s2.size());i++){
        ans.push_back(s1.top());
        s1.pop();
        ans.push_back(s2.top());
        s2.top();
    }
    while(!s1.empty()){
        ans.push_back(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        ans.push_back(s1.top());
        s1.pop();
    }
    return ans;
}

int main()
{
    vector<int> arr{-5,-2,5,2,4,7,1,8,0,-8};
    int n = arr.size();
    vector<int> ans = rearrangePosNeg(arr,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}