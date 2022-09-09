#include<iostream>
using namespace std;

int getFactorial(int n){
    //base case
    if(n>=1)
    {
        return n*getFactorial(n-1);;
    }
    return 1;
}

int main()
{
    int n=10;
    cout<<getFactorial(n);
    return 0;
}