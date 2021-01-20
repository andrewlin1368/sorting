#include <iostream>
using namespace std;

void shell_sort(int *arr, int n)
{
    int gap = n / 2;
    while (gap >= 1)
    {
        for (int i = 0; i < n; i += gap)
        {
            if (arr[i] > arr[i + gap] && i + gap < n)
            {
                swap(arr[i], arr[i + gap]);
                int j = i;
                while (arr[j] < arr[j - gap])
                {
                    swap(arr[j], arr[j - gap]);
                    j--;
                }
            }
        }
        gap /= 2;
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

    shell_sort(arr, n);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}