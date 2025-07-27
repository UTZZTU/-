#include <bits/stdc++.h>
using namespace std;
int f[15],n,res;
string s;
bool judge()
{
	for(int i=2;i<=n;i++)
	{
		if(f[i]==f[i-1]) return false;
	}
	return true;
}
int main ()
{
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
	{
		f[i]=s[i-1]-'a';
	}
	sort(f+1,f+1+n);
	do
	{
		if(judge()) res++;
	}while(next_permutation(f+1,f+1+n));
	cout<<res;
	return 0;
}