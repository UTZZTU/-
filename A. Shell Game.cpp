#include <bits/stdc++.h>
using namespace std;
int a[10],pos,x,y;
void solve()
{
	cin>>pos;
	a[pos]=1;
	for(int i=1;i<=3;i++)
	{
		cin>>x>>y;
		swap(a[x],a[y]);
	}
	if(a[1]) cout<<1<<endl;
	else if(a[2]) cout<<2<<endl;
	else cout<<3<<endl;
}
int main ()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}