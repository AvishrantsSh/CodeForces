#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int size = s.length();
    bool complete = false;
    for (int i = 0; i < size - 1; i++)
    {
        if ((s[i] - '0') % 2 == 0 && s[i] < s[size - 1])
        {
            char tmp = s[i];
            s[i] = s[size - 1];
            s[size - 1] = tmp;
            complete = true;
            break;
        }
    }
    for (int i = size - 1; !complete && i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            char tmp = s[i];
            s[i] = s[size - 1];
            s[size - 1] = tmp;
            complete = true;
            break;
        }
    }
    if (complete)
        cout << s << endl;
    else
        cout << -1 << endl;
}