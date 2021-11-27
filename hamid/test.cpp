#include <bits/stdc++.h>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    int size_apples = apples.size();
    int size_oranges = oranges.size();
    int nbr_apples = 0, nbr_oranges = 0;
    for (int i = 0; i < size_apples; i++)
    {
        apples[i] += a;
        if (apples[i] >= s && apples[i] <= t)
            nbr_apples++;
    }
    for (int i = 0; i < size_oranges; i++)
    {
        oranges[i] += b;
        if (oranges[i] >= s && oranges[i] <= t)
            nbr_oranges++;
    }
    cout << nbr_apples << endl;
    cout << nbr_oranges << endl;
}

int main()
{
    vector<int> apples = {2, 3, -4};
    vector<int> oranges = {3, -2, -4};
    int s = 7, t = 10, a = 4, b = 12;
    countApplesAndOranges(s, t, a, b, apples, oranges);
}
