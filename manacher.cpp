#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm> 
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#include<sstream>
#include<time.h>
#define pi acos(-1)
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
const int maxn=5e5+10;
int p[maxn*2];
int sum[maxn];
void manacher(string str)
{
    int len=str.size();
    string s;
    s+="$#";
    for(int i=0;i<len;i++)
    {
        s+=str[i];
        s+='#';
    }
    int len2=s.size();
    memset(p,0,sizeof(p));
    int id=0,mx=0;
    for(int i=0;i<len2;i++)
    {
        if(i<mx) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(s[i+p[i]]==s[i-p[i]]) p[i]++;
        if(i+p[i]>mx)
        {
            id=i;
            mx=p[i]+i;
        }
    }
}
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
    	int book[27]={0};
        string str;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=26;i++)  scanf("%d",book+i);
        cin>>str;
        int len=str.size();
        sum[0]=book[1+str[0]-'a'];
        for(int i=1;i<len;i++)
        {
            sum[i]=sum[i-1]+book[1+str[i]-'a'];
        }
        manacher(str);
        int ans=-INF;
        for(int i=0;i<len-1;i++)//枚举分割点，[0,i]为左串，注意这里i<len-1
        {
            int temp=0;
            if(p[i+2]-1==i+1) temp+=sum[i];//前缀[0,i]是否是回文串，就看p[i+2]是否等于i+1，这里我的字符串从0开始，建议在草稿纸上算一下，
            if(p[i+2+len]-1==len-i-1) temp+=sum[len-1]-sum[i];//判断后缀[i+1,len-1]是否是回文串，同上建议
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
	}
    system("pause");
    return 0;
}