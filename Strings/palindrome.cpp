#include<iostream>
#include<string>
using namespace std;

string getReverse(string s){
    int i = 0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])
        return "NO";
        i++;
        j--;
    }
    return "YES";
}

int main()
{
    string s = "aabbaa";
    cout<<getReverse(s);
    return 0;
}