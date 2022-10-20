#include<iostream>
using namespace std;

bool isSubsequence(string X,string Y,int n,int m){
    int t[n+1][m+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }

    //code
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1])
            t[i][j] = 1 + t[i-1][j-1];
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }

    if(t[n][m]-n==0)
    return true;

    return false;
}


int main()
{
    string X = "abc",Y = "ahbgdc";
    int n = X.length(), m = Y.length();
    cout<<isSubsequence(X,Y,n,m);
    return 0;
}