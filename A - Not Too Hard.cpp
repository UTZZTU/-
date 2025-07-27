#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,x,k,res;
int main ()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		if(k<=x) res+=k;
	}
	cout<<res;
	return 0;
}