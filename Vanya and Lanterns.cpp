#include <iostream>
#include <iomanip>
#define ll long long
using namespace std;

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, l;
    cin >> n >> l;
    ll *arr = new ll[n];

    ll index = 0;
    while (n - index)
        cin >> arr[index++];

    merge_sort(arr, n);

    ll max_dist = 2 * arr[0];
    for (ll i = 1; i < n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) > max_dist)
            max_dist = abs(arr[i] - arr[i - 1]);
    }

    if (max_dist < 2 * (l - arr[n - 1]))
        max_dist = 2 * (l - arr[n - 1]);

    cout << fixed << setprecision(9) << double(max_dist)/2;
}