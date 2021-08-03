#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll to_find, ref[3];
	cin >> ref[0] >> ref[1] >> to_find;
	ref[2] = ref[1] - ref[0];
	
	ll ans = (((to_find - 1) / 3) % 2 == 0) ? ref[(to_find - 1) % 3] : -ref[(to_find - 1) % 3];
	if (ans < 0)
	{
		while (ans < 0)
			ans += 1000000007;
		cout << ans;
	}
	else
		cout << ans % 1000000007;
}