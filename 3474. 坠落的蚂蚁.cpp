#include <bits/stdc++.h>
using namespace std;
const int N = 100;
struct ant
{
	int id,pos,st;
	bool operator <(const ant &x)const
	{
		return pos<x.pos;
	}
}before[N],after[N];
int order[N],n;
int main ()
{
	int id;
	const int T = 1e4;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&before[i].pos,&before[i].st);
		before[i].id=i;
		after[i]={0,before[i].pos+T*before[i].st,before[i].st};
		if(before[i].st==0)
		id=i;
	}
	sort(before,before+n);
	for(int i=0;i<n;i++)
	order[before[i].id]=i;
	sort(after,after+n);
	id=order[id];
	if (after[id].pos < 100 and after[id].pos > 0) cout << "Cannot fall!";
  else {
    if (after[id].st == 1) cout << T - (after[id].pos - 100);
    else cout << T - (0 - after[id].pos);
  }
  return 0;
}