#include<vector>
#include<iostream>
using namespace std;

int maxSumSubArray(vector<int>&v,int k){
    int win_sum=0;
    for(int i=0;i<k;i++){
        win_sum+=v[i];
    }

    int curr_sum=win_sum;
    for(int i=k;i<v.size();i++){
        curr_sum += v[i]-v[i-k];
        win_sum = max(win_sum,curr_sum);
    }
    return win_sum;
}

int main()
{
    vector<int> v{1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k =4;
    cout<<maxSumSubArray(v,k);
    return 0;
}