#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Sieve(vector<bool> &sieve, ll n)
{
    sieve[0] = false;
    sieve[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j = j + i)
                sieve[j] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> sieve(1000001, true);
    Sieve(sieve, 1000000);

    ll n, ele;
    cin >> n;
    while (n)
    {
        cin >> ele;
        ll tmp = sqrt(ele);
        if (tmp * tmp == ele && sieve[tmp])
            cout << "YES\n";
        else
            cout << "NO\n";
        n--;
    }
}