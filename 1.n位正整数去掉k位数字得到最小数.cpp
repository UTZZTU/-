//全CSDN最菜。GitHub:Catigeart
#include<cstdio>
#include<cstring>
#include<cstdlib>
 
#define MAXN 1000000
#define LOSERN 30//log2(10^8)<27
 
using namespace std;
 
typedef struct N{
    char data;//数位值，用char存放不影响比较
    int loserPos[LOSERN];//败者列表
    int lpLen;//败者信息长度
}N;
 
N n[MAXN];
char ans[MAXN];
int np, ap;//num point & ans point
int k;
int player[MAXN+1];//锦标赛数组
 
int cmp(int nPosA, int nPosB);
void compete(int head, int rear ,int minArr[]);
 
int main()
{
    //初始化
//    printf("Please input n:");
    char c;
    scanf("%c", &c);
    int nLen = 0;
    while(c != '\n')
    {
        n[nLen].data = c;
        nLen++;
        scanf("%c", &c);
    }
    nLen++;
    if(n[0].data=='-' || (nLen==1 && n[0].data=='0'))
    {//非法输入n
        printf("n isn't a positive integer!\n");
        return 0;
    }
//    printf("Please input k:");
    scanf("%d",&k);
    if(nLen <= k)
    {//非法输入k
        printf("No enough number !\n");
        return 0;
    }
    int minPosArr[2] = {MAXN+1,MAXN+1};//minPos,2ndMinPos.MAXN+1表示空
    int deleteNum;//删除数量
    int head=0, rear=k;//搜索区域的头尾
    while(k!=0 && nLen-np>k)
    {
        compete(head, rear, minPosArr);
        deleteNum = minPosArr[0]-np;
        k -= deleteNum;//k值更新
        np = minPosArr[0]+1;//np移动
        ans[ap] = n[minPosArr[0]].data;//传值到ans数组
        ap++;//ap移动
        //若上一轮有已搜索信息向本轮传递，则裁剪区域
        if(minPosArr[1] != MAXN+1)
            head = rear+1;//cut
        else//如果==MAXN+1，即无第二小信息
            head = np;
        rear = np+k;
    }
    if(nLen-np <= k)//已不能再保留新数，按算法不会发生<情况，仅鲁棒写法
        np = nLen;//移动np到末尾，等同直接删去
    while(n[np].data != 0)
    {//如果删完了仍然有剩余数位，直接保留
        ans[ap] = n[np].data;
        ap++;
        np++;
    }
    ap = 0;//重置ap
    //前导零的特殊处理
    if(ans[ap] == '0')
    {
        printf("(");
        while(ans[ap] == '0')
        {
            printf("%c",ans[ap]);
            ap++;
        }
        printf(")");
    }
    while(ans[ap])
    {
        printf("%c",ans[ap]);
        ap++;
    }
    printf("\n");
    system("pause");
    return 0;
}
 
int cmp(int nPosA, int nPosB)
{//锦标赛算法比较函数
    int smallPos, bigPos;
    if(n[nPosA].data<n[nPosB].data || (n[nPosA].data==n[nPosB].data && nPosA<nPosB))
    {//左胜出
        smallPos = nPosA;
        bigPos = nPosB;
    }
    else
    {//右胜出
        smallPos = nPosB;
        bigPos = nPosA;
    }
    n[smallPos].loserPos[n[smallPos].lpLen] = bigPos;
    n[smallPos].lpLen++;
    return smallPos;
}
 
void compete(int head, int rear, int minPosArr[])
{//锦标赛算法
    int len = rear-head+1;
    int i, tmp = len-1;
    for(i=head; i<=rear; i++,tmp--)
        player[tmp] = i;//逆序输入（无特别用意）
    int add = 1;
    int pos1st;
 
    while(2*add <= len)
    {//设置左方为胜者
        for(i=0; i+add<len; i+=2*add)
            player[i] = cmp(player[i], player[i+add]);
        if(i < len)//奇数
            player[0] = cmp(player[0], player[i]);
        add *= 2;
    }
    if(minPosArr[1] != MAXN+1)//上一轮存在求出的第二小
        player[0] = cmp(player[0], minPosArr[1]);
    pos1st = player[0];
    //找第二小
    int pos2nd = MAXN+1;
    char data2nd = '9'+1;
    int rightPos[LOSERN+1];//pos1st经筛选的右方败者列表
    memset(rightPos, 0, sizeof(rightPos));
    int rightLen = 0;
    for(i=0; i<n[pos1st].lpLen; i++)
    {
        if(n[pos1st].loserPos[i] <= pos1st)
            continue;//位置合法性判断
        else
        {
            rightPos[rightLen] = n[pos1st].loserPos[i];
            rightLen++;
        }
        if(n[n[pos1st].loserPos[i]].data<data2nd || (n[n[pos1st].loserPos[i]].data==data2nd && pos2nd>n[pos1st].loserPos[i]))
        {//若更小或等值但位置位于当前值的左方
            pos2nd = n[pos1st].loserPos[i];
            data2nd = n[n[pos1st].loserPos[i]].data;
        }
    }//pos2nd可能== MAXN+1(没有发生比较)
    if(pos2nd != MAXN+1)
    {//把pos1st的败者记录附加到pos2nd中向下一轮传递
        for(i=0; i<rightLen; i++)
        {
            n[pos2nd].loserPos[n[pos2nd].lpLen] = rightPos[i];
            n[pos2nd].lpLen++;
        }
    }
    minPosArr[0] = pos1st;
    minPosArr[1] = pos2nd;
}