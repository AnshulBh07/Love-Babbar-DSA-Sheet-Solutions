#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string printLCS(string X,string Y,int n,int m){
    int t[n+1][m+1];

    //base
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0)
            t[i][j]=0;
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

    //printing
    string str = "";
    int i=n,j=m;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            str.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j])
            j--;
            else
            i--;
        }
    }
    reverse(str.begin(),str.end()); 
    return str;
}

int main()
{
    string X = "acbcf",Y = "abcdaf";
    int n=X.length(),m=Y.length();

    cout<<printLCS(X,Y,n,m);
    return 0;
}