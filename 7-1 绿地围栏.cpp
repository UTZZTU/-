#include <bits/stdc++.h>
using namespace std;
int n,l,tt[1010],x,y,res;
int main ()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tt[i]);
	}
	printf("0 0\n");
//	for(int i=1;i<=n;i++)
//	{
//		if(i&1)
//		{
//			if(tt[i]-y>0)
//			{
//				if(abs(tt[i]-y)+res>=l)
//				{
//					int xz=abs(tt[i]-y)-(l-res);
//					if(x==0&&y+(l-res)==0) break;
//					printf("%d %d\n",x,y+(l-res));
//					res=0;
//					for(int j=1;j<=xz/l;j++)
//					{
//						if(x==0&&y+1==0) break;
//						printf("%d %d\n",x,y+l);
//						y+=l;
//					}
//					res=xz%l;
//					y=tt[i];
//				}
//				else
//				{
//					res+=abs(tt[i]-y);
//					y=tt[i];
//				}
//			}
//			else if(tt[i]-y<0)
//			{
//				if(abs(tt[i]-y)+res>=l)
//				{
//					int xz=abs(tt[i]-y)-(l-res);
//					if(x==0&&y-(l-res)==0) break;
//					printf("%d %d\n",x,y-(l-res));
//					res=0;
//					for(int j=1;j<=xz/l;j++)
//					{
//						if(x==0&&y-l==0) break;
//						printf("%d %d\n",x,y-l);
//						y-=l;
//					}
//					res=xz%l;
//					y=tt[i];
//				}
//				else
//				{
//					res+=abs(tt[i]-y);
//					y=tt[i];
//				}
//			}
//		}
//		else
//		{
//			if(tt[i]-x>0)
//			{
//				if(abs(tt[i]-x)+res>=l)
//				{
//					int xz=abs(tt[i]-x)-(l-res);
//					if(x+(l-res)==0&&y==0) break;
//					printf("%d %d\n",x+(l-res),y);
//					res=0;
//					for(int j=1;j<=xz/l;j++)
//					{
//						if(x+l==0&&y==0) break;
//						printf("%d %d\n",x+l,y);
//						x+=l;
//					}
//					res=xz%l;
//					x=tt[i];
//				}
//				else
//				{
//					res+=abs(tt[i]-x);
//					x=tt[i];
//				}
//			}
//			else if(tt[i]-x<0)
//			{
//				if(abs(tt[i]-x)+res>=l)
//				{
//					int xz=abs(tt[i]-x)-(l-res);
//					if(x-(l-res)==0&&y==0) break;
//					printf("%d %d\n",x-(l-res),y);
//					res=0;
//					for(int j=1;j<=xz/l;j++)
//					{
//						if(x-l==0&&y==0) break;
//						printf("%d %d\n",x-l,y);
//						x-=l;
//					}
//					res=xz%l;
//					x=tt[i];
//				}
//				else
//				{
//					res+=abs(tt[i]-x);
//					x=tt[i];
//				}
//			}
//		}
//	}
    for(int i=1;i<=n;i++)
    {
    	if(i&1)
    	{
    		if(tt[i]-y>0)
    		{
    			int sz=tt[i]-y;
    			for(int j=1;j<=sz;j++)
    			{
    				res++;
    				y++;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
			else
			{
				int sz=abs(tt[i]-y);
				for(int j=1;j<=sz;j++)
    			{
    				res++;
    				y--;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
		}
		else
		{
			int sz=tt[i]-x;
			if(tt[i]-x>0)
    		{
    			for(int j=1;j<=sz;j++)
    			{
    				res++;
    				x++;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
			else
			{
				int sz=abs(tt[i]-x);
				for(int j=1;j<=sz;j++)
    			{
    				res++;
    				x--;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
		}
	}
	if(x!=0)
	{
		    
			if(0-x>0)
    		{
			    int sz=-x;
    			for(int j=1;j<=sz;j++)
    			{
    				res++;
    				x++;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
			else
			{
				int sz=abs(-x);
				for(int j=1;j<=sz;j++)
    			{
    				res++;
    				x--;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
	}
	if(y!=0)
	{
		if(0-y>0)
    		{
    			int sz=0-y;
    			for(int j=1;j<=sz;j++)
    			{
    				res++;
    				y++;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
			else
			{
				int sz=abs(-y);
				for(int j=1;j<=sz;j++)
    			{
    				res++;
    				y--;
    				if(res==l&&!(x==0&&y==0))
    				{
    					printf("%d %d\n",x,y);
					}
					res%=l;
				}
			}
	}
	return 0;
}