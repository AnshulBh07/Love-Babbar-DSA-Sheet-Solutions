#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<char,int> findDuplicates(string str){
    unordered_map<char,int> count;
    for(int i=0;i<str.size();i++){
        count[str[i]]++;
    }
    return count;
}

int main()
{
    string str = "Invincible";
    unordered_map<char,int> ans = findDuplicates(str);
    for(auto it:ans){
        if(it.second>1){
            cout<<it.first<<" with number of counts : "<<it.second<<endl;
        }
    }
    return 0;
}