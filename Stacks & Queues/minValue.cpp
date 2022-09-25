#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int minValue(string s,int k){
    string str;
    for(int i=0;i<s.length()-k;i++){
        str[i] = s[i];
    }

    unordered_map<char,int> mp;

    char ch;
    for(int i=0;i<str.length();i++){
        ch = str[i];
        mp[ch]++;
    }

    for(auto x:mp)
    cout<<x.first<<" ";
}

int main()
{
    string s ="abccc";
    int k =1;
    minValue(s,k);
    return 0;
}