#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, s, t;
    cin >> n >> s >> t;
    ll ref[n], tmp = s, valid = n;
    vector<bool> move(n, false);

    for (auto &it : ref)
        cin >> it;

    move[s - 1] = true;
    while (!move[t - 1] && valid > 0)
    {
        tmp = ref[tmp - 1];
        move[tmp - 1] = true;
        valid--;
    }

    if (valid < 1)
    {
        cout << -1;
        return 0;
    }

    cout << n - valid;
}