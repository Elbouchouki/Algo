#include <bits/stdc++.h>
using namespace std;

string strings_xor(string s, string t)
{

    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        res.append(to_string(s[i] ^ t[i]));
    }
    return res;
}

int main()
{
    cout << strings_xor("10101", "00101") << endl;
    return 0;
}