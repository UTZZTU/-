#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int>A;
A a[100010];
bool cmp(A e,A r)
{
if(e.first>r.first)return true;
if(e.first==r.first)
{
if(e.second<r.second)return true;
return false;
}
return false;
}
int main()
{
long  n;
cin>>n;
int Ar=0,Ag=0,Br=0,Bg=0;
for(long i=1;i<=n;i++)
{
int aa,bb;
cin>>aa>>bb;
a[i]={aa,bb};
}
sort(a+1,a+n+1,cmp);
for(long i=1;i<=n;i++)
{
if(i<=n/2)
{
if(a[i].second==0)Ar+=1;
if(a[i].second==1)Ag+=1;
}
if(i>n/2)
{
if(a[i].second==0)Br+=1;
if(a[i].second==1)Bg+=1;
}
}
cout<<Ar<<" "<<Ag<<endl;
cout<<Br<<" "<<Bg; 
}

