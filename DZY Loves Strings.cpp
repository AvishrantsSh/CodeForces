#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    ll k;
    cin >> s >> k;
    ll ans = 0, max = INT_MIN;
    vector<ll> weight(26, 0);

    ll size = s.length();
    for (int i = 0; i < 26; i++)
    {
        cin >> weight[i];
        if (weight[i] > max)
            max = weight[i];
    }

    for (ll i = 0; i < size; i++)
        ans += (i + 1) * weight[s[i] - 'a'];

    ans += max * k * (2 * size + k + 1) / 2;
    cout << ans;
}