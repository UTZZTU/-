#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
	inline bool operator <(const node &u)const
	{
		return x+y>u.x+u.y;
	}
};
priority_queue<node>p;
int main ()
{
	p.push((node){9,8});
	p.push((node){1,9});
	p.push((node){4,6});
	p.push((node){0,0});
	p.push((node){10,10});
	while(!p.empty())
	{
		node u=p.top();
		p.pop();
		cout<<u.x<<" "<<u.y<<endl;
	}
	return 0;
}