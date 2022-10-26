//whenever count of 0 becomes equal to count of 1 increment ans;
#include<iostream>
using namespace std;

int countMaxSubstr(string s){
    int n = s.length();
    int count0 =0,count1 = 0,count;

    for(int i=0;i<n;i++){
        if(s[i]=='0')
        count0++;
        else
        count1++;

        if(count0==count1)
        count++;
    }

    if(count1!=count0)
    return -1;

    return count;
}

int main()
{
    string s = "0100110101";
    cout<<countMaxSubstr(s);
    return 0;
}