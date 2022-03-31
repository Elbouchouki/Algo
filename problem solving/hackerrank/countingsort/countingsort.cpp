#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr)
{
    vector<int> res(100, 0);
    for (int x : arr)
        res[x]++;
    return res;
}

int main()
{

    vector<int> input = {1, 1, 3, 2, 1};
    vector<int> result = countingSort(input);
    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}