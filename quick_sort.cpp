#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (arr[i] < pivot && i <= end)
            i++;
        while (arr[j] > pivot && j >= start + 1)
            j--;
        if (i >= j)
            break;
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    swap(arr[start], arr[j]);
    return j;
}

void quick_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int sorted = partition(arr, start, end);
        quick_sort(arr, start, sorted - 1);
        quick_sort(arr, sorted + 1, end);
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

    quick_sort(arr, 0, n - 1);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}