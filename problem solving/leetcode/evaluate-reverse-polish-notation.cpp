#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define read(x) cin >> x;

using namespace std;

void solve();
int evalRPN(vector<string> &tokens);

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
  // // ["4","13","5","/","+"]
  // vector<string> token = {"4", "13", "5", "/", "+"};
  // ["4","-2","/","2","-3","-","-"]
  // vector<string> token = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  vector<string> token = {"4", "-2", "/", "2", "-3", "-", "-"};
  debug(evalRPN(token));
}
bool isOperand(string c)
{
  return (c == "*" || c == "/" || c == "-" || c == "+");
}
int calculat(int a, int b, string op)
{
  if (op == "+")
    return a + b;
  if (op == "-")
    return a - b;
  if (op == "*")
    return a * b;
  return a / b;
}
int evalRPN(vector<string> &tokens)
{
  stack<int> s;
  for (string &token : tokens)
  {
    if (isOperand(token))
    {
      int op1 = s.top();
      s.pop();
      int op2 = s.top();
      s.pop();
      s.push(calculat(op2, op1, token));
    }
    else
    {
      s.push(stoi(token));
    }
  }
  return s.top();
}