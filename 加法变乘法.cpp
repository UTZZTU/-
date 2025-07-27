#include <bits/stdc++.h>
using namespace std;
bool check(int x,int y)
{
	if(1225-x-x-1-y-y-1+x*(x+1)+y*(y+1)==2015)
	return true;
	return false;
}
int main ()
{
	for(int i=1;i<=48;i++)
	{
		for(int j=i+2;j<=48;j++)
		{
			if(check(i,j))
			{
				cout<<i<<endl;
			}
		}
	}
	return 0;
}