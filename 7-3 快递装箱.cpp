#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define sc(a) scanf("%lld",&a)
#define pf(a) printf("%d",a) 
#define endl "\n"
#define int long long
#define mem(a,b) memset(a,b,sizeof a)
#define ull unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(auto i=a;i<=b;++i)
#define bep(i,a,b) for(auto i=a;i>=b;--i)
#define LL long long 
#define lowbit(p) p&(-p)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PI acos(-1)
#define pb push_back
#define x first
#define y second
const double eps = 1e-6;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const int N = 1e4 + 10;
// deque<int> a, b, c, d;
queue<PII> a, b, c;
deque<PII> d1, d;
int n, m, w1, w2, wm;
int f1[N], f2[N];
int res1, res2;

signed main()
{
	// fast;
	cin >> n >> wm >> w1 >> w2;
	PII p;
	for(int i=1; i<=n; i++)
	{
	    while(d.size() >= 2) 
	    {
	        p = d.back();
	        d.pop_back();
	        d1.push_back(p);
	    }
	    
		if(c.size())
		{
			p = c.front();
			c.pop();
			if(!d.size()) 
			{
				d.push_front(p);
				f1[p.y] = 1;
			}
			else if(d.size())
			{
				PII q = d.front();
				d.pop_front();
				if(p.x + q.x <= wm && !f1[p.y]) d.push_front({p.x + q.x, q.y});
				else if((p.x + q.x > wm && !f1[p.y]) || f1[p.y])
				{
					if(q.x > w2) res2 ++;
					else d.push_back(q);
					d.push_front(p);
					f1[p.y] = 1;
				}
			}	
		}
		// else if(d.size() && i == n)
		// {
		// 	PII q = d.front();
		// 	d.pop_front();
		// 	if(q.x > w2) res2 ++;
		// 	else d1.push_back(q);
		// }

		if(b.size())
		{
			p = b.front();
			b.pop();
			if(p.x > w2) res1 ++;
			else c.push(p);
		}

		if(a.size())
		{
			p = a.front();
			a.pop();
			if(p.x > w1) f1[p.y] = 1;
			b.push(p);
		}
		
		cin >> m;

		if(d1.size()) 
		{
			p = d1.front();
			d1.pop_front();
			if(p.x + m <= wm) 
			{
				a.push({m + p.x, i});
				f1[i] = 1;
			}
			else
			{
				d1.push_front(p);
				a.push({m, i});
			}
		}
		else a.push({m, i});
		
// 		cout << "di.size(): " << d1.size() << endl;
	} 
	
	if(d.size())
	{
		p = d.front();
		d.pop_front();
		if(p.x > w2) res2 ++;
		else d.push_front(p);
	}
	
	vector<int> v;
	
	while(a.size())
	{
	    p = a.front();
	    v.push_back(p.x);
	    a.pop();
	   // cout << "!!!" << endl;
	}
    
    while(b.size())
	{
	    p = b.front();
	    v.push_back(p.x);
	    b.pop();
	   // cout << "!!!" << endl;
	}
	while(c.size())
	{
	    p = c.front();
	    v.push_back(p.x);
	    c.pop();
	   // cout << "!!!" << endl;
	}
	while(d.size())
	{
	    p = d.front();
	    v.push_back(p.x);
	    d.pop_front();
	   // cout << "!!!" << endl;
	}
	while(d1.size())
	{
	    p = d1.front();
	    v.push_back(p.x);
	    d1.pop_front();
	   // cout << "!!!" << endl;
	}
	
	sort(v.begin(), v.end());
	
	cout << res1 << " " << res2 << " " << v.size() << endl;
	
	if(v.size() == 0) puts("None");
	else
	{
		for(int i=0; i<v.size(); i++)
		{
		    cout << v[i];
		    if(i == v.size() - 1) cout << endl;
		    else cout << " ";
		}
	}
	
	return 0;
}
