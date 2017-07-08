//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */
bool ones(string &str)
{
	ll len = str.length();
	per(i,len-1,0)
	{
		ll temp = (str[i] - '0');
		if(temp == 1 || temp == 4 || temp == 7)
		{
			str[i] = '$';
			if(len == 1)
			{
				return false;
			}
			return true;
		}

	}
	return false;
}

bool twos(string &str)
{
	ll len = str.length();
	per(i,len-1,0)
	{
		ll temp = (str[i] - '0');
		if(temp == 2 || temp == 5 || temp == 8)
		{
			str[i] = '$';
			if(len == 1)
			{
				return false;
			}
			return true;
		}

	}

}
void removezeroes(string &str)
{
		ll pos = 0;
		while(str[pos] == '0' || str[pos] == '$')
		{
			str[pos] = '$';
			++pos;
		}

}

int main()
{
//	string str;
//	ll sum = 0, dollar = 0;
//	cin>>str;
//	ll len = str.length();
//	rep(i,0,len)
//	{
//		sum += (str[i] - '0');
//	}
//	if(sum % 3 == 0)
//	{
//		cout<<str;
//		return 0;
//	}
//	else if(sum % 3 == 1)
//	{
//		if(ones(str) == true)
//		{
//			removezeroes(str);
//		}
//		else
//		{
//			cout<<-1;
//			return 0;
//		}
//
//	}
//	else
//	{
//		if(ones(str) == true && len > 2)
//	{
//		if(ones(str) == true)
//		{
//			return true;
//		}
//		return false;
//	}
//	return false;
//		if(twos(str) == true)
//		{
//			removezeroes(str);
//		}
//		else
//		{
//			cout<<-1;
//			return 0;
//		}
//	}
//	rep(i,0,len)
//	{
//		if(str[i] == '$')
//		{
//			++dollar;
//		}
//	}
//	if(dollar == len)
//	{
//		cout<<0;
//	}
//	else
//	{
//		rep(i,0,len)
//		{
//			if(str[i] != '$')
//			{
//				cout<<str[i];
//			}
//		}
//	}
cout<<"Ceil of 1.2 is : "<<ceil(1.2)<<endl;

cout<<"Ceil of 2 is : "<<ceil(2)<<endl;

cout<<"Ceil of 1.0 is : "<<ceil(1.0)<<endl;

cout<<"Ceil of -1.2 is : "<<ceil(-1.2)<<endl;

cout<<"Ceil of -1.0 is : "<<ceil(-1.0)<<endl;

cout<<"Ceil of -3 is : "<<ceil(-3)<<endl;

	return 0;
}
