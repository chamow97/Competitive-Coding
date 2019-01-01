#include<bits/stdc++.h>

using namespace std;

#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);

int n, k;
const int MAXN = 5e5 + 10;
vector<int> arr(MAXN, 0);
int lBound = 1, rBound = 1;
int currSize = 1;

void solve()
{
	if(n == 1)
	{
		lBound = rBound = 1;
		return;
	}
	map<int, int> m;
	set<int> s;
	int ptr1 = 1, ptr2 = 2;
	s.insert(arr[ptr1]);
	m[arr[ptr1]]++;
	s.insert(arr[ptr2]);
	m[arr[ptr2]]++;
	while(ptr1 <= ptr2 && ptr2 < n)
	{
		if(s.size() <= k)
		{
			if(currSize < (ptr2 - ptr1 + 1))
			{
				currSize = (ptr2 - ptr1 + 1);
				lBound = ptr1;
				rBound = ptr2;
			}
			++ptr2;
			m[arr[ptr2]]++;
			s.insert(arr[ptr2]);
		}
		else
		{
			m[arr[ptr1]]--;
			if(m[arr[ptr1]] == 0)
			{
				s.erase(s.find(arr[ptr1]));
			}
			ptr1++;
		}
	}
	if(currSize < (ptr2 - ptr1 + 1) && ptr2 <= n && s.size() <= k)
	{
		currSize = (ptr2 - ptr1 + 1);
		lBound = ptr1;
		rBound = ptr2;
	}
}

int main()
{
	fastread
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	solve();
	cout << lBound << ' ' << rBound;
	return 0;
}