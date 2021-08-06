#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll teams;
    cin >> teams;
    ll dress[teams][2], dress_usage[teams][2];
    for (int i = 0; i < teams; i++)
    {
        cin >> dress[i][0] >> dress[i][1];
        dress_usage[i][0] = teams - 1;
    }

    for (ll i = 0; i < teams; i++)
    {
        for (ll k = i + 1; k < teams; k++)
        {
            if (dress[i][0] == dress[k][1])
                dress_usage[k][0]++;
            else
                dress_usage[k][1]++;

            if (dress[i][1] == dress[k][0])
                dress_usage[i][0]++;
            else
                dress_usage[i][1]++;
        }
    }
    for (ll i = 0; i < teams; i++)
    {
        for (ll j = 0; j < 2; j++)
            cout << dress_usage[i][j] << ' ';
        cout << '\n';
    }
}