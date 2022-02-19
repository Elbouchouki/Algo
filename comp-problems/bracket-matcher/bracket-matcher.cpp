#include <bits/stdc++.h>
using namespace std;

string BracketMatcher(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        if (str[i] == ')')
        {
            if (st.size() == 0)
                return "0";
            st.pop();
        }
    }
    return "1";
}

int main(void)
{

    cout << BracketMatcher("()()()()((()))(()())(())()(()");
    return 0;
}