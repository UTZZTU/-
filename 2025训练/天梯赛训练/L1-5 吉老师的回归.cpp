#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int n,m,k;
string s[100];
void solve()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<endl;
		getline(cin,s[i]);
//		cout<<s[i]<<endl;
		if(s[i].find("qiandao")==-1&&s[i].find("easy")==-1)
		{
			k++;	
		}
	}
	
	if(k<=m) cout<<"Wo AK le";
	else
	{
		int p=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i].find("qiandao")==-1&&s[i].find("easy")==-1)
			{
				p++;
			}
			if(p==m+1)
			{
				cout<<s[i];
				break;
			}
		}	
	}
}
int main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}