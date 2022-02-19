#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> *arr);
void print_vect(vector<int> arr);

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 6, 8, 6, 4, 3, 2, 1, 5, 7};
    int size = arr.size();
    print_vect(arr);
    selection_sort(&arr);
    print_vect(arr);
}
void print_vect(vector<int> arr)
{
    cout << "[";
    for (int x : arr)
        cout << x << " ";
    cout << "]" << endl;
}
void selection_sort(vector<int> *arr)
{
    int size = (*arr).size();
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if ((*arr)[j] < (*arr)[min_index])
                min_index = j;
        }
        swap((*arr)[i], (*arr)[min_index]);
    }
}