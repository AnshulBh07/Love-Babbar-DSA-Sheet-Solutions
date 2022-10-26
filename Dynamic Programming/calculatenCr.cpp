#include<iostream>
#include<cstring>
using namespace std;

//DP
int nCr(int n,int r){
    
    int t[n+1][r+1];
    int mod = 1000000007;

    //base case
    for(int i=0;i<n+1;i++){ // r==0
        t[i][0] = 1;
    }
    for(int j=1;j<r+1;j++) //n<r
        t[0][j] = 0;

    //code
    for(int i=1;i<n+1;i++){
        for(int j=1;j<r+1;j++){
            if(n>r){
                t[i][j] = (t[i-1][j-1] + t[i-1][j])%mod;
            }
            else if(n<r)
            t[i][j] = 0;
            else if(n==r)
            t[i][j] = 1;
        }
    }
    return t[n][r];
}

/*Recursion
int nCr(int n,int r){

    //base cases
    if(r>n)
    return 0;

    if(n==r || r==0)
    return 1;

    int smallProb = nCr(n-1,r-1) + nCr(n-1,r);
    return smallProb;
}*/

int main()
{
    int n = 10, r =5;
    //memset(t,-1,sizeof(t));

    cout<<nCr(n,r);
    return 0;
}