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
    ll t;
    t = readInt();
    while(t--)
    {
        char str[1000001];
	cin>>str;
	ll i,j,k,len = strlen(str);
	i = 0;
	j = len-1;

        bool isPalin = false;
        for(i=0;i<len/2;i++)
        {
            if(str[i] == str[len-1-i])
            {
                isPalin = true;
            }
            else
            {
                isPalin = false;
                break;
            }
        }
        if(isPalin == false)
        {
            while(i < j)
	{
		if(str[i] >= str[j])
		{
			i++;
			j--;
		}
		else
		{
			str[j] = '0';
			k = j-1;
			while(str[k] == '9' && k>i)
			{
				str[k] = '0';
				k--;
			}
			str[k]++;
			i += (j-k);
			j = len-1-i;
		}
	}

        }
        else
        {
            while(i < j)
	{
		if(str[i] > str[j])
		{
			i++;
			j--;
		}
		else
		{
			str[j] = '0';
			k = j-1;
			while(str[k] == '9' && k>i)
			{
				str[k] = '0';
				k--;
			}
			str[k]++;
			i += (j-k);
			j = len-1-i;
		}
	}

        }

	for(i=0; i<len/2; i++)
    {

        str[len-1-i] = str[i];
    }
	cout<<str;
	cout<<endl;

    }


    return 0;
}
