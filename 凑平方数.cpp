
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<10;
vector<int> nums;//存放符合条件的平方数
int ans;

void check(long long x){
    int status = 0;//记录数字的状态，初始时全标记为0
    if(x==0) status = 1;//对于0要特殊处理一下，他的二进制表示应该是0000000001，标记最低位即第0位为1
    while(x){//如果x不是0 
        //获取十进制个位上的数，1移位到对应位置后再与上一次的状态做与运算
        //如果运算结果不为0说明个位上的数字之前已经被使用过，这个平方数不合要求，不记录
        if((status & (1 << (x%10) ) ) != 0 ) return;
        
        status |=(1<<(x%10));//或运算标记本次出现的数对应位置置为1
        x/=10;//循环直至记录所有位 
    } 
    //经历过上面的while循环后没有执行return，说明这个数没有重复的单个数字，将状态添加到vector中 
    nums.push_back(status);
}

void dfs(int x,int y){
    //从第x个合法的数字往后取，当前的组合状态为y
    if(y == (1<<10) - 1){
        //1左移10位然后-1得到的结果就是二进制的1111111111 
        //y==1111111111说明组合数可行，刚好每个位都出现了一次，记录答案
        ans++; 
        return;
    } 
    for(int i = x;i < nums.size(); i++){//将位置i的平方数与它后面的每一个数进行判断 
        if((nums[i]&y)==0) dfs(i+1,nums[i]|y);//如果二者的与结果为0，说明二者没有相同的数字，可以组合，dfs去找下一个数字 
    }
} 

int main(){
    for(long long i = 0 ; i<=100000; i++ ){//平方数，用check检查一遍 
        check(i*i); 
    }
    dfs(0,0);//dfs从0开始，初始状态为0000000000，去搜寻可行结果 
    cout<<ans<<endl;
    return 0; 
} 