#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int num1,num2,tt;
}s[200010];
bool cmp(node a,node b){
	return a.tt>b.tt;
}
ll n,k,res;
int main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&s[i].num1,&s[i].num2);
		s[i].tt=s[i].num2-s[i].num1;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(i<=k)
		res+=s[i].num2;
		else
		res+=s[i].num1;
	}
	cout<<res;
	return 0;
}