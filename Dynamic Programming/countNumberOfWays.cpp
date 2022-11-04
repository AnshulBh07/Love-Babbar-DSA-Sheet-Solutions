#include<iostream>
#include<cstring>
using namespace std;

/*Recursive approach (very time consuming)
//Time Complexity : O(2^n)
int climbStairs(int dist){
    // base cases
    if(dist<0)  return 0; //invalid input
    if(dist==0) return 1; //starting position

    return climbStairs(dist-1) + climbStairs(dist-2); //you can only take 1 or 2 steps 
}
*/

/*Memoization
static int t[45+1];

int climbStairs(int dist){
    if(dist < 0)
    return 0;

    if(dist==0)
    return 1;

    if(t[dist]!=-1)
    return t[dist];

    return t[dist] = climbStairs(dist-1) + climbStairs(dist-2);

}*/

//DP, Time Complexity : O(n), Space : O(n)
int climbStairs(int dist){
    int t[dist+1];

    //base case
    t[0]=1;
    if(dist>=1)
    t[1] = 1;

    for(int i=1;i<dist+1;i++){
        t[i] = t[i-1] + t[i-2];
    }

    return t[dist];
}

int main()
{
    //memset(t,-1,sizeof(t));
    cout<<climbStairs(45);
    return 0;
}