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
TreeNode *invertTree(TreeNode *root);
void display(TreeNode *root);
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
  TreeNode *left = new TreeNode(1);
  TreeNode *right = new TreeNode(3);
  TreeNode *head = new TreeNode(2, left, right);
  display(head);
  cout << "\n";
  TreeNode *newHead = invertTree(head);
  display(newHead);
}
void display(TreeNode *root)
{
  if (root == nullptr)
    return;
  cout << root->val << " ";
  display(root->left);
  display(root->right);
}
TreeNode *invertTree(TreeNode *root)
{
  if (root == nullptr)
    return root;
  invertTree(root->left);
  invertTree(root->right);

  TreeNode *temp = root->right;
  root->right = root->left;
  root->left = temp;
  return root;
}
