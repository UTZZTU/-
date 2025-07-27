#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"
using namespace std;
struct BK{
	int H,A,B,C,D,E,W,e;	
};//属性比较多，所以考虑用结构体，一个BK代表一个宝可梦 
int h,a,b,c,d,e,w,ee;
queue<BK> AA,BB;  //AA和BB 表示小A和小B   ps：比较形象 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);  //关流很重要，否则会超时 
	int n,m,k,cnt1 = 0, cnt2 = 0;
	cin>>n>>m>>k;
	while(n--){
		cin>>h>>a>>b>>c>>d>>e>>w;
		BK x ;
		x.H = h, x.A = a, x.B = b, x.C = c, x.D = d, x.E = e, x.W = w, x.e = 0;
		AA.push(x);
		
	} //把小A的宝可梦载入 
	while(m--){
		cin>>h>>a>>b>>c>>d>>e>>w;
		BK x;
		x.H = h, x.A = a, x.B = b, x.C = c, x.D = d, x.E = e, x.W = w, x.e= 0;
		BB.push(x);
		
	}  //把小B的宝可梦载入 
			BK aa = AA.front();
			BK bb = BB.front();			
			k *= 2;
			long long count = 0;   //aa是攻击方，bb是被攻击方 
		while(!AA.empty() && !BB.empty() && k > 0){	//攻击过程，结束条件是某一个人的宝可梦死光或者局数用完	 
				long long hit,  p, q;
				p = aa.A - bb.C >  0? aa.A - bb.C :0;
				q = aa.B - bb.D >  0? aa.B - bb.D :0;
				hit = max(p, q);
				if(aa.W > hit && aa.e >=  aa.E) hit = aa.W, aa.e -= aa.E;
				if(hit == p || hit == q) aa.e ++;	//模拟攻击，找伤害，一定注意是实际伤害最大的，别忘了能量的变化			 
				bb.H -= hit;
								
			    AA.push(aa);
			    AA.pop(); 
			    aa = AA.front(); //攻击方换发 
									                  
				if(bb.H <= 0)
				{
					BB.pop();
					bb = BB.front();//被攻击方死了才能换下一个				 	
				}
				swap(aa,bb);
				swap(AA,BB); //A和B换发 
				count ++;
				k--;			 
			}
		if(k >= 0 && !AA.empty() && !BB.empty()) cout<<"Draw"<<endl; //没死光就是平局						
		else if(count % 2 == 0) cout<<"Bob"<<endl;    //总是A是单数攻击，B是双数攻击，所以看结束的时候的攻击局数就可以判断谁赢了 
		else if(count % 2 == 1) cout<<"Alice"<<endl;
	return 0;
	}
	