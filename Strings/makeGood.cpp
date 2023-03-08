#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string makeGood(string s){
    if(s.length()==1 || s.length()==0)
    return s;

    string ans = "";

    stack<char> st;
    char ch;
    st.push(s[0]);

    for(int i=1;i<s.length();i++){
        ch = s[i];
        if((char)tolower(ch) == st.top() && ch!=st.top()){
            st.pop();
        }
        else{
            st.push(ch);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s = "leEeetcode";
    cout<<makeGood(s);
    return 0;
}