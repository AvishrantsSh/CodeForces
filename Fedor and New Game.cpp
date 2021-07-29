#include <iostream>
#define ll long long

using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    /*
        11 : 1011

        1011 & 1010 = 1010
        1010 & 1000 = 1000
        1000 & 0000 = 0000
    */
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, count = 0;
    cin >> n >> m >> k;

    int *arr = new int[++m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    int ref = arr[m - 1];
    for (int i = 0; i < m - 1; i++)
    {
        if(countSetBits(arr[i] ^ ref) <= k)
            count++;
    }
    cout << count;
}