\#include <cstdio>
#include <algorithm>
#include <cstring>
#define MX 1e9
#define MN -1e9
typedef long long int ll;
using namespace std;
struct NUM{                        //�ýṹ��NUM�е�����������������
    char dit[30];
}num[11000];
bool cmp(NUM &a,NUM &b){                   //��Ϊ��̫���ˣ�����sort����������д�˸��ȽϺ�����
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
            scanf(" %c",&t);    //scanf�и�ʽ���Ʒ�%cǰ�ӿո���Ժ��Իس��ȿհ׷���
            if(t=='#'){         //����������˺ö�öࡣ 
                if(lens){       //������Ӧ��ûʲô��˵������
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
