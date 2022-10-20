#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/*
//Recursive
int LCS(string X,string Y,int n,int m){
    //base case
    if(n==0 || m==0)
    return 0;

    //choice diagram
    if(X[n-1]==Y[m-1])
    return 1 + LCS(X,Y,n-1,m-1);

    else
    return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
}

//Memoization (Bottom Up)
static int t[1001][1001];

int LCS(string X,string Y,int n,int m){
    //base case
    if(n==0 || m==0)
    return 0;

    if(t[n][m]!=-1)
    return t[n][m];

    if(X[n-1]==Y[m-1])
    return t[n][m] = 1 + LCS(X,Y,n-1,m-1);
    else
    return t[n][m] = max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1)); 
}*/

int LCS(string X,string Y,int n,int m){
    int t[n+1][m+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }

    //choice diagram
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1])
            t[i][j] = 1 + t[i-1][j-1];
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][m];
}

int main()
{
    string X = "abcde", Y = "ace";
    int n = X.length(), m = Y.length();

    //memset(t,-1,sizeof(t));
    cout<<"Length of longest common subsequence : "<<LCS(X,Y,n,m);
    return 0;
}