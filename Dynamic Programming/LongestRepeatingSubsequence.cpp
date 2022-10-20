#include<iostream>
using namespace std;

int LRS(string X,int n){
    string Y = X;
    int t[n+1][n+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }

    //code
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(X[i-1]==Y[j-1] && i!=j)
            t[i][j] = t[i-1][j-1] + 1;
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][n];
}

int main()
{
    string X = "AABEBCDD";
    int n = X.length();
    cout<<LRS(X,n);
    return 0;
}