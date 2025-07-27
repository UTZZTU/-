#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
const int N = 2e5 + 10;
vector<pair<int,int> >a[N],b[N];
int n,m;

int check(int x,int y) {

	for(int i=0;i<n;i++) swap(b[i][x],b[i][y]);
	
	int flag = 0;
	for(int i=0;i<n;i++) {
		for(int j=1;j<m;j++) {
			if(b[i][j].first < b[i][j-1].first) {
				flag = 1;
				break;
			}
		}
		if(flag) break;
		
	}
	for(int i=0;i<n;i++) swap(b[i][x],b[i][y]);
	
	return flag;
}

int main(){
	int t;
	scanf("%d",&t);
	
	while(t --) {
		scanf("%d %d",&n,&m);
		
		for(int i=0;i<=n;i++) {
			a[i].clear();
			b[i].clear();
		}
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int c;
				scanf("%d",&c);
				a[i].push_back({c,j});
				b[i].push_back({c,j});
			}
		}
		
		for(int i=0;i<n;i++) sort(a[i].begin(),a[i].end());
		
		int x = -1,y = -1;
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(a[i][j].second != j) {
					if(x == -1) x = j;
					y = j;
				}
			}
		} 
		
		if(x == -1) printf("1 1\n");
		else if(check(x,y) == 0) printf("%d %d\n",x+1,y+1);
		else printf("-1\n");
	}
	
	return 0;
} 
