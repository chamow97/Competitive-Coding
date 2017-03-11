#include <iostream>
using namespace std;

int main() {
    int m,s,temp1,temp2;
    cin>>m>>s;
    char small[101], high[101];
    int i;//loop var
    //code to find the smallest number 
    //storing m
    temp1 = s;
    temp2 = s;
    //ignoring case with large sum
    if( s>(9*m) || (s==0 && m>1))
    {
        cout<<"-1 -1";
    }
    else
    {
        //to find the smallest
        temp1 -= 1; // to take care of zeroes
        for(i=m-1;i>=0;i--)
        {
            if(temp1-9 >= 0)
            {
                small[i] = '9';
                temp1 -= 9;
            }
            else
            {
                small[i] = char(temp1+48);
                temp1 = 0;
            }
           
        }
        small[0] = char(small[0]+1);//1st digit shld be atleast 1
        small[m] = '\0';
        //to find largest
        for(i=0;i<m;i++)
        {
            if(temp2-9 >= 0)
            {
                high[i] = '9';
                temp2 -= 9;
            }
            else
            {
                high[i] = char(temp2+48);
                temp2 = 0;
            }
        }
        high[m] = '\0';
        cout<<small<<" "<<high;
    }
    
    
	return 0;
}