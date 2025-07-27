#include <bits/stdc++.h>
using namespace std;
int f[1000010],ans,js,maxx;
string u;
map<char,int> mp;
int main ()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='Z')
		{
			if(!mp.count(u[i]))
			{
				mp[u[i]]=i+1;
			}
			else
			{
				f[mp[u[i]]]++;
				f[i+2]--;
			}
		}
		else if(u[i]=='U')
		{
			if(mp.count('Z'))
			{
				f[mp['Z']]++;
				f[i+2]--;
			}
			if(!mp.count(u[i]))
			{
				mp[u[i]]=i+1;
			}
			else
			{
				f[mp[u[i]]]++;
				f[i+2]--;
			}
		}
		else if(u[i]=='L')
		{
			if(mp.count('Z'))
			{
				f[mp['Z']]++;
				f[i+2]--;
			}
			if(mp.count('U'))
			{
				f[mp['U']]++;
				f[i+2]--;
			}
			if(!mp.count(u[i]))
			{
				mp[u[i]]=i+1;
			}
			else
			{
				f[mp[u[i]]]++;
				f[i+2]--;
			}
		}
		else if(u[i]=='I')
		{
			if(mp.count('Z'))
			{
				f[mp['Z']]++;
				f[i+2]--;
			}
			if(mp.count('U'))
			{
				f[mp['U']]++;
				f[i+2]--;
			}
			if(mp.count('L'))
			{
				f[mp['L']]++;
				f[i+2]--;
			}
			if(!mp.count(u[i]))
			{
				mp[u[i]]=i+1;
			}
			else
			{
				f[mp[u[i]]]++;
				f[i+2]--;
			}
		}
	}
	for(int i=1;i<=u.size();i++)
	{
		ans+=f[i];
		if(ans!=0)
		js++;
		else
		{
			maxx=max(maxx,js);
			js=0;
		}
	}
	maxx=max(maxx,js);
	cout<<maxx<<endl;
	return 0;
}