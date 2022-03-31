#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> *arr);
void print_vect(vector<int> arr);

void _quick_sort(vector<int> *arr, int start, int end);
int partition(vector<int> *arr, int start, int end);

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 6, 8, 6, 4, 3, 2, 1, 5, 7};
    int size = arr.size();
    print_vect(arr);
    quick_sort(&arr);
    print_vect(arr);
}
void print_vect(vector<int> arr)
{
    cout << "[";
    for (int x : arr)
        cout << x << " ";
    cout << "]" << endl;
}
void quick_sort(vector<int> *arr)
{
    _quick_sort(arr, 0, (*arr).size() - 1);
}
void _quick_sort(vector<int> *arr, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(arr, start, end);
    _quick_sort(arr, start, pivot - 1);
    _quick_sort(arr, pivot + 1, end);
}
int partition(vector<int> *arr, int start, int end)
{
    int i = start + 1, j = i, pivot = start;
    while (j <= end)
    {
        if ((*arr)[j] < (*arr)[pivot])
        {
            swap((*arr)[j], (*arr)[i]);
            i++;
        }
        j++;
    }
    swap((*arr)[pivot], (*arr)[i - 1]);
    return i - 1;
}