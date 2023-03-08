#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int firstUniqueChar(string str){
    unordered_map<char,int> mp;

    char ch;
    for(int i=0;i<str.length();i++){
        ch = str[i];
        mp[ch]++;
    }

    for(auto it : mp){
        cout<<it.first<<" - "<<it.second<<endl;
    }

    vector<pair<char,int>> ans;
    for(int i=0;i<str.length();i++){
        ch = str[i];
        ans.push_back({ch,mp[ch]});
    }

    cout<<"{";
    for(int i=0;i<ans.size();i++){
        cout<<"{"<<ans[i].first<<","<<ans[i].second<<"},";
        if(ans[i].second==1)
        return i;
    }
    cout<<"}";
}

int main(){
    string s = "loveleetcode";
    cout<<firstUniqueChar(s);
    return 0;
}