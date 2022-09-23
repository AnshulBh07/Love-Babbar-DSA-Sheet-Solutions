#include<iostream>
#include<map>
using namespace std;

int autoNumber(string str){
    map<int,int> freq;
    int sum=0,sum1=0;
    
    char ch;
    for(int i=0;i<str.length();i++){
        ch = str[i];
        freq[str[i]]++;
        sum+=ch;
    };

    for(auto x:freq){
        cout<<x.second<<" ";
        sum1+=x.second;
    }
    cout<<sum;
}

int main()
{
    string str = "3211000";
    autoNumber(str);
    return 0;
}