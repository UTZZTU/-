#include <bits/stdc++.h>
using namespace std;
string s,t,u,v;
int n,m,res1,res2;
int main ()
{
	cin>>s>>t;
	n=s.size(),m=t.size();
	for(int i=0;i<n;i++)
	{
		u+=s[i];
		if(i+1>=m&&u.substr((i+1)-m,m)==t) res1++;
	}
	s+=s;
	for(int i=0;i<2*n;i++)
	{
		v+=s[i];
		if(i+1>=m&&v.substr((i+1)-m,m)==t) res2++;
	}
	printf("%d\n",res2-res1);
	return 0;
}