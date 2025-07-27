#include <bits/stdc++.h>
using namespace std;
struct node
{
	int pos,num;
}s[100];
//bool cmp(node x,node y)
//{
//	
//}
int n;
int get(int x)
{
	if(x==1) return 12;
	else if(x==2) return 9;
	else if(x==3) return 7;
	else if(x==4) return 5;
	else if(x==5) return 4;
	else if(x<=7) return 3;
	else if(x<=10) return 2;
	else if(x<=15) return 1;
	else return 0;
}
int main ()
{
	cin>>n;
	for(int i=1;i<=20;i++)
	{
		s[i].pos=i;
		s[i].num=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=20;j++)
		{
			int p,k;
			cin>>p>>k;
			s[j].num+=get(p)+k;
		}
	}
//	sort(s+1,s+1+20,cmp);
	for(int i=1;i<=20;i++)
	{
		cout<<s[i].pos<<" "<<s[i].num<<endl;
	}
	return 0;
}
