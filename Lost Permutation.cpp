#include <bits/stdc++.h>
using namespace std;
int t,m,s,k;
bool judge(int a[])
{
	int i=1;
	while(a[i]) i++;
	for(i;i<=1000;i++)
	if(a[i])
	return false;
    return true;
}
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>s;
		int f[1010]={0},j=1;
		for(int i=1;i<=m;i++)
		{
			cin>>k;
			f[k]++;
		}
		for(int i=1;;i++)
		{
			if(!f[i])
			{
				if(s>=i)
				{
					f[i]++;
					s-=i;
				}
				else
				break;
			}
		}
		if(s)
		cout<<"NO"<<endl;
		else
		{
			if(judge(f))
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
	return 0;
}