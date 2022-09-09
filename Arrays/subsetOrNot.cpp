#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string isSubset(vector<int>&a,vector<int>&b){
    unordered_map<int,int> helper;
    for(int i=0;i<a.size();i++){
        helper[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        helper[b[i]]--;
    }
    for(auto x:helper){
        if(x.second<0)
        return "No";
    }
    return "Yes";
}

int main()
{
    vector<int> a{11,1,13,21,3,7};
    vector<int> b{11,3,7,1};
    string ans = isSubset(a,b);
    cout<<ans;
    return 0;
}