#include<iostream>
#include<set>
#include<map>
using namespace std;

string Decode(string key, string message){
    map<char,char> mp;

    for(int i=0;i<key.size();i++){
        mp[key[i]] = key[i];
    }

    for(auto x:mp){
        cout<<x.second<<" ";
    }
}

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    Decode(key,message);
    return 0;
}