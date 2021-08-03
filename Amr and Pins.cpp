#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll r, x, y, x2, y2, steps = 0;
    cin >> r >> x >> y >> x2 >> y2;
    ll dx = x2 - x, dy = y2 - y;
    double d = sqrt(dx * dx + dy * dy);
    steps = 0.5 * d / r;
    if (2 * steps * r != d)
        steps++;

    cout << steps;
}