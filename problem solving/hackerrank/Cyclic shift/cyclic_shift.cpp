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
        vector<bool> stringA;
        vector<bool> stringB;
        string number;
        cin >> n >> k >> number;
        stringA.reserve(number.size());
        stringB.reserve(number.size());
        for (auto a : number)
            stringA.push_back(a == '1');
        stringB = stringA;
        for (long long int i = 0; i < k; i++)
        {
            stringB.insert(stringB.begin(), stringB[stringB.size() - 1]);
            stringB.pop_back();
            while (stringB != stringA)
            {
                stringB.insert(stringB.begin(), stringB[stringB.size() - 1]);
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
