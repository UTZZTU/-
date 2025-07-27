#include <iostream>
using namespace std;
int n;
int dfs(int m,int n)
{
	if(m==1||n==1) 
	return 1;
    if(m<n) 
	return dfs(m,m);
    else if(m==n) 
	return 1+dfs(m,m-1);
    else 
	return dfs(m,n-1) + dfs(m-n,n);
}
int main ()
{
	while(cin>>n)
	{
		cout<<dfs(n,n)<<endl;
	}
	return 0;
}