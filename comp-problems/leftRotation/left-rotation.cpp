#include <bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(int d, vector<int> &arr)
{
    vector<int> res(arr.size());
    queue<int> q;
    for (int i = 0; i < arr.size(); i++)
    {
        }

    for (int i = 0; i < d; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < arr.size(); i++)
    {
        res[i] = q.front();
        q.pop();
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    rotateLeft(4, arr);
}