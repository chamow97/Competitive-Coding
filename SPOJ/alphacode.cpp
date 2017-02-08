//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main()
{
	
	while(1)
	{
		char str[10000];
		bool notPossible = false;
		cin>>str;
		ll len = strlen(str);
		ll arr[5011];
		arr[0] = 1;
		if(str[0] == '0')
		arr[1] = 0;
		else
			arr[1] = 1; 
		ll val=0;
		if(str[0] == '0' && len==1)
		{
			break;
		}
		// if(((ll(str[1-1] -48)*10)+ll(str[2-1] - 48))<=26 && str[0] != '0' && str[2] != '0' && str[1] != '0' )
		// {
		// 	arr[2] = 2;
		// }
		// else
		// {
		// 	arr[2] = 1;
		// }
		rep(i,2,len)
		{
			if(str[i-1] == '0' && str[i] == '0')
			{
				notPossible = true;
			break;		
			}
			if(str[i-1] == '0' && (ll(str[i-2] -48)*10)>20)
			{
				notPossible = true;
				break;
			}
			if(str[i-1] == '0' || str[i-2] == '0' || ((ll(str[i-2] -48)*10)+ll(str[i-1] - 48))>26 || str[i] == '0')
			{
				arr[i] = arr[i-1];
			}
			else
			{
				arr[i] = arr[i-2] + arr[i-1];
			}
		}
			if(str[len-1] == '0' && str[len] == '0')
			{
				notPossible = true;
				
			}
			if(str[len-1] == '0' && (ll(str[len-2] -48)*10)>20)
			{
				notPossible = true;
			}
				if(str[len-1] == '0' || ((ll(str[len-2] -48)*10)+ll(str[len-1] - 48))>26 || str[len-2] == '0')
		{
			arr[len] = arr[len-1];
		}
		else
		{
			arr[len] = arr[len-1] + arr[len-2];
		}

		
		if(notPossible == false)
		cout<<arr[len]<<'\n';
		else
		{
			cout<<"0\n";
		}
   	
	}
 return 0;	
}
