#include <iostream>
#include <vector>
using namespace std;

void bucket_sort(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    vector<vector<int>> vec;
    vec.resize(max + 1);

    for (int i = 0; i < max + 1; i++)
        vec[i].push_back(0);

    for (int i = 0; i < n; i++)
    {
        vec[arr[i]].push_back(arr[i]);
    }

    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (vec[i][1] != 0)
        {
            while (vec[i].size() > 1)
            {
                arr[j] = vec[i].back();
                vec[i].pop_back();
                j++;
            }
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

    bucket_sort(arr, n);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}