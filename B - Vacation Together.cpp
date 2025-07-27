#include <iostream>
using namespace std;
int n,d,f[110],res,maxx;
string s[110];
int main ()
{
	cin>>n>>d;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<d;j++)
		{
			if(s[i][j]=='o')
			{
				f[j+1]++;
			}
		}
	}
	for(int i=1;i<=d;i++)
	{
		if(f[i]==n) res++;
		else
		{
			maxx=max(maxx,res);
			res=0;
		}
	}
	maxx=max(maxx,res);
	cout<<maxx;
	return 0;
}