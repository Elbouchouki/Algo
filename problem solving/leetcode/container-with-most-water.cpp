#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define read(x) cin >> x;

using namespace std;

void solve();
int maxArea(vector<int> &height);
int maxArea_bruteforce(vector<int> &height);

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
  // [2,3,4,5,18,17,6]
  vector<int> height = {2, 3, 4, 5, 18, 17, 6};
  debug(maxArea(height));
}

int maxArea_bruteforce(vector<int> &height)
{
  int n = height.size();
  int m = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      int distance = abs(i - j);
      int curr = distance * min(height[i], height[j]);
      m = max(m, curr);
    }
  }
  return m;
}

int maxArea(vector<int> &height)
{
  int m = 0;
  int left = 0;
  int right = height.size() - 1;
  while (left < right)
  {
    int newMax = abs(left - right) * min(height[left], height[right]);

    m = max(newMax, m);
    if (height[left] > height[right])
      right--;
    else
      left++;
  }
  return m;
}