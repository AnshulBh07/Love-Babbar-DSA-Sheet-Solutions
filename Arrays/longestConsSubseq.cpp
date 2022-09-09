#include <iostream>
#include <algorithm>
using namespace std;

int findLongestConseqSubseq(int *arr, int n)
{
    sort(arr, arr + n);
    int count = 1, i = 0;
    int maxi = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + 1 == arr[i + 1])
        {
            count++;
            maxi = max(maxi, count);
        }
        else if (arr[i] == arr[i + 1])
        {
            continue;
        }
        else
        {
            count = 1;
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findLongestConseqSubseq(arr, n);
    return 0;
}