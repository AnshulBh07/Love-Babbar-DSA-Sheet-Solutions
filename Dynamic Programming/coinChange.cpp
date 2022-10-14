//unbounded version of subset sum
#include<iostream>
#include<cstring>
using namespace std;

/*
//Recursive - caused TLE on gfg the code is right tho
int coinChange(int *coins,int n,int sum){
    //base cases
    if(n==0)
    return 0;
    if(sum==0)
    return 1;

    if(coins[n-1]<=sum)
    return coinChange(coins,n,sum-coins[n-1]) + coinChange(coins,n-1,sum);

    else
    return coinChange(coins,n-1,sum);
}

//Memoization
static int t[5][11];

int coinChange(int *coins,int n,int sum){
    //base cases
    if(n==0)
    return 0;
    if(sum==0)
    return 1;

    if(t[n][sum]!=-1)
    return t[n][sum];

    if(coins[n-1]<=sum)
    return t[n][sum] = coinChange(coins,n,sum-coins[n-1])+coinChange(coins,n-1,sum);
    else
    return t[n][sum] = coinChange(coins,n-1,sum);
}*/

//DP
int coinChange(int *coins,int n,int sum){
    long long int t[n+1][sum+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
            t[i][j] = 0;
            if(j==0)
            t[i][j] = 1;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coins[i-1]<=j)
            t[i][j] = t[i][j-coins[i-1]],t[i-1][j];
            else
            t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int coins[]={1,2,3};
    int n=3,sum=4;
    //memset(t,-1,sizeof(t));

    cout<<coinChange(coins,n,sum);
    return 0;
}