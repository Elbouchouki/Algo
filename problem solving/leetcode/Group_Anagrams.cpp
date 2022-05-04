#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> res;
    unordered_map<string, int> m;
    for (string s : strs)
    {
      vector<int> count(26, 0);
      for (char c : s)
      {
        count[c - 'a'] += 1;
      }
      string key = "";
      for (int x : count)
        key.append(to_string(x) + (char)('a' + x));
      const auto it = m.find(key);
      if (it != m.end())
        res[it->second].push_back(s);
      else
      {
        res.push_back({s});
        m[key] = res.size() - 1;
      }
    }
    return res;
  }
  static vector<vector<string>> groupAnagrams_opt(vector<string> &strs)
  {
    unordered_map<string, vector<string>> my_map;
    for (string s : strs)
    {
      string c = s;
      sort(c.begin(), c.end());
      my_map[c].push_back(s);
    }

    vector<vector<string>> res;
    for (auto itr : my_map)
    {
      res.push_back(itr.second);
    }
    return res;
  }
  static vector<vector<string>> groupAnagrams_opt2(vector<string> &strs)
  {
    vector<vector<string>> result;
    unordered_map<string, int> hash;

    for (const auto &str : strs)
    {
      auto sortedAna = str;
      sort(sortedAna.begin(), sortedAna.end());

      const auto it = hash.find(sortedAna);
      if (it != hash.end())
        result[it->second].push_back(str);
      else
      {
        result.push_back({str});
        hash[sortedAna] = result.size() - 1;
      }
    }

    return result;
  }
};
int main()
{

  // ["cab","tin","pew","duh","may","ill","buy","bar","max","doc"]
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // "eat","tea","tan","ate","nat","bat"
  // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  vector<vector<string>> res = Solution::groupAnagrams(strs);
  for (vector<string> single : res)
  {
    for (string s : single)
      cout << s << " ";
    cout << "\n";
  }
  return 0;
}