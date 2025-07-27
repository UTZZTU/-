#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,k,w;
int main ()
{
	cin>>n>>m;
	getchar();
	cin>>s;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			w+=s[i];
		}
	}
	int pos=w.find(k);
	if(pos==-1)
	puts("NO");
	else
	puts("YES");
	return 0;
}