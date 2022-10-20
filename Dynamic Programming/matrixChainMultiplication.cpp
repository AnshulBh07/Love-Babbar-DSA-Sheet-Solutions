#include<iostream>
#include<cstring>
using namespace std;

/*Recursive approach
//This format remains same in all questions
int MCM(int *arr,int i,int j){

    //base case
    if(i>=j)
    return 0;

    int tempAns,mn = INT16_MAX;
    for(int k=i;k<j;k++){
        //tempAns = cost of part 1 + cost of part 2 + extra cost (part1 + part2)
        tempAns = MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);

        //function
        if(tempAns<mn)
        mn = tempAns;
    }
    return mn;
}*/


//Memoization
static int t[1001][1001];

int MCM(int *arr,int i,int j){
    
    //base case
    if(i>=j)
    return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    t[i][j] = INT16_MAX;
    for(int k=i;k<j;k++){
        t[i][j] = min(t[i][j],MCM(arr,i,k) + MCM(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]));
    }
    return t[i][j];
}

int main()
{
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i=1,j=n-1;
    memset(t,-1,sizeof(t));

    cout<<MCM(arr,i,j);
    return 0;
}