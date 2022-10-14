/*This is a classic problem of unbounded knapsack, in unbounded knapsack we can use the same instance
of an item multiple items. In this problem we need to cut the rod in such a way that the profit is
maximum. */
#include<iostream>
#include<cstring>
using namespace std;

/*
//Recursive approach
int rodCutting(int *piece,int *price,int L,int n){
    if(L==0 || n==0)    return 0;

    if(piece[n-1]<=L)
    return max(price[n-1]+rodCutting(piece,price,L-piece[n-1],n),rodCutting(piece,price,L,n-1));

    else if(piece[n-1]>L)
    return rodCutting(piece,price,L,n-1);
}

//Memoization
static int t[9][9];

int rodCutting(int *piece,int *price,int L,int n){
    if(L==0 || n==0) return 0;

    if(t[n][L]!=-1)
    return t[n][L];

    if(piece[n-1]<=L)
    return t[n][L] = max(price[n-1]+rodCutting(piece,price,L-piece[n-1],n),rodCutting(piece,price,L,n-1));

    else
    return t[n][L] = rodCutting(piece,price,L,n-1);
}*/

int rodCutting(int *piece,int *price,int L,int n){
    int t[n+1][L+1];

    //base case
    for(int i=0;i<n+1;i++){
        for(int j=0;j<L+1;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<L+1;j++){
            if(piece[i-1]<=j)
            t[i][j] = max(price[i-1]+t[i][j-piece[i-1]],t[i-1][j]);
            else
            t[i][j] = t[i-1][j];
        }
    }
    return t[n][L];
}

int main(){
    //two ararys or we can say one arary with two properties
    int piece[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,17,20};
    int L = 8; //length of rod
    int n = sizeof(piece)/sizeof(piece[0]);

    //memset(t,-1,sizeof(t));
    cout<<rodCutting(piece,price,L,n);
    return 0;
}
