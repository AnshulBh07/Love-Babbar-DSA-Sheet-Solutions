#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//Time Complexity : O(nmlogm) where n  is the number of strings, m is the size of each string when sorted
//Space Complexity : O(n)
vector<string> printAnagramsTogether(vector<string>&s){
    //vector that stores string with index
    vector<pair<string,int>> helper;

    for(int i=0;i<s.size();i++){
        helper.push_back(make_pair(s[i],i));
    }

    //sorting each string in vector lexicographically
    for(int i=0;i<s.size();i++){
        sort(helper[i].first.begin(),helper[i].first.end());
    }

    //sorting the whole vector to get similar strings together
    sort(helper.begin(),helper.end());

    for(int i=0;i<helper.size();i++){
        cout<<helper[i].first<<" ";
    }
    cout<<endl;

    for(int i=0;i<helper.size();i++){
        cout<<s[helper[i].second]<<" ";
    }
}

//better time complexity using hashmaps i.e O(n+m)
vector<vector<string>> anagramsTogetherHashing(vector<string> s){
    //create a hash table with string array elemts as keys and a vector<string> as value
    //we will use chaining 
    unordered_map<string,vector<string>> mp;

    for(int i=0;i<s.size();i++){
        //sort each word in the string vector
        string t = s[i];
        sort(t.begin(),t.end());

        mp[t].push_back(s[i]);
    }
    vector<vector<string>> ans;
    for(auto x:mp){
        ans.push_back(x.second);
    }

    return ans;
}

int main()
{
    vector<string> s{"act","god","tac","dog","cat"};
    for(auto x:s)
    cout<<x<<" ";

    cout<<endl;
    printAnagramsTogether(s);

    vector<vector<string>> ans = anagramsTogetherHashing(s);
    for(vector<string> v:ans){
        for(string x:v){
            cout<<x<<" ";
        }
    }
    return 0;
}