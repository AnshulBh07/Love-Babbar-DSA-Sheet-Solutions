#include<iostream>
#include<algorithm>
using namespace std;

string addBinary(string a,string b){
    int n = a.length()-1;
    int m = b.length()-1;
    string ans;
    int carry = 0;

    while(n>=0 || m>=0 || carry){
        if(n>=0){
            carry+=a[n] - '0';
            n--;
        }
        if(m>=0){
            carry+=b[m] - '0';
            m--;
        }

        ans+=(carry%2 + '0');
        carry = carry/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string a = "1010",b = "1011";
    cout<<addBinary(a,b);
    return 0;
}