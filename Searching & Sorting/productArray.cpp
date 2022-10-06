#include<iostream>
#include<vector>
using namespace std;

vector<int> productArray(vector<int>&v){
    vector<int> ans;
    int product =1;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            product*=v[i];
        }
        else    count++;
    }

    for(int i=0;i<v.size();i++){
        if(count==0){
            long long x = product;
            ans.push_back(x/v[i]);
        }
        else{
            if(v[i]!=0){
                ans.push_back(0);
            }
            else{
                if(count==1){
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v{10,3,5,6,2};
    vector<int> ans = productArray(v);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}