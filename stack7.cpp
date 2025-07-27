#include<cstdio> 
#include<cstring> 
#include<queue>
#include<deque>
#include<vector>
#include<string>
 
using namespace std;
 
#define MAXN (100000)
 
struct CMD{
	int x,y;
};//x为操作行为编号，y为操作数。
//x 0-25：变量赋值，对应着a-z；此时y为常量；
//x 26：print操作；此时y为被操作变量；
//x 27：lock；此时y没有作用；
//x 28：unlock；此时y没有作用。
//x 29：end;此时y没有作用。 
 
int var[26];//26个变量。
vector<CMD> pro[MAXN];//各个程序的指令。
int place[MAXN];//程序下次进入unit应该执行的指令。
bool islock;//变量是否被锁。 
int who;//谁锁的 
queue<int> block;//阻塞队列 
deque<int> wait;//等待队列 
int n,T;
int t[6];
 
void exe(int ID){
	int tt=T;
	while(tt>0){
		int xx=pro[ID][place[ID]].x,yy=pro[ID][place[ID]].y;
		if(0<=xx&&xx<=25){
			var[xx]=yy;
			tt-=t[1];
		}else if(xx==26){
			printf("%d: %d\n",ID+1,var[yy]);
			tt-=t[2];
		}else if(xx==27){
			if(islock){
				block.push(ID);
				return ;
			} 
			islock=true;
			who=ID;
			tt-=t[3];
		}else if(xx==28){
			islock=false;
			if(!block.empty()){
				wait.push_front(block.front());
				block.pop();
			}
			tt-=t[4];
		}else if(xx==29){
			return ;
		}
		place[ID]++;
	}
	wait.push_back(ID);
}
 
void CLR(){
	memset(var,0,sizeof(var));
	memset(place,0,sizeof(place));
	for(int i=0;i<n;i++)pro[i].clear();
	islock=false;
	who=-1;
	while(!block.empty())block.pop();
	wait.clear();
}
 
void read_pro(int ID){
	char s[10];
	for(int i=0;i<10;i++)s[i]=' ';
	while(scanf("%s",s)){
		if(s[2]=='d'){
			pro[ID].push_back((CMD){29,0});
			break;
		}
		else if(s[2]=='i'){
			scanf("%s",s);
			pro[ID].push_back((CMD){26,s[0]-'a'});
		}
		else if(s[2]=='c')pro[ID].push_back((CMD){27,0});
		else if(s[2]=='l')pro[ID].push_back((CMD){28,0});
		else{
			int x=s[0]-'a';
			scanf("%s",s);
			int y;
			scanf("%d",&y);
			pro[ID].push_back((CMD){x,y});
		}
		for(int i=0;i<10;i++)s[i]=' ';
	}
}
 
int main(){
//freopen("in.txt","r",stdin);
	int total;
	scanf("%d",&total);
	while(total--){
		CLR();
		scanf("%d%d%d%d%d%d%d",&n,&t[1],&t[2],&t[3],&t[4],&t[5],&T);
		for(int i=0;i<n;i++){
			read_pro(i);
			wait.push_back(i);
		}
		while(!wait.empty()){
			int ID=wait.front();
			wait.pop_front();
			//cout<<ID<<endl;
			exe(ID);
		}
		if(total)printf("\n");
	}
//fclose(stdin);
	return 0;
}