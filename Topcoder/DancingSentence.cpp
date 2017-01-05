#include<bits/stdc++.h>
using namespace std;

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
class DancingSentence
{
public:
	string makeDancing(string sentence)
	{
		string temp;
		int it=1;
		rep(i,0,sentence.length())
		{
			if(sentence[i] != ' ')
			{
				if(it==1 && sentence[i]>=65 && sentence[i]<=90)
				{
					it *= (-1);
					temp[i] = sentence[i] + 32;
				}
				else if(it==-1 && sentence[i]>=97 && sentence[i]<=122)
				{
					it *= (-1);
					temp[i] = sentence[i] - 32;
				}
				else
				{
					temp[i] = sentence[i];			
				}
			}
			else
			{
				temp[i] = sentence[i];
			}

		}
		return temp;
	}

};