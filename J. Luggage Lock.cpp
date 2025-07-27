#include<iostream>
#include<bits/stdc++.h>
#define csh(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long int ll;
const int N = 1E6 + 5;
 
int jy[10000];
bool book[10000];
struct Node{
	int d1, d2, d3, d4;
	int sum, cnt;
};
int mov[20][4] = {
	{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},
	{1,1,0,0},{0,1,1,0},{0,0,1,1},
	{1,1,1,0},{0,1,1,1},{1,1,1,1},
	{-1,0,0,0},{0,-1,0,0},{0,0,-1,0},{0,0,0,-1},
	{-1,-1,0,0},{0,-1,-1,0},{0,0,-1,-1},
	{-1,-1,-1,0},{0,-1,-1,-1},{-1,-1,-1,-1}
};
void bfs() {
	Node start{ 0,0,0,0,0,0 };
	jy[0] = 0;
	book[0] = 1;
	queue<Node>q;
	q.push(start);
	while (!q.empty()){
		Node top = q.front();
		q.pop();
		for (int i = 0; i < 20; i++) {
			int t1 = (top.d1 + mov[i][0] + 10) % 10;
			int t2 = (top.d2 + mov[i][1] + 10) % 10;
			int t3 = (top.d3 + mov[i][2] + 10) % 10;
			int t4 = (top.d4 + mov[i][3] + 10) % 10;
			int tsum = t1 * 1000 + t2 * 100 + t3 * 10 + t4;
			if (!book[tsum]) {
				book[tsum] = 1;
				jy[tsum] = top.cnt+1;
				q.push(Node{ t1,t2,t3,t4,tsum,top.cnt + 1 });
			}
		}
	}
}
int main() {
	bfs();
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int d0 = (a[0] - b[0] + 10) % 10;
		int d1 = (a[1] - b[1] + 10) % 10;
		int d2 = (a[2] - b[2] + 10) % 10;
		int d3 = (a[3] - b[3] + 10) % 10;
		int dsum = d0 * 1000 + d1 * 100 + d2 * 10 + d3;
		cout << jy[dsum] << endl;
	}
}
 