#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,k,l,counter=0;
	int found=0;
	char a[51][51];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{found=0;

				if(a[i][j]==a[i+1][j] && a[i][j]=='.')
					++found;
				 if(a[i][j]==a[i-1][j]&& a[i][j]=='.')
					++found;
				 if(a[i][j]==a[i][j-1]&& a[i][j]=='.')
					++found;
				 if(a[i][j]==a[i][j+1]&& a[i][j]=='.')
					++found;
				if(found<2)
                    {
                        a[i][j]='*';
                    }


		}
	}
	for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!='*')
                ++counter;
                cout<<a[i][j];
        }
        cout<<endl;
    }
    counter=sqrt(counter);
    cout<<(counter+1)/2;
}
