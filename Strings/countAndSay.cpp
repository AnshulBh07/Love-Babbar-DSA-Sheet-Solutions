#include<iostream>
#include<unordered_map>
using namespace std;

string countAndSay(int n){
    if(n == 1) return "1";
        string num = countAndSay(n-1);
        string res; int count = 0;
        for(int i = 0; i < num.size(); i++)
        {
            if(i == 0 || num[i] == num[i-1]) count++;
            else {
                res += to_string(count) + num[i-1];
                count = 1;
            }
        }
        res += to_string(count) + num.back();
        return res;
}

int main()
{
    string str = "332221";
    int n = str.size();
    string ans = countAndSay(n);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}