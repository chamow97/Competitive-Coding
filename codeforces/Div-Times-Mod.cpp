#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = INT_MAX;

	for(int i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			int j = n / i;
			int x = k * i + j;
			if((x % k) * (x / k) == n)
			{
				ans = min(ans, x);
			}
		}
	}
	cout << ans;
	return 0;
}
