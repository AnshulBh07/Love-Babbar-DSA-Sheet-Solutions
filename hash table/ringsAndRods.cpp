#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int ringsAndRods(string rings){
    map<int,set<char>> mp;

    for(int i=0;i<rings.length();i+=2){
        mp[rings[i+1]-'0'].insert(rings[i]);
    }

    int count=0;
    for(auto x:mp){
        if(x.second.size()==3)
        count++;
    }
    return count;
}

int main()
{
    string rings = "B0B6G0R6R0R6G9";
    cout<<ringsAndRods(rings);
    return 0;
}