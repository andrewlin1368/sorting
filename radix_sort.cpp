#include <iostream>
#include <vector>
using namespace std;

void radix_sort(int *arr, int n)
{
    vector<vector<int>> vec;
    vec.resize(10);

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    string str = to_string(max);
    int counter = 0;
    int mod = 1;
    while (counter < str.length())
    {
        for (int i = 0; i < n; i++)
        {
            int arr_loc;
            if (arr[i] / mod == 0)
            {
                arr_loc = 0;
            }
            else
            {
                arr_loc = (arr[i] / mod) % 10;
            }
            vec[arr_loc].push_back(arr[i]);
        }

        int arr_counter = 0;
        for (int i = 0; i < 10; i++)
        {
            if (!vec[i].empty())
            {
                for (int j = 0; j < vec[i].size(); j++)
                {
                    arr[arr_counter] = vec[i][j];
                    arr_counter++;
                }
                while (!vec[i].empty())
                    vec[i].pop_back();
            }
        }
        mod *= 10;
        counter++;
    }
}

int main()
{
    int arr[16] = {211, 113, 24, 1, 566, 5, 211, 153, 892, 71, 468, 1532, 756, 958, 113, 45};
    int n = 16;

    cout << "Before: ";
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";

    radix_sort(arr, n);

    cout << "After: ";
    for (auto x : arr)
        cout << x << " ";

    return 0;
}