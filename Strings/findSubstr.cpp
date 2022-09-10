#include<iostream>
#include<string>
using namespace std;

bool isSubStr(string str1,string str2){
    string temp=str1+str2;
    if(str1.length()!=str2.length()){
        return false;
    }

    return(temp.find(str2)!=string::npos);
}

int main()
{
    string str1="AACD",str2="ACDA";
    cout<<isSubStr(str1,str2);
    return 0;
}