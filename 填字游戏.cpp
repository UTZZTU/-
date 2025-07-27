\#include <cstdio>
#include <algorithm>
#include <cstring>
#define MX 1e9
#define MN -1e9
typedef long long int ll;
using namespace std;
struct NUM{                        //用结构体NUM中的数组来储存整数。
    char dit[30];
}num[11000];
bool cmp(NUM &a,NUM &b){                   //因为我太懒了，想用sort函数，所以写了个比较函数。
    if(strlen(a.dit)!=strlen(b.dit))
    return strlen(a.dit)< strlen(b.dit);
    else
        return strcmp(a.dit,b.dit)<0;
};
int main(){
    char t;
    ll r,c,i,j,lens,cnt=0;
    scanf("%lld %lld",&r,&c);
    for(i=1;i<=r;i++){
        lens=0;
        for(j=1;j<=c;j++){ 
            scanf(" %c",&t);    //scanf中格式控制符%c前加空格可以忽略回车等空白符。
            if(t=='#'){         //我在这里错了好多好多。 
                if(lens){       //接下来应该没什么好说的啦。
                    cnt++;
                    lens=0;
                }
            }
            else{
                num[cnt].dit[lens++]=t;
                num[cnt].dit[lens]='\0';
            }
        }
        if(lens)            
            cnt++;
    }
    sort(num,num+cnt,cmp);
    printf("%s",num[0].dit);
}
