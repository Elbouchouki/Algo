#include <bits/stdc++.h>
using namespace std;

typedef struct tag
{
    map<string, string> attributes;
    vector<int> childs;
} tag_t;

int main()
{
    string line;
    int n, q;
    cin >> n >> q;
    stack<int> s;
    vector<tag_t> tags;
    int curr_index = 0;
    while (n)
    {
        cin >> line;
        if (line[1] == '/')
        {
            s.pop();
            continue;
        }
        tag_t curr;
        s.push(stoi(line.substr(4, 1)));
        for (int i = 5; line.size(); i++)
        {
                }
    }
    return 0;
}
// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>

// tag1.tag2~name
// tag1~name
// tag1~value
