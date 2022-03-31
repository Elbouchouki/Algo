#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> *arr);
void print_vect(vector<int> arr);

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 6, 8, 6, 4, 3, 2, 1, 5, 7};
    int size = arr.size();
    print_vect(arr);
    bubble_sort(&arr);
    print_vect(arr);
}
void print_vect(vector<int> arr)
{
    cout << "[";
    for (int x : arr)
        cout << x << " ";
    cout << "]" << endl;
}
void bubble_sort(vector<int> *arr)
{
    int size = (*arr).size();
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size - i; j++)
            if ((*arr)[j] < (*arr)[j - 1])
                swap((*arr)[j], (*arr)[j - 1]);
}