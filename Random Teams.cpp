#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    ll iter = n / m;
    cout << m * iter * (iter - 1) / 2 + iter * (n % m) << " " << (n - m) * (n - m + 1) / 2;
}