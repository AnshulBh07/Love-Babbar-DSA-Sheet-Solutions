/*Three steps involved for best understanding
    Recursive(Parent) ---> Memoization ---> Top Down DP
    after you are practised enough u can do top down after revursive itself
    For recursive always make the choice diagram*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
Recursive approach
int knapSack(int *wt,int *val,int W,int n){
    //base case --> think of smallest possible input from parameters
    //return the optimal solution at minimum possible input
    if(n==0 || W==0) 
    return 0;

    if(wt[n-1]<=W)
    return max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1),knapSack(wt,val,W,n-1));

    else if(wt[n-1]>W)
    return knapSack(wt,val,W,n-1);
}


//Memoization
static int t[1001][1001];

int knapSack(int *wt,int *val,int W,int n){
    if(n==0 || W==0)    
    return 0;

    if(t[n][W]!=-1) 
    return t[n][W];

    if(wt[n-1]<=W)
    return t[n][W] = max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1),knapSack(wt,val,W,n-1));

    else if(wt[n-1]>W)
    return t[n][W] = knapSack(wt,val,W,n-1);
}
*/

//True DP (Top down Approach)
static int t[4][5];

int knapSack(int *wt,int *val,int W,int n){
    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0)
            t[i][j] == 0;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int wt[]={4,5,1};
    int val[]={1,2,3};
    int W = 4,n = 3;

    cout<<knapSack(wt,val,W,n);
    return 0;
}