#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime(ll n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ll floor_square = (ll)sqrt(x);
        if (x == floor_square * floor_square && floor_square != 1 && isPrime(floor_square))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}