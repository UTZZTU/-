#include <bits/stdc++.h>
using namespace std;
int x,pos;
int main ()
{
	scanf("%d",&x);
	pos=x;
	while(pos!=0)
	{
		x=x+1;
		pos&=x;
	}
	cout<<x;
	return 0;
}