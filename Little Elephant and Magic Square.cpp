#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a[3][3];
    for (int i = 0; i < 3; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    ll x = (a[2][1] + a[1][2]) / 2;
    a[0][0] = x;
    a[1][1] = x + a[0][2] - a[2][1];
    a[2][2] = x + a[0][1] - a[1][2];

    for (int i = 0; i < 3; i++)
        cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
}