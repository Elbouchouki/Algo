#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_case;
    vector<long long int> result;
    cin >> test_case;
    while (test_case--)
    {
        long long int n, k, cpt = 1;
        string stringA, stringB;
        cin >> n >> k >> stringB;
        stringA = stringB;
        for (long long int i = 0; i < k; i++)
        {
            stringB.insert(0, stringB.substr(n - 1, 1));
            stringB.pop_back();
            while (stringB.compare(stringA))
            {
                stringB.insert(0, stringB.substr(n - 1, 1));
                stringB.pop_back();
                cpt++;
            }
        }
        result.push_back(cpt);
    }
    for (long long int i : result)
        cout << i << endl;
    return 0;
}
