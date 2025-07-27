#include <iostream>
using namespace std;
int a[1000010];
int n,m,k,s,w;
int find(int x)
{
	int r=x;
    while(r!=a[r]){
        r=a[r];
    }
    int i=x,j;
    while(i!=r){
        j=a[i];
        a[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
	int rx=find(x),ry=find(y);
	if(rx!=ry)
	a[ry]=rx;
}
int main ()
{
	int ans=1,sum=0;
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[ans]=ans;
			ans++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s>>w;
		join(s,w);
	}
	for(int i=1;i<ans;i++)
	{
		if(a[i]==i)
		sum++;
	}
	cout<<sum;
	return 0;
}