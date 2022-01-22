#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> *arr);
void print_vect(vector<int> arr);

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 6, 8, 6, 4, 3, 2, 1, 5, 7};
    int size = arr.size();
    print_vect(arr);
    insertion_sort(&arr);
    print_vect(arr);
}
void print_vect(vector<int> arr)
{
    cout << "[";
    for (int x : arr)
        cout << x << " ";
    cout << "]" << endl;
}
void insertion_sort(vector<int> *arr)
{
    int size = (*arr).size();
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j >= 1 && (*arr)[j] < (*arr)[j - 1])
        {
            swap((*arr)[j], (*arr)[j - 1]);
            j--;
        }
    }
}