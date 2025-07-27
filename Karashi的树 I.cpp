#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[300010],k,res,pos;
vector<int> vec[300010];
priority_queue<int> q;
int dfs(int level,int num){
	for(int i=0;i<vec[level].size();i++)
	{
		num+=dfs(vec[level][i],1);
	}
	q.push(num);
	return num;
}
int main ()
{
	scanf("%lld",&n);
	pos=n;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		vec[k].push_back(i);
	}
	dfs(1,1);
	while(!q.empty())
	{
		res+=a[pos]*q.top();
		q.pop();
		pos--;
	}
	cout<<res;
	return 0;
}
