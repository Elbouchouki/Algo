#include <bits/stdc++.h>
using namespace std;

typedef struct tag
{
    map<string, string> attributes;
    vector<int> childs;
} tag_t;

int main()
{
    int n, q, curr_index;
    string nullStr;
    stack<int> tag_stack;
    vector<tag_t> tag_list;
    cin >> n >> q;
    getline(cin, nullStr);
    for (int v = 0; v < n; v++)
    {
        int flag = 1;
        string temp_line, key, value;
        getline(cin, temp_line);
        cout << temp_line;
        stringstream X(temp_line);
        // close tag case
        if (temp_line[1] == '/')
        {
            tag_stack.pop();
            if (tag_stack.size())
                cout << temp_line[4] - 1;
            tag_list[tag_stack.top()].childs.push_back(temp_line[4] - 1);
            continue;
        }
        getline(X, nullStr, ' ');
        tag_t curr_tag;
        while (flag)
        {
            getline(X, key, ' ');
            getline(X, nullStr, ' ');
            getline(X, value, ' ');
            curr_tag.attributes.insert({key, value.substr(0, value.length() - 2)});
            if (value[value.length() - 1] == '>')
                flag = 0;
        }
        tag_list.push_back(curr_tag);
    }

    // cout << endl;
    // while (tag_stack.size())
    // {
    //     cout << tag_stack.top() << " ";
    //     tag_stack.pop();
    // }

    return 0;
}