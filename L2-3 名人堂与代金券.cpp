#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int N, G, K;
struct P{
	char name[20];
	int score;
	bool operator <(const P&a)const &{
		if (score != a.score)
			return score > a.score;
		else
			return strcmp(name, a.name)<0;
	}
}s[10000+10];
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &N, &G, &K);
	for (int i = 0; i < N; i++)
		scanf("%s %d", s[i].name, &s[i].score);
	sort(s, s + N);
	int s60 = 0, sg = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].score >= G)
			sg++;
		else if (s[i].score >= 60)
			s60++;
		else break;
	}
	printf("%d\n", sg * 50 + s60 * 20);//重点处理方法
	int c = 1,ca=0;
	for (int i = 0; i < K; i++) {
		printf("%d %s %d\n", c, s[i].name, s[i].score);
		while (s[i + 1].score == s[i].score) {
			i++;
			printf("%d %s %d\n", c, s[i].name, s[i].score);
			ca++;
		}
		c++;//正常加一
		c += ca;//加上重复
		ca = 0;
	}
		
	return 0;
}