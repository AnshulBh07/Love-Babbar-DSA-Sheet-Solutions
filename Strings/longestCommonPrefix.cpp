#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> strs){
    int n = strs.size();

    //sorts the string lexicographically
    sort(strs.begin(),strs.end());
    for(string s :strs)
    cout<<s<<" ";
    cout<<endl;

    //finding common prefix of first and last 
    int len = min(strs[0].length(),strs[n-1].length());
    string s1 = strs[0], s2 = strs[n-1];
    string ans="";
    for(int i=0;i<len;i++){
        if(s1[i]==s2[i])
        ans.push_back(s1[i]);
        else
        break;
    }
    return ans;
}

int main()
{
    vector<string> strs{"dog","racecar","car"};
    cout<<longestCommonPrefix(strs);
    return 0;
}