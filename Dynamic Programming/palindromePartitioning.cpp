#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool isPalindrome(string s,int i,int j){

    while(i<j){
        if(s[i]!=s[j]);
        return false;

        i++;j--;
    }
    return true;
}

/*Recursion
int palindromePartition(string s,int i,int j){
    //base case
    if(i>=j || isPalindrome(s,i,j))
    return 0;

    int ans = INT16_MAX,tempAns;
    //looping k
    for(int k=i;k<j;k++){
        tempAns = palindromePartition(s,i,k) + palindromePartition(s,k+1,j) + 1;

        ans = min(ans,tempAns);
    }
    return ans;
}*/

//Memoization
static int t[100][100];

int palindromePartition(string s,int i,int j){
    //base case
    if(i>=j || isPalindrome(s,i,j))
    return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    t[i][j] = INT16_MAX;
    //looping k
    for(int k=i;k<j;k++){
        t[i][j] = min(t[j][j],palindromePartition(s,i,k) + palindromePartition(s,k+1,j) + 1);
    }

    /*Optimized code
    int left,right;
    for(int k=i;k<j;k++){
        if(t[i][k]!=-1)
        left = t[i][k];
        else
        left = solve(s,i,k);
        t[i][k] = left;

        if(t[k+1][j]!=-1)
        right = t[k+1][j];
        else
        right = solve(s,k+1,j)
        t[k+1][j] = right;

        tempAns = 1 + left + right;

        ans = min(ans,tempAns);
    }*/
    return t[i][j];
}

int main()
{
    string s = "ababbbabbababa";
    int n = s.length();
    int i=0,j=n-1;
    memset(t,-1,sizeof(t));

    cout<<palindromePartition(s,i,j);
    return 0;
}