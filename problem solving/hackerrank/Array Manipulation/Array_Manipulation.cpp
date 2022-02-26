#include <bits\stdc++.h>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries)
{
    long max = 0;
    vector<long> elements(n + 1, 0);
    for (size_t i = 0; i < queries.size(); i++)
        for (size_t j = queries[i][0]; j <= queries[i][1]; j++)
        {
            elements[j] += queries[i][2];
            if (elements[j] > max)
                max = elements[j];
        }
    return max;
    // return *max_element(elements.begin(), elements.end());
}
void testcase_1()
{
    int n = 5;
    vector<vector<int>> queries = {
        vector<int>{1, 2, 100},
        vector<int>{2, 5, 100},
        vector<int>{3, 4, 100}};
    cout << arrayManipulation(n, queries) << endl;
}
void testcase_2()
{
    int n = 10;
    vector<vector<int>> queries = {vector<int>{2, 6, 8},
                                   vector<int>{3, 5, 7},
                                   vector<int>{1, 8, 1},
                                   vector<int>{5, 9, 15}};
    cout << arrayManipulation(n, queries) << endl;
}
int main()
{
    testcase_1();
    testcase_2();
}