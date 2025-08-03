#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define next Next
// 顶点的可选的颜色
int degree[10010];
 
// 顶点选择的颜色
int color[10010];
 
// 图，next[i]代表和i相邻的节点 
vector<int> next[10010];
 
// 顶点个数，边个数
int n, m;
 
int k;
 
int main()
{
	int count = 0;
	while(scanf("%d %d", &n, &m) == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			next[i] = vector<int>();
			color[i] = 0;
			degree[i] = 0;
		}
 
		int max_degree = 0;		
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			degree[x]++;
			degree[y]++;
			next[x].push_back(y);
			next[y].push_back(x);
			int t_max = max(degree[x],degree[y]);	
			max_degree = t_max > max_degree ? t_max : max_degree;		
		}
		if(max_degree % 2 == 0)
			k = max_degree+1;
		else
			k = max_degree;
 
		
		for(int i = 1; i <= n; i++)					
			degree[i] = k-degree[i];
	
		// 依次为可选颜色最小的顶点选定颜色
		for(int i = 1; i <= n; i++)
		{
			int p;
			int min_degree = 20000;
			for(int j = 1; j <= n; j++)
			{
				if(color[j] == 0 && min_degree > degree[j])
				{
					min_degree = degree[j];
					p = j;
				}
			}
 
			// 根据该点的相邻点已选的颜色来确定该点的颜色
			int not_color[10010];
			for(int j = 1; j <= k; j++)
				not_color[j] = 0;
		
			for(int j = 0; j < next[p].size(); j++)
			{
				if(color[next[p][j]] != 0)
				{
					not_color[color[next[p][j]]] = 1;
				}
			}		
			for(int j = 1; j <= k; j++)
			{
				if(not_color[j] == 0)
				{
					color[p] = j;
					break;
				}
			}	
 
			// 更新该点相邻点可选的颜色数目
			for(int j = 0; j < next[p].size(); j++)
			{
				if(color[next[p][j]] == 0)
				{
					degree[next[p][j]]--;
				}
			}
	
		}
 
		// 输出
		if(count > 0)
			printf("\n");
		printf("%d\n", k);		
		for(int i = 1; i <= n; i++)
			printf("%d\n", color[i]);
		count++;	
	}		
	return 0;
}