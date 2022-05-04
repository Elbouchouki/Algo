#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define read(x) cin >> x;

using namespace std;

void solve();
bool isValid(string s);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //#ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("error.txt", "w", stderr);
  // freopen("output.txt", "w", stdout);
  //#endif

  int t = 1;
  // /*is Single Test case?*/ cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}

void solve()
{
  string s = "())";
  debug((isValid(s) ? "true" : "false"));
}
bool isValid(string s)
{
  stack<char> parentheses;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ')' || s[i] == '}' || s[i] == ']')
    {
      if (parentheses.size() == 0)
        return false;
      char curr = parentheses.top();
      switch (s[i])
      {
      case ')':
        if (curr != '(')
          return false;
        break;
      case '}':
        if (curr != '{')
          return false;
        break;
      case ']':
        if (curr != '[')
          return false;
        break;
      default:
        return false;
      }
      parentheses.pop();
    }
    else
    {
      parentheses.push(s[i]);
    }
  }
  if (parentheses.size() != 0)
    return false;
  return true;
}
// bool isonlyopen(char s)
// {
//   if (s == '{' || s == '(' || s == '[')
//     return true;
//   return false;
// }
// bool ispairs(char s, char ss)
// {
//   if (s == '{' && ss == '}')
//     return true;
//   if (s == '(' && ss == ')')
//     return true;
//   if (s == '[' && ss == ']')
//     return true;
//   return false;
// }
// bool isValid(string s)
// {
//   stack<char> st;
//   for (int i = 0; i < s.length(); i++)
//   {
//     if (isonlyopen(s[i]))
//       st.push(s[i]);
//     else if (!st.empty() && ispairs(st.top(), s[i]))
//       st.pop();
//     else
//       return false;
//   }
//   return st.empty();
// }