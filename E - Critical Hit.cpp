#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int n,p,k=1;
double x,sum,tt;
void dfs(int n,double gl,int cz)
{
	if(n<1)
	{
		sum+=gl*cz;
		return;
	}
	else if(n==1)
	{
		sum+=gl*(cz+1);
		return;
	}
	else
	{
		dfs(n-2,gl*x,cz+1);
		dfs(n-1,gl*(1-x),cz+1);
	}
}
int main ()
{
	cin>>n>>p;
	x=p*1.0/100;
	dfs(n,1.0,0);
	cout<<sum;
	return 0;
}