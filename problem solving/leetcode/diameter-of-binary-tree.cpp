#include <bits/stdc++.h>

#define debug(x) cout << x << "\n";
#define debug_vect(x)  \
  for (auto &item : x) \
    cout << item << " ";
#define read(x) cin >> x;

using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve();
int diameterOfBinaryTree(TreeNode *root);
int diameter(TreeNode *root, int &biggest);
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
  TreeNode *a = new TreeNode(4);
  TreeNode *b = new TreeNode(5);
  TreeNode *c = new TreeNode(2, a, b);
  TreeNode *d = new TreeNode(3);
  TreeNode *head = new TreeNode(3, c, d);
  TreeNode *secondHead = new TreeNode(1, new TreeNode(2), nullptr);

  debug(diameterOfBinaryTree(head));
  debug(diameterOfBinaryTree(secondHead));
}

int biggest = 0;
int diameter(TreeNode *root)
{
  if (root == nullptr)
    return -1;

  int left = diameter(root->left);
  int right = diameter(root->right);
  biggest = max(biggest, (2 + left + right));
  return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
  diameter(root);
  return biggest;
}
