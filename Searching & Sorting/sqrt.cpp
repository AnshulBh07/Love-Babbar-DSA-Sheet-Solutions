#include<iostream>
using namespace std;

int findSqrt(int n){
    if(n==0 || n==1)
    return n;

    int s = 1, e = n/2;
    int mid,sqr,ans;
    while(s<=e){
        mid = s + (e-s)/2;
        sqr = mid * mid;

        if(sqr==n)
        return mid;

        if(sqr<=n){
            s=mid+1;
            ans=mid;
        }
        else 
        e= mid-1;
    }
    return ans;
}

int main()
{
    int n = 64;
    cout<<findSqrt(n);
    return 0;
}