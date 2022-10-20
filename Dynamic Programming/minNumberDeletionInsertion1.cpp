//make Y from X and find minimum number of insertions and deletions to do so
#include<iostream>
using namespace std;

int minDeletionInsertion(string X,string Y,int n,int m){
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

    int lenLCS = t[n][m];
    return (n-lenLCS) + (m-lenLCS);
}

int main()
{
    string X = "apple", Y = "pea";
    int n = X.length(), m = Y.length();
    cout<<minDeletionInsertion(X,Y,n,m);
    return 0;
}