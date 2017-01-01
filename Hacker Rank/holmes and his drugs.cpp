#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a[100000];
	long long pos,j,n,q,k,i,temp=1000000009,tempVal,repeat=0,repeated;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//sort( a.begin(), a.end() );
	//a.erase( unique( a.begin(), a.end() ), a.end() );
	sort(a,a+n);
	cin>>q;
	while(q--)
	{

		cin>>k;
		for(i==n-1;i>=0;i--)
		{
			repeat=0;
			if(a[i]==k)
			{
				for(j=i-1;j>=0;j--)
				{
					if(a[j]==a[i])
					{
						++repeat;
					}
					else
					{
						
						break;
					}
				}
				pos=i;
				repeated=repeat;
			}
		}
		tempVal=pow(2,pos+repeated);
		cout<<tempVal%temp<<endl;
		//if(pos==n-1)
		//{
	//		tempVal=pow(2,pos);
	//		cout<<tempVal%temp<<"\n";
	//	}
	//	else if(pos==0)
	//	{
	//		cout<<"1\n";
	/*	}
		else
		{
			tempVal=pow(2,pos);
			cout<<tempVal%temp<<"\n";
		}
	*/
	}
}