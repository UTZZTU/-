#include <iostream>
#include <algorithm>
using namespace std;
int n,f[110];
string s[110];
struct node
{
	int pos,win;
}u[110];
bool cmp(node x,node y)
{
	if(x.win!=y.win) return x.win>y.win;
	else return x.pos<y.pos; 
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		u[i].pos=i;
		u[i].win=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
//		u[i].pos=i;
//		int res=0;
		for(int j=0;j<n;j++)
		{
			if(s[i][j]=='o') u[i].win++;
//			else if(s[i][j]=='x') u[j+1].win++;
		}
//		u[i].win=res;
	}
	sort(u+1,u+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
//		f[u[i].pos]=i;
//		cout<<u[i].pos<<" "<<u[i].win<<endl;
		printf("%d ",u[i].pos);
	}
//	for(int i=1;i<=n;i++) printf("%d ",f[i]);
	return 0;
}