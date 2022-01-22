#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> a);
vector<int> reverseArray(vector<int> a);

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    printArray(array);
    printArray(reverseArray(array));
    return 0;
}

void printArray(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (i != 0)
            cout << "-";
        cout << a[i];
    }
    cout << endl;
}
vector<int> reverseArray(vector<int> a)
{
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        res[i] = a[a.size() - 1 - i];
    }
    return res;
}
