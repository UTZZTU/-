#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+10;
typedef pair<int,int>PII;
PII a[maxn];
int n;
vector<int> multi(vector<int>a,int b) {
	vector<int> c;
	int t = 0;
	for(int i=0;i<a.size();i++) {
		t += a[i]*b;
		c.push_back(t%10);
		t/=10;
	}
	while(t) {
		c.push_back(t%10);
		t/=10;
	}
	return c;
}
vector<int> div(vector<int> a,int b) {
	vector<int> c;
	bool is_first = true;
	int t = 0;
	for(int i=a.size()-1;i>=0;i--) {
		t = t*10+a[i];
		int x = t/b;
		if(!is_first||x) {
			is_first = false;
			c.push_back(x);
		}
		t %= b;
	}
	reverse(c.begin(),c.end());//低位到高位存储 符合竖式计算的方法
	return c;
}
vector<int> getMax(vector<int> a,vector<int> b) {//取max函数 
	if(a.size()>b.size()) return a;
	if(a.size()<b.size()) return b;
	for(int i=a.size()-1;i>=0;i--) {
	    if(a[i]>b[i]) return a;
	    else if(b[i]>a[i]) return b;
	}
	return b;
}
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		a[i]={x*y,x};//将乘积与自己的左手存起，要右手的时候就除下就行了 
	}
	sort(a+1,a+1+n);//贪心策略：按照乘积从小到大排序 
	vector<int> ans(1,0);//存最后答案 初始为0 
	vector<int> mul(1,1);//存左手乘积 初始为1 
	for(int i=0;i<=n;i++) {
		if(i) ans = getMax(ans,div(mul,a[i].first/a[i].second));//除国王之外的取max
		mul = multi(mul,a[i].second);//累乘左手 
	}	
	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];cout<<endl;
} 
