#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define debug_vect(x)  \
  for (auto &item : x) \
    cout << item << " ";
#define read(x) cin >> x;

using namespace std;

void solve();
int carFleet(int target, vector<int> &position, vector<int> &speed);

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
  int target = 12;
  vector<int> position = {10, 8, 0, 5, 3};
  vector<int> speed = {2, 4, 1, 1, 3};
  debug(carFleet(target, position, speed));
}

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
}