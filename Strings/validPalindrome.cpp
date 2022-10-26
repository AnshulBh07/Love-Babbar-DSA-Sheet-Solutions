#include<iostream>
using namespace std;

bool valindPalindrome(string s){
    string s2;

    for(int i=0;i<s.length();i++){
        if(isalpha(s[i]) || (s[i]<=9 && s[i]>=0))
        s2.push_back(s[i]);
    }
    for(int i=0;i<s2.length();i++){
        s2[i] = tolower(s2[i]);
    }

    int i=0,j=s2.length()-1;
    while(i<j){
        if(s2[i]==s2[j])
        return true;

        i++;
        j--;
    }
    return false;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout<<valindPalindrome(s);
    return 0;
}