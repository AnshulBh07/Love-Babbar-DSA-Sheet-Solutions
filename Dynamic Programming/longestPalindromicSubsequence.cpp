#include<iostream>
#include<algorithm>
using namespace std;

string reverseString(string X,int n){
    int i=0,j=n-1;
    while(i<j){
        swap(X[i],X[j]);
        i++;
        j--;
    }
    return X;
}

string LPS(string X,string Y,int n){
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
            if(X[i-1]==Y[j-1])
            t[i][j] = 1 + t[i-1][j-1];
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }

    //printing lcs
    string ans = "";
    int i=n,j=n;
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            ans.push_back(X[i-1]);
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

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string X = "agbcba";
    
    int n = X.length();
    string Y = reverseString(X,n);

    cout<<LPS(X,Y,n);
    return 0;
}