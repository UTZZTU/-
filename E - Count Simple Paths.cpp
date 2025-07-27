#include <iostream>
#include <vector>
using namespace std;
int n,m,visited[200010],x,y,res;
vector<int> vec[200010];
void dfs(int num)
{
	if(res>1000000)
	return;
	for(int i=0;i<vec[num].size();i++)
	{
		int j=vec[num][i];
		if(visited[j])
		continue;
		res++;
		visited[j]=1;
		dfs(j);
		visited[j]=0;
	}
	return;
}
int main ()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	visited[1]=1;
	res=1;
	dfs(1);
	cout<<min(res,1000000);
	return 0;
}