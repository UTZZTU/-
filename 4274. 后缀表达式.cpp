#include <bits/stdc++.h>
using namespace std;
int l[25],r[25],f[25],n;
string s[25];
string g(int n)
{
	if(l[n]==-1&&r[n]==-1)
	return "("+s[n]+")";
	if(l[n]==-1&&r[n])
	return "("+s[n]+g(r[n])+")";
	return  "("+g(l[n])+g(r[n])+s[n]+")";
}
int main ()
{
	cin>>n;
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>l[i]>>r[i];
		if(l[i]) f[l[i]]=1;
		if(r[i]) f[r[i]]=1;
	}
	int x=1;
	while(f[x]) x++;
	cout<<g(x);
	return 0;
}