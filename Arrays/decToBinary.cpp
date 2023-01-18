#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int binaryToDecimal(string binNumber){
    int ans = 0;

    int base = 1; //2^0
    
    for(int i = binNumber.length()-1;i>=0;i--){
        ans+= (binNumber[i]-'0')*base;
        base *=2;
    }
    return ans;
}

vector<int> decToBinary(int n){
    vector<int> ans;

    while(n>0){
        ans.push_back(n%2);
        n = n/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    
    int n;
    string binNumber;
    cout<<"Enter binary number : ";
    cin>>binNumber;
    cout<<"Corresponding decimal number is : "<<binaryToDecimal(binNumber);

    cout<<endl;
    cout<<"\nEnter decimal number : ";
    cin>>n;
    cout<<"Corresponding binary number is : ";
    vector<int> ans = decToBinary(n);
    for(auto it : ans)
    cout<<it;

    return 0;
}