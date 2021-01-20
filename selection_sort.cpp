#include <iostream>
using namespace std;

void selection_sort(int *arr, int n)
{
    int arr_loc;
    int min = INT_MAX;
    int j = 0;
    while (j < n)
    {
        for (int i = j; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                arr_loc = i;
            }
        }
        swap(arr[j], arr[arr_loc]);
        j++;
        min = INT_MAX;
    }
}

int main()
{
    int arr[16] = {2, 3, 4, 1, 6, 5, 11, 3, 2, 1, 8, 32, 6, 8, 13, 5};
    int n = 16;

    cout << "Before: ";
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";

    selection_sort(arr, n);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}
