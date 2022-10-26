#include <iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// remove trailing and leading edges
string removeEdges(string s)
{
    int i = 0, j = s.length() - 1;
    while (s[i] == ' ')
        i++;
    while (s[j] == ' ')
        j--;

    string str;
    for (int k = i; k <= j; k++)
    {
        str.push_back(s[k]);
    }
    return str;
}

int lengthOfLastWord(string s)
{
    vector<string> tokens;
    string snew = removeEdges(s);

    stringstream ss(snew);
    string temp_str;

    while (getline(ss, temp_str, ' '))
    {
        tokens.push_back(temp_str);
    }

    int n = tokens.size();
    int len = tokens[n - 1].length();

    return len;
}

int main()
{
    string s = "   fly me   to   the moon  ";
    cout<<lengthOfLastWord(s);
    return 0;
}