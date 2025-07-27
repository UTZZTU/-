#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res=0,x;
double s1,s2,s3,s4,s;
int main ()
{
	cin>>s;
	x=s*100000000;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			for(int m=0;m<=100;m++)
			{
				for(int n=0;n<=100;n++)
				{
					if(i*j*m*n==x)
					res++;
//					if(i*j*m*n>s)
//					break;
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}