#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int lcs(string X, string Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[m][n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int l1 = a.length();
    int l2 = b.length();
    if (l1 == l2)
    {
        bool flag = true;
        vector<int> arr(26, 0);
        for (int i = 0; i < l1; i++)
        {
            arr[a[i] - 'a']++;
        }
        for (int i = 0; i < l2; i++)
        {
            arr[b[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
                flag = false;
        }
        if (flag == true)
        {
            cout << "array";
            return 0;
        }
    }

    if (l1 != l2)
    {
        int length = lcs(a, b, l1, l2);
        if (length == l2)
        {
            cout << "automaton";
            return 0;
        }
    }

    if (l1 != l2)
    {
        bool flag = true;
        vector<int> arr(26, 0);
        for (int i = 0; i < l1; i++)
        {
            arr[a[i] - 'a']++;
        }
        for (int i = 0; i < l2; i++)
        {
            arr[b[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] < 0)
                flag = false;
        }
        if (flag == true)
        {
            cout << "both";
            return 0;
        }
    }
    cout << "need tree" << endl;
    return 0;
}