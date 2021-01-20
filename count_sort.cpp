#include <iostream>
using namespace std;

void count_sort(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int temp_arr[max + 1] = {0};

    for (int i = 0; i < n; i++)
        temp_arr[arr[i]]++;

    int k = 0;

    for (int i = 0; i < max + 1; i++)
    {
        int j = temp_arr[i];
        while (j > 0)
        {
            arr[k] = i;
            j--;
            k++;
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

    count_sort(arr, n);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}
