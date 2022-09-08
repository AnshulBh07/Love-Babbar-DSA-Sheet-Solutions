//check whether the given expression is valid or not , do this by checking number of opening and
//closing brackets and their positioning
#include <iostream>
#include <stack>
using namespace std;

bool IsValid(char *s)
{
    stack<char> st;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        //for ()
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }

        //for []
        else if (ch=='[')
        {
            st.push(ch);
        }
        else if(ch==']')
        {
            if(st.empty() || st.top()!='[')
            {
                return false;
            }
            st.pop();
        }

        //for {}
        else if(ch=='{')
        {
            st.push(ch);
        }
        else if(ch=='}')
        {
            if(st.empty() || st.top()!='{')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    char s[100] = "{(a+b)+[c-d+f]}";

    if (IsValid(s))
    {
        cout << "Valid String!\n";
    }
    else
    {
        cout << "Invalid String!\n";
    }
    return 0;
}