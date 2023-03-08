#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

string removeLeadingTrailing(string s){
    int countT =0; //count number of trailing spaces
    int countL = 0; //count number of leading spaces

    int i = 0;

    while(s[i]==' '){
        countL++;
        i++;
    }

    i= s.length()-1;
    while(s[i]==' '){
        countT++;
        i--;
    }

    //removing spaces
    s.erase(s.begin()+0,s.begin()+countL);
}

string removeExtraMid(string s){

}

string revreseWords(string s){

    stringstream ss(s);
    string temp_str;
    vector<string> v;
    string ans="";

    while(getline(ss,temp_str,' ')){
        v.push_back(temp_str);
    }

    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }

    return ans;
}

int main(){
    string s = "  the  sky    is blue   ";
    cout<<s<<endl;
    removeLeadingTrailing(s);
    cout<<s;
    return 0;
}