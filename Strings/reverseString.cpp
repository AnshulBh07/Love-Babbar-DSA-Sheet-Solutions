#include<iostream>
#include<string>
using namespace std;

string getReverse(string s){
    int i = 0,j=s.size()-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}

int main()
{
    string s = "LeetCode";
    cout<<getReverse(s);
    return 0;
}