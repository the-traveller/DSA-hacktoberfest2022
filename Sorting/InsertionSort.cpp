// Insertion Sort

// Best case O(n)
// Worst case O(n*2)
// Average case O(n*2)

// In-place : Yes
// Stable : No

#include <iostream>
using namespace std;

void Insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main()
{
    int arr[] = {67, 45, 32, 98, 54, 69};
    Insertionsort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}