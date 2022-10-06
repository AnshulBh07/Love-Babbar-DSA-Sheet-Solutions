#include<iostream>
using namespace std;

int sumNumString(string s){
    string temp = "";
    char ch;
    int sum = 0;
    for(int i=0;i<s.length();i++){
        ch = s[i];
        if(isdigit(ch)){
            temp+=ch;
        }
        else{
            sum+=atoi(temp.c_str());
            temp="";
        }
    }
    return sum+atoi(temp.c_str());
}

int main()
{
    string s = "xi10j5xANs3h112ul";
    cout<<sumNumString(s);
    return 0;
}