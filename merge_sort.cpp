#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int left = mid - start + 1;
    int right = end - mid;

    int left_arr[left], right_arr[right];

    for (int i = 0; i < left; i++)
        left_arr[i] = arr[start + i];
    for (int i = 0; i < right; i++)
        right_arr[i] = arr[i + mid + 1];

    int i, j, k = start;
    i = j = 0;

    while (i < left && j < right)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }
    while (i < left)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr[16] = {2, 3, 4, 1, 6, 5, 11, 3, 2, 1, 8, 32, 6, 8, 13, 5};
    int n = 16;

    cout << "Before: ";
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";

    merge_sort(arr, 0, n - 1);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}