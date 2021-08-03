The following lines at the beginning of the code make input and output more efficient
```c++
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
```

- How to set decimal precision
	```c++
		#include<iomanip>
		/*...*/
		
		std::cout << fixed << setprecision(8) << number;
	```

Template structure (work in progress)
```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
```