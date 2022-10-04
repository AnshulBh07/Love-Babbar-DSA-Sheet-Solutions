#include<iostream>
#include<vector>
using namespace std;

int sumOfSquares(int n){
    vector<int> sampleSpace;
    int i=1;
    while(i*i<n){
        sampleSpace.push_back(i*i);
        i++;
    }

    int x=0,count=0,sum=0;
    while(sum!=n){
        sum+=sampleSpace[x];

        if(sum>n)
        x=0;

        x++;
        count++;
    }

    return count;
}

int main()
{
    int n =13;
    cout<<sumOfSquares(n);
    return 0;
}