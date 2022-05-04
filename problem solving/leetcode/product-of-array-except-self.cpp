#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define debug_vect(x) \
  for (auto y : x)    \
    cout << y << " ";
#define read(x) cin >> x;

using namespace std;

void solve();
vector<int> productExceptSelf(vector<int> &nums);
vector<int> productExceptSelf_opt(vector<int> &nums);

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
  vector<int> nums = {1, 2, 3, 4};
  vector<int> res = productExceptSelf_opt(nums);
  for (auto x : res)
  {
    debug(x);
  }
}
vector<int> productExceptSelf(vector<int> &nums)
{
  vector<int> res(nums.size());
  for (int i = 0; i < nums.size(); i++)
  {
    int prod = 1;
    for (int j = 0; j < nums.size(); j++)
    {
      if (i == j)
        continue;
      prod *= nums[j];
    }
    res[i] = prod;
  }
  return res;
}

vector<int> productExceptSelf_opt(vector<int> &nums)
{
  int n = nums.size();
  vector<int> res(n);
  int prefix = 1;
  for (int i = 0; i < n; i++)
  {
    res[i] = prefix;
    prefix *= nums[i];
  }
  int postfix = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    res[i] *= postfix;
    postfix *= nums[i];
  }
  return res;
}
