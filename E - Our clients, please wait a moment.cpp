#include<iostream>
#include <queue>
using namespace std;
#define int long long
#define maxn 2000500
#define maxm 5000050
#define INF  0x3f3f3f3f3f3f3f

struct Edge
{
    int u,v,w,next;
}e1[maxm],e2[maxm];
int head1[maxn],cnt1,n,m,s1=1,vis1[maxn],dis1[maxn],a,b,c,f[1010][1010],head2[maxn],cnt2,s2,vis2[maxn],dis2[maxn],minn;
struct node
{
    int w,now;
    inline bool operator <(const node &x)const
    //閲嶈浇杩愮畻绗︽妸鏈€灏忕殑鍏冪礌鏀惧湪鍫嗛《锛堝ぇ鏍瑰爢锛?
    {
        return w>x.w;//杩欓噷娉ㄦ剰绗﹀彿瑕佷负'>'
    }
};
priority_queue<node>q1,q2;
//浼樺厛闃熷垪锛屽叾瀹炶繖閲屼竴鑸娇鐢ㄤ竴涓猵air锛屼絾涓轰簡鏂逛究鐞嗚В鎵€浠ョ敤鐨勭粨鏋勪綋
inline void add1(int u,int v,int w)
{
    e1[++cnt1].u=u;
    //杩欏彞璇濆浜庢棰樹笉闇€瑕侊紝浣嗗湪缂╃偣涔嬬被鐨勯棶棰樿繕鏄湁鐢ㄧ殑
    e1[cnt1].v=v;
    e1[cnt1].w=w;
    e1[cnt1].next=head1[u];
    //瀛樺偍璇ョ偣鐨勪笅涓€鏉¤竟
    head1[u]=cnt1;
    //鏇存柊鐩墠璇ョ偣鐨勬渶鍚庝竴鏉¤竟锛堝氨鏄繖涓€鏉¤竟锛?
}
inline void add2(int u,int v,int w)
{
    e2[++cnt2].u=u;
    //杩欏彞璇濆浜庢棰樹笉闇€瑕侊紝浣嗗湪缂╃偣涔嬬被鐨勯棶棰樿繕鏄湁鐢ㄧ殑
    e2[cnt2].v=v;
    e2[cnt2].w=w;
    e2[cnt2].next=head2[u];
    //瀛樺偍璇ョ偣鐨勪笅涓€鏉¤竟
    head2[u]=cnt2;
    //鏇存柊鐩墠璇ョ偣鐨勬渶鍚庝竴鏉¤竟锛堝氨鏄繖涓€鏉¤竟锛?
}
//閾惧紡鍓嶅悜鏄熷姞杈?
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        dis1[i]=INF;
        dis2[i]=INF;
    }
    dis1[s1]=0;
    dis2[s2]=0;
    //璧嬪垵鍊?
    q1.push((node){0,s1});
    q2.push((node){0,s2});
    while(!q1.empty())
    //鍫嗕负绌哄嵆涓烘墍鏈夌偣閮芥洿鏂?
    {
        node x=q1.top();
        q1.pop();
        int u=x.now;
//        cout<<u<<endl;
        //璁板綍鍫嗛《锛堝爢鍐呮渶灏忕殑杈癸級骞跺皢鍏跺脊鍑?
        if(vis1[u]) continue; 
        //娌℃湁閬嶅巻杩囨墠闇€瑕侀亶鍘?
        vis1[u]=1;
        for(int i=head1[u];i;i=e1[i].next)
        //鎼滅储鍫嗛《鎵€鏈夎繛杈?
        {
            int v=e1[i].v;
            if(dis1[v]>dis1[u]+e1[i].w)
            {
//            	cout<<u<<" "<<v<<endl;
            	dis1[v]=dis1[u]+e1[i].w;
            	//鏉惧紱鎿嶄綔
            	q1.push((node){dis1[v],v});
            	//鎶婃柊閬嶅巻鍒扮殑鐐瑰姞鍏ュ爢涓?
            }
        }
    }
    while(!q2.empty())
    //鍫嗕负绌哄嵆涓烘墍鏈夌偣閮芥洿鏂?
    {
        node x=q2.top();
        q2.pop();
        int u=x.now;
        //璁板綍鍫嗛《锛堝爢鍐呮渶灏忕殑杈癸級骞跺皢鍏跺脊鍑?
        if(vis2[u]) continue; 
        //娌℃湁閬嶅巻杩囨墠闇€瑕侀亶鍘?
        vis2[u]=1;
        for(int i=head2[u];i;i=e2[i].next)
        //鎼滅储鍫嗛《鎵€鏈夎繛杈?
        {
            int v=e2[i].v;
            if(dis2[v]>dis2[u]+e2[i].w)
            {
            	dis2[v]=dis2[u]+e2[i].w;
            	//鏉惧紱鎿嶄綔
            	q2.push((node){dis2[v],v});
            	//鎶婃柊閬嶅巻鍒扮殑鐐瑰姞鍏ュ爢涓?
            }
        }
    }
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
    s2=n;
//    for(int i=1,x,y,z;i<=m;i++)
//    {
//        x=read(),y=read(),z=read();
//        add(x,y,z);
//        add(y,x,z);
//    }
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&f[i][j]);
			if(i==j) continue;
			add1(i,j,f[i][j]*a);
//			add1(j,i,f[j][i]*a);
			add2(i,j,f[i][j]*b+c);
//			add2(j,i,f[j][i]*b+c);
		}
	}
    dijkstra();
    minn=0x3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        minn=min(minn,dis1[i]+dis2[i]);
//        printf("%lld %lld\n",dis1[i],dis2[i]);
    }
    cout<<minn;
    return 0;
}