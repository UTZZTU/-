#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int nu[N];
void test(){
	string s[2];cin >> s[0] >> s[1];
	queue<pair<int,int>> qu;
	int t,q;cin >> t >> q;
	int no = 0;
	int num = 0,block = 0;//一样的数量,阻塞的数量
	int n = s[0].size();
	for(int i = 1;i <= n;i++)
		nu[i] = 0;
	s[0] = ' ' + s[0];
	s[1] = ' ' + s[1];
	for(int i = 1;i <= n;i++)
		if(s[0][i] == s[1][i])
			num++;
	while(q--){
		no++;
		if(!qu.empty() && qu.front().first + t <= no){
			nu[qu.front().second]--;
			if(!nu[qu.front().second]){
				block--;
				if(s[0][qu.front().second] == s[1][qu.front().second])
					num++;	
			}
			qu.pop();
		}
		int op;cin >> op;
		if(op == 1){
			int pos;cin >> pos;
			if(s[0][pos] == s[1][pos])
				num--;
			qu.push({no,pos});
			if(!nu[pos])
				block++;
			nu[pos]++;
		}else if(op == 2){
			int aim1,pos1,aim2,pos2;
			cin >> aim1 >> pos1 >> aim2 >> pos2;
			aim1--;
			aim2--;
			if(s[aim1][pos1] == s[1 - aim1][pos1])
				num--;
			if(s[aim2][pos2] == s[1 - aim2][pos2])
				num--;
			swap(s[aim1][pos1],s[aim2][pos2]);
			if(s[aim1][pos1] == s[1 - aim1][pos1])
				num++;
			if(s[aim2][pos2] == s[1 - aim2][pos2])
				num++;
		}else{
			if(num + block == n)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}
#undef int
int main()
{
	int t = 1;cin >> t;
	while(t--){
		test();
	}
}
