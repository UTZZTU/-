#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string,string> mp1,mp2;
unordered_map<int,string> mp3;
unordered_map<string,int> mp4;
unordered_map<string,int> mp5;
int n,f[100010],flag=1;
string s,t;
bool judge(int x)
{
	int flag=1;
	string u=mp3[x];
	string v=mp1[u];
	if(!mp5[v])
	{
		return true;
	}
	while(1)
	{
		if(!mp5[v])
	    {
		    break;
	    }
		if(f[mp4[v]])
		{
			flag=0;
			break;
		}
		else
		{
			f[mp4[v]]=1;
			u=v;
			v=mp1[u];
			if(f[mp4[v]]&&mp4[u]<x)
			{
				break;
			}
		}
		
	}
	if(flag)
	return true;
	else
	return false;
}
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		mp3[i]=s;
		mp4[s]=i;
		mp5[s]=1;
		mp1[s]=t;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])
		continue;
		if(!judge(i))
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}