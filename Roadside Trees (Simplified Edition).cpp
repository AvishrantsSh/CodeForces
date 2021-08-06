#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, tmp, prev = 0, total = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> tmp;
        total += abs(tmp - prev) + 1;
        prev = tmp;
    }
    cout << --total + n;
}