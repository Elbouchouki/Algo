#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define debug_vect(x)  \
  for (auto &item : x) \
    cout << item << " ";
#define read(x) cin >> x;

using namespace std;

void solve();
vector<string> generateParenthesis(int n);
void gen(vector<string> &res, string in, int opened, int closed, int n);

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
  int n = 3;
  debug_vect(generateParenthesis(n));
}

vector<string> generateParenthesis(int n)
{
  vector<string> res;
  gen(res, "", 0, 0, n);
  return res;
}

void gen(vector<string> &res, string in, int opened, int closed, int n)
{
  if (in.length() == (n * 2))
  {
    res.push_back(in);
    return;
  }

  if (opened < n)
  {
    gen(res, (in + "("), opened + 1, closed, n);
  }
  if (closed < opened)
  {
    gen(res, (in + ")"), opened, closed + 1, n);
  }
}

// vector<string> generateParenthesis(int n)
// {
//   vector<string> res;
//   string in = "";
//   gen(res, in, 0, 0, n);
//   return res;
// }

// void gen(vector<string> &res, string &in, int opened, int closed, int n)
// {
//   if (in.length() == (n * 2))
//   {
//     res.push_back(in);
//     return;
//   }

//   if (opened < n)
//   {
//     in.push_back('(');
//     gen(res, in, opened + 1, closed, n);
//     in.pop_back();
//   }
//   if (closed < opened)
//   {
//     in.push_back(')');
//     gen(res, in, opened, closed + 1, n);
//     in.pop_back();
//   }
// }