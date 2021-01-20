#include <iostream>
using namespace std;

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        if (k < arr[i - 1])
        {
            int j = i;
            while (k < arr[j - 1] && j != 0)
            {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = k;
        }
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

    insertion_sort(arr, n);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}