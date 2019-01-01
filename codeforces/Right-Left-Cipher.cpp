#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cin >> str;
	string ans = "";
	int ptr1 = 0, ptr2 = str.length() - 1;
	while(ptr1 <= ptr2)
	{
		string curr = "";
		if(str.length() % 2 == 0)
		{
			curr += str[ptr1++];
			if(ptr2 >= ptr1)
			{
				curr += str[ptr2--];
			}		
		}
		else
		{
			curr += str[ptr2--];
			if(ptr1 <= ptr2)
			{
				curr += str[ptr1++];
			}
		}
		ans = curr + ans;
	}
	cout << ans;
	return 0;
}