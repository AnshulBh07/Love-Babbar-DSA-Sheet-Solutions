#include<iostream>
using namespace std;

/*Time complexity : exponential
int fibonacci(int n){
    //base case
    if(n==1 || n==0)
    return n;

    return fibonacci(n-1) + fibonacci(n-2);
}*/

//using DP, Time Complexity : O(n), Space : O(n)
int fibonacci(int n){
    //create an array to store the fibonacci sequence 
    int f[n+2];
    f[0]=0;
    f[1]=1;

    for(int i=2;i<=n;i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}

int main()
{
    int n = 8;
    cout<<fibonacci(n);
    return 0;
}