#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    unordered_map<string, string> hash_map;

    for (ll i = 0; i < m; i++)
    {
        string lang1, lang2;
        cin >> lang1 >> lang2;
        hash_map[lang1] = lang2;
    }
    string res = "";
    for (ll i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        res += (hash_map[word].length() < word.length()) ? hash_map[word] : word;
        if (i != n - 1)
            res += ' ';
    };
    cout << res;
}