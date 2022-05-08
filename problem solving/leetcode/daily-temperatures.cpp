#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define debug_vect(x)  \
  for (auto &item : x) \
    cout << item << " ";
#define read(x) cin >> x;

using namespace std;

void solve();
vector<int> dailyTemperatures(vector<int> &temperatures);
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
  // [77,77,77,77,77,41,77,41,41,77]
  // vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> temperatures = {77, 77, 77, 77, 77, 41, 77, 41, 41, 77};

  debug_vect(dailyTemperatures(temperatures));
}

vector<int> dailyTemperatures(vector<int> &temperatures)
{
  int n = temperatures.size();
  vector<int> res(n, 0);
  stack<pair<int, int>> s;

  for (int i = 0; i < n; i++)
  {
    while (s.size() && s.top().first < temperatures[i])
    {
      int index = s.top().second;
      res[index] = i - index;
      s.pop();
    }
    if (i < n - 1 && temperatures[i + 1] > temperatures[i])
    {
      res[i] = 1;
    }
    else
    {
      s.push({temperatures[i], i});
    }
  }
  return res;
}