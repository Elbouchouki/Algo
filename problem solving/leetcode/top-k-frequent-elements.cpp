#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define debug_vect(x) \
  for (auto y : x)    \
    cout << y << " ";
#define read(x) cin >> x;

using namespace std;

void solve();
vector<int> topKFrequent(vector<int> &nums, int k);

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

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs";
  return 0;
}

void solve()
{
  vector<int> nums = {1};
  int k = 1;
  vector<int> res = topKFrequent(nums, k);
  for (auto x : res)
  {
    debug(x);
  }
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
  unordered_map<int, int> m;
  for (auto num : nums)
  {
    m[num] += 1;
  }
  vector<vector<int>> sorting(nums.size());
  for (pair<int, int> p : m)
  {
    sorting[p.second - 1].push_back(p.first);
  }

  vector<int> res;
  for (int i = sorting.size() - 1; i >= 0; i--)
  {
    for (auto x : sorting[i])
    {
      if (res.size() == k)
        break;
      res.push_back(x);
    }
  }
  return res;

  // for(auto x:nums){
  //   sorting[]
  // }
}
