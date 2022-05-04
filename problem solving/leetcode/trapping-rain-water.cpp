#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define read(x) cin >> x;

using namespace std;

int trap_On(vector<int> &height);
int trap(vector<int> &height);
int trap_3(vector<int> &height);
void solve();

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
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  debug(trap_3(height));
}

int trap_On(vector<int> &height)
{
  int n = height.size();
  vector<int> maxLeft(n);
  vector<int> maxRight(n);
  maxLeft[0] = height[0];
  maxRight[n - 1] = height[n - 1];

  for (int i = 1; i < n; i++)
  {
    maxLeft[i] = max(maxLeft[i - 1], height[i]);
  }
  for (int i = n - 2; i >= 0; i--)
  {
    maxRight[i] = max(maxRight[i + 1], height[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int cal = min(maxLeft[i], maxRight[i]) - height[i];
    if (cal > 0)
      ans += cal;
  }
  return ans;
}

int trap(vector<int> &height)
{
  int n = height.size();
  int left = 0, maxLeft = height[left];
  int right = n - 1, maxRight = height[right];
  int ans = 0;
  while (left < right)
  {
    if (maxLeft < maxRight)
    {
      left++;
      maxLeft = max(maxLeft, height[left]);
      ans += maxLeft - height[left];
    }
    else
    {
      right--;
      maxRight = max(maxRight, height[right]);
      ans += maxRight - height[right];
    }
  }
  return ans;
}
int trap_3(vector<int> &height)
{
  int ans = 0, leftMax = 0, rightMax = 0;
  int left = 0, right = height.size() - 1;
  while (left < right)
  {
    leftMax = max(height[left], leftMax);
    rightMax = max(height[right], rightMax);
    if (height[left] < height[right])
    {
      ans += leftMax - height[left];
      left++;
    }
    else
    {
      ans += rightMax - height[right];
      right--;
    }
  }
  return ans;
}