#include <bits/stdc++.h>
#define ll long long
using namespace std;

void clean_row(bool **&a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;
    bool b[m][n], a[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
            a[i][j] = 0;
        }

    bool flag = false, start = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j])
            {
                start = true;
                bool true_flag = true, col_complete = true, row_complete = true;
                for (int k = 0; k < m; k++)
                {
                    if (!b[k][j])
                    {
                        true_flag = false;
                        col_complete = false;
                        break;
                    }
                }

                for (int k = 0; k < n; k++)
                {
                    if (!b[i][k])
                    {
                        true_flag = false;
                        row_complete = false;
                        break;
                    }
                }

                if (true_flag)
                {
                    a[i][j] = 1;
                    flag = true;
                }

                if(!row_complete && !col_complete)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }

    if (start && !flag)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";

        cout << "\n";
    }
}