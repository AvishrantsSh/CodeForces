/*
    https://codeforces.com/problemset/problem/451/B
*/
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll *arr = new ll[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll rev_count = 0;
    bool in_order = true;
    ll left = 0, right = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (rev_count > 1)
            break;

        if (arr[i] <= arr[i + 1])
        {
            in_order = true;
            continue;
        }
        else
        {
            if (in_order)
            {
                rev_count++;
                in_order = false;
                left = i, right = i + 1;
            }
            else
                right++;
        }
    }
    if (rev_count <= 1)
    {
        bool in_order = true;
        
        if (right < n - 1)
            if (arr[left] > arr[right + 1])
                in_order = false;
        
        if (left > 0)
            if (arr[left - 1] > arr[right])
                in_order = false;

        if (in_order)
            cout << "yes\n" << left + 1 << "  " << right + 1;
        else
            cout << "no";
    }
    else
        cout << "no";
}