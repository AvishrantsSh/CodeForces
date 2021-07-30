Merge Sort
----------
One of the fastest and most efficient sorting algorithm for a majority of sorting problems.

```c++
void merge_sort(ll *arr, ll size)
{
    if (size <= 1)
        return;

    // Merge sort left and right side
    ll mid = size / 2;
    ll *left = arr;
    ll *right = arr + mid;
    ll *temp = new ll[size];

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    ll i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid)
    {
        if (left[i] < right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }
    while (i < mid)
        temp[k++] = left[i++];

    while (j < size - mid)
        temp[k++] = right[j++];

    for (i = 0; i < size; i++)
        arr[i] = temp[i];
}
```