#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define read(x) cin >> x;

using namespace std;

void solve();
class MinStack
{
  vector<int> s;
  vector<int> min_s;

public:
  MinStack()
  {
  }

  void push(int val)
  {
    int curr_min = val;
    if (s.size())
    {
      curr_min = min(val, min_s[min_s.size() - 1]);
    }
    s.push_back(val);
    min_s.push_back(curr_min);
  }

  void pop()
  {
    s.pop_back();
    min_s.pop_back();
  }

  int top()
  {
    return s[s.size() - 1];
  }

  int getMin()
  {
    return min_s[min_s.size() - 1];
  }
};

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
  //   ["MinStack","push","push","push","getMin","pop","top","getMin"]
  // [[],[-2],[0],[-3],[],[],[],[]]
  // [ "MinStack", "push", "push", "push", "push", "getMin", "pop", "getMin", "pop", "getMin", "pop", "getMin" ]
  // [[],[2],[0],[3],[0],[],[],[],[],[],[],[]]
  MinStack *obj = new MinStack();
  obj->push(2);
  obj->push(0);
  obj->push(3);
  obj->push(0);

  debug(obj->getMin());
  obj->pop();
  debug(obj->getMin());
  obj->pop();
  debug(obj->getMin());
  obj->pop();
  debug(obj->getMin());
}
