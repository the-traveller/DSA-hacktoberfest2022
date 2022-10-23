// Heap Sort

// Best case O(n log n)
// Worst case O(n log n)
// Average case O(n log n)

// In-place : Yes
// Stable : No

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;

    // Calculating left and right Child
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    for (int i = n; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
     int arr[] = {5, 6, 1, 7, 3, 8, 45, 96, 12};
    print_array(arr, 9);
    HeapSort(arr, 9);
    print_array(arr, 9);
}