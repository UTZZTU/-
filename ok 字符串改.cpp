#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios::sync_with_stdio(false),cin.tie(0);
string s;
int n,t;
int main()
{
	ios;
	cin>>n>>t; 
	cin>>s;
	int x=0,y=0,j=0,sum=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o') x++;
		if(s[i]=='k') y++;
		while(t<x&&t<y)
		{
			if(s[j++]=='o') 
			{
				x--;
			}
			else y--; 
		}
		sum=max(sum,x+y);
	}
	cout<<sum<<endl;
	return 0;
}