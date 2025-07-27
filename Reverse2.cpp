#include <bits/stdc++.h>
using namespace std;
int n,q,l,r,num;
string s;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') continue;
		num++;
		int j=i;
		while(j<n&&s[j]=='1') j++;
		j--;
		i=j;
	}
	while(q--)
	{
		cin>>l>>r;
		l--,r--;
		int pp=0;
		if(s[l]=='1')
		{
			if(l-1>=0&&s[l-1]=='1') pp++;
			if(r+1<n&&s[r+1]=='1') pp--;
		}
		if(s[r]=='1')
		{
			if(l-1>=0&&s[l-1]=='1') pp--;
			if(r+1<n&&s[r+1]=='1') pp++;
		}
		cout<<num+pp<<endl;
	}
	return 0;
}