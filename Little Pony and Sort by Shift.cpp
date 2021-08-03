#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll size, shift = 0, prev = INT_MIN, first = INT_MIN;
    ll order_shift = 0;
    cin >> size;
    while (size)
    {
        ll tmp;
        cin >> tmp;
        if (size == 1 && tmp > first && order_shift == 1)
        {
            cout << -1;
            return 0;
        }

        if (first == INT_MIN)
            first = tmp;

        if (prev <= tmp)
        {
            if (order_shift == 1)
                shift++;
        }

        else
        {
            if (tmp > first)
            {
                cout << -1;
                return 0;
            }
            order_shift++;
            shift++;
        }

        if (order_shift == 2)
        {
            cout << -1;
            return 0;
        }

        size--;
        prev = tmp;
    }
    cout << shift;
}