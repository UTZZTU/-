#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int pre[100010];
int find(int x)
{
    int i=1;
    while(pre[x]!=x)
    {
        x=pre[x];
        i++;
    }
    return i;
}
int main ()
{
    int n,i,max=0,k,q=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>k;
        if(k==-1)
            pre[i]=i;
        else
        pre[i]=k;
    }
    for(i=1;i<=n;i++)
    {
        if(find(i)>max)
            max=find(i);
    }
    for(i=1;i<=n;i++)
    {
    	if(find(i)==max)
    	printf("%d ",i);
	}
    return 0;
}