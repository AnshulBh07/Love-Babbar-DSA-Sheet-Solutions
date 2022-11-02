#include<iostream>
#include<stack>
using namespace std;

int longestValidString(string s){
    stack<char> st;
    char ch;

    for(int i=0;i<s.length();i++){
        ch = s[i];
        if(ch=='(')
        st.push(ch);
        else if(ch==')'){
            if(st.top()=='(')
            st.pop();
            else
            st.push(ch);
        }
    }
    return s.length()-st.size();
}

int main()
{
    string s = "(()(";
    cout<<longestValidString(s);
    return 0;
}