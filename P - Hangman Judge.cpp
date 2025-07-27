#include<stdio.h>
#include<string.h>
#define maxn 100000
 
int main()
	{
		int n;
		char s[maxn], a[maxn];
		int lens, lena;
		int guessed[30]; //初始为0 当其值为1时 代表 这个已经猜对了
		int i, j;
		int is_lose, is_win;
//		freopen("C:\\Users\\zhangwei\\Desktop\\input.txt","r",stdin); 
//		freopen("C:\\Users\\zhangwei\\Desktop\\output.txt","w",stdout); 
		while(scanf("%d",&n) == 1 && n != -1){
			scanf("%s",s);
			scanf("%s",a); 
			lens = strlen(s);
			lena = strlen(a);
			i = 0;
			j = 0;
			is_lose = 0;
			is_win = 1;
			memset(guessed, 0, sizeof(guessed));
			int cnt_false = 0;  //统计错误次数
			while(j < lena){
				for(i = 0; i < lens; i++ ){
					if(!guessed[a[j]-'a'] && a[j] == s[i]){//以a[]数组为判断核心
						guessed[a[j]-'a'] = 1;
						break;
					}
					else if(guessed[a[j]-'a']){
						cnt_false++;
						break;
					}
				}
				if(i == lens)//当 猜到末尾仍然没有发现猜对时 就是 猜错了
					cnt_false++;
				if(cnt_false >= 7){
					is_lose = 1;
					break; 
				}	
				j++;
			}
			for(int i = 0; i < lens; i++ ){//判断 答案中的字符是否全部被猜对
				if(guessed[s[i]-'a'] != 1){
					is_win = 0;
					break;
				}
			}
			printf("Round %d\n",n);
			if(is_win == 0 && is_lose == 0)
				printf("You chickened out.\n");
			else if(is_win){
				printf("You win.\n");
			}
			else if(is_lose){
				printf("You lose.\n");
			}	 
			
		}
		
		return 0;		
	}
