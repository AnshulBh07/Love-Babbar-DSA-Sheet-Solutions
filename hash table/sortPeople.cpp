#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<string> sortPeople(vector<string>&names,vector<int>&heights){
    map<int,string> mp;
    int n = heights.size();

    for(int i=0;i<n;i++){
        mp[heights[i]] = names[i];
    }

    vector<string> ans;

    for(auto x:mp)
    ans.push_back(x.second);

    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{
    vector<string> names{"Mary","John","Emma"};
    vector<int> heights{180,165,170};

    vector<string> ans = sortPeople(names,heights);
    for(string s:ans)
    cout<<s<<" ";
    return 0;
}