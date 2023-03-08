#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<string> letterCombinations(string digits){
    vector<string> ans;
    
    if(digits.length()==0)
    return ans;

    //mapping numbers from 2-9 to strings
    int ascii = 97;
    vector<string> mp;
    mp[0]="";
    mp[1]="";
    for(int i=2;i<=9;i++){
        string temp="";
        for(int i=0;i<3;i++){
            temp+=char(ascii);
            ascii++;
        }
        mp.push_back(temp);
    }

    for(string s:mp){
        cout<<s<<" ";
    }
}

int main(){
    string digits = "23";
    letterCombinations(digits);
    return 0;
}