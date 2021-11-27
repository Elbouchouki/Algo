#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> *arr);
void print_vect(vector<int> arr);

void _merge_sort(vector<int> *arr, int start, int end);
void merge(vector<int> *arr, int start, int mid, int end);

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 6, 8, 6, 4, 3, 2, 1, 5, 7};
    int size = arr.size();
    print_vect(arr);
    merge_sort(&arr);
    print_vect(arr);
}
void print_vect(vector<int> arr)
{
    cout << "[";
    for (int x : arr)
        cout << x << " ";
    cout << "]" << endl;
}
void merge_sort(vector<int> *arr)
{
    _merge_sort(arr, 0, (*arr).size() - 1);
}

void _merge_sort(vector<int> *arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    _merge_sort(arr, start, mid);
    _merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
void merge(vector<int> *arr, int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int left[size1], right[size2];

    for (int i = 0; i < size1; i++)
        left[i] = (*arr)[i + start];
    for (int i = 0; i < size2; i++)
        right[i] = (*arr)[i + mid + 1];

    int l = 0, r = 0, index = start;
    while (l < size1 && r < size2)
    {
        if (left[l] < right[r])
        {
            (*arr)[index++] = left[l++];
        }
        else
        {
            (*arr)[index++] = right[r++];
        }
    }
    while (l < size1)
        (*arr)[index++] = left[l++];
    while (r < size2)
        (*arr)[index++] = right[r++];
}