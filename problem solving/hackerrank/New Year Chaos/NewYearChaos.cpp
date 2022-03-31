#include <bits/stdc++.h>
using namespace std;

/* ------------------------------- to complete ------------------------------ */
void minimumBribes(vector<int> q)
{
    int bribes = 0;
    for (int i = 0; i < q.size(); i++)
    {
        if (((i + 1) < q[i]) || (q[(i + 1)] < q[i]))
        {
            if (q[i] - (i + 1) > 2)
            {
                cout << "Too chaotic" << endl;
                return;
            }
            bribes += abs(q[i] - (i + 1));
        }
    }
    cout << bribes << endl;
}
/* ---------------------------------- test ---------------------------------- */
int main()
{
    vector<int> input1 = {1, 2, 3, 5, 4, 6, 7, 8};
    vector<int> input2 = {4, 1, 2, 3};
    vector<int> input3 = {2, 1, 5, 3, 4};
    vector<int> input4 = {2, 5, 1, 3, 4};
    vector<int> input5 = {1, 2, 5, 3, 7, 8, 6, 4};

    minimumBribes(input1); // 1
    minimumBribes(input2); // Too chaotic
    minimumBribes(input3); // 3
    minimumBribes(input4); // Too chaotic
    minimumBribes(input5); // 7

    return 0;
}