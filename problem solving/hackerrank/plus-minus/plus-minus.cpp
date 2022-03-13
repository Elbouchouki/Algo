#include <bits/stdc++.h>
using namespace std;

void plusMinus(vector<int> arr)
{
    double pos = 0, neg = 0, zero = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else
        {
            if (arr[i] > 0)
                pos++;
            else
                neg++;
        }
    }
    cout << fixed << setprecision(6) << pos / arr.size() << endl
         << neg / arr.size() << endl
         << zero / arr.size() << endl;
}

int main()
{
    vector<int> input_1 = {1, 1, 0, -1, -1};
    vector<int> input_2 = {-4, 3, -9, 0, 4, 1};
    plusMinus(input_1);
    plusMinus(input_2);
}