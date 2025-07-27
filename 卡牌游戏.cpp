#include <bits/stdc++.h>
using namespace std;
int sum1,sum2,n;
string a="Jin",b="Mu",c="Shui",d="Huo",e="Tu",u,v;
int main ()
{
	cin>>n;
	getchar();
	while(n--)
	{
		cin>>u>>v;
		if(u==a)
		{
			if(v==b)
			sum1+=3;
			else if(v==d)
			sum2+=3;
		}
		else if(u==b)
		{
			if(v==e)
			sum1+=3;
			else if(v==a)
			sum2+=3;
		}
		else if(u==c)
		{
			if(v==d)
			sum1+=3;
			else if(v==e)
			sum2+=3;
		}
		else if(u==d)
		{
			if(v==a)
			sum1+=3;
			else if(v==c)
			sum2+=3;
		}else
		{
			if(v==c)
			sum1+=3;
			else if(v==b)
			sum2+=3;
		}
	}
	if(sum1>sum2)
	cout<<"Alice";
	else if(sum1<sum2)
	cout<<"Bob";
	else
	cout<<"Draw";
	return 0;
}