#include <bits/stdc++.h>
using namespace std;
string s1[1010],s2[1010];
int k1=1,k2=1,f[1050][1050];
int main ()
{
	string a,b,f1,f2;
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			if(i==0)
			f1+=a[i];
			else
			{
				s1[k1++]=f1;
				f1.clear();
				f1+=a[i];
			}
		}
		else
		f1+=a[i];
	}
	s1[k1++]=f1;
	f1.clear();
	for(int i=0;i<b.size();i++)
	{
		if(b[i]>='A'&&b[i]<='Z')
		{
			if(i==0)
			f2+=b[i];
			else
			{
				s2[k2++]=f2;
				f2.clear();
				f2+=b[i];
			}
		}
		else
		f2+=b[i];
	}
	s2[k2++]=f2;
	f2.clear();
	for(int i=1;i<k1;i++)
	{
		for(int j=1;j<k2;j++)
		{
			if(s1[i]==s2[j])
			f[i][j]=f[i-1][j-1]+1;
			else
			f[i][j]=max(f[i][j-1],f[i-1][j]);
		}
	}
	cout<<f[k1-1][k2-1];
	return 0;
}