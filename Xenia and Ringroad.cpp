#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    ll n, m, k, curr_pos = 1;
    cin >> n >> m;
    ll count = 0;

    while (m--)
    {
        cin >> k;
        count += (k >= curr_pos) ? k - curr_pos : n + k - curr_pos;
        curr_pos = k;
    }
    cout << count;
}