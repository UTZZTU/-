#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct listee
{
    int dz;
    int jz;
    int next;
}s[100010];
int main ()
{
    int ks,n,q,z,h,a[100010],b[100010],c[100010],j,i,zjz;
    cin>>ks>>n;
    vector<int> r1;
    memset(c,0,sizeof(c));
    while(n--)
    {
        cin>>q>>z>>h;
        s[q].dz=q;
        s[q].jz=z;
        s[q].next=h;
    }
    z=1;
    q=ks;
    while(1)
    {
        a[z]=s[q].jz;
        vector<int>::iterator it=find(r1.begin(),r1.end(),abs(s[q].jz));
        if(it!=r1.end())
            c[z]=-1;
        else
            r1.push_back(abs(s[q].jz));
        b[z]=q;
        if(s[q].next==-1)
            break;
        else
        {
            q=s[q].next;
            z++;
        }
    }
   for(i=1;i<=z;i++)
   {
   	if(c[i]==-1)
   	continue;
     if(c[i]!=-1)
     {
     	q=b[i];
     	zjz=a[i];
	 }
	 i++;
	 while(c[i]==-1&&i<=z)
	 i++;
	 if(i>z)
	 {
	 	printf("%05d %d -1\n",q,zjz);
	 }
	 else
	 {
	 	 h=b[i];
	 printf("%05d %d %05d\n",q,zjz,h);
	 }
	 i--;
   }
   for(i=1;i<=z;i++)
   {
   	if(c[i]!=-1)
   	continue;
     if(c[i]==-1)
     {
     	q=b[i];
     	zjz=a[i];
	 }
	 i++;
	 while(c[i]!=-1&&i<=z)
	 i++;
	 if(i>z)
	 {
	 	printf("%05d %d -1\n",q,zjz);
	 }
	 else
	 {
	 	 h=b[i];
	 printf("%05d %d %05d\n",q,zjz,h);
	 }
	 i--;
   }
    return 0;
}