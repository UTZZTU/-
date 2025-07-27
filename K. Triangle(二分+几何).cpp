#include<cstdio>
#include<iostream>
#include<queue>//妈的绝了
#include<cmath>
using namespace std;
int ax,ay,bx,by,cx,cy,dx,dy;
int mxm(int a,int b){
	return a>b?a:b;
}
int mim(int a,int b){
	return a<b?a:b;
}
double dis(double x1,double y1,double x2,double y2){
	return sqrt(   (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)    );
}
double crs(double x1,double y1,double x2,double y2){
	return x1*y2-y1*x2;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    	if((ay-by)*(dx-bx)==(dy-by)*(ax-bx)){//在ab边上 
    		int mxx=mxm(ax,bx),mix=mim(ax,bx);
    		int mxy=mxm(ay,by),miy=mim(ay,by);
    		double aax,aay,bbx,bby,ccx,ccy,ddx,ddy;
    		aax=(double)ax;
    		aay=(double)ay;
    		bbx=(double)bx;
    		bby=(double)by;
    		ccx=(double)cx;
    		ccy=(double)cy;
    		ddx=(double)dx;
    		ddy=(double)dy;
    		if((dy-ay)*(bx-ax)!=(by-ay)*(dx-ax)){
    			printf("-1\n");
    			continue;
			}
			if(dy>mxy||dx>mxx||dx<mix||dy<miy){
				printf("-1\n");
    			continue;
			}
			if(dx==ax&&dy==ay){
				printf("%.12f %.12f\n",(bbx+ccx)/2.0,(bby+ccy)/2.0);
				continue;
			}
			if(dx==bx&&dy==by){
				printf("%.12f %.12f\n",(aax+ccx)/2.0,(aay+ccy)/2.0);
				continue;
			}
			double ad=dis(ax,ay,dx,dy);
			double ab=dis(ax,ay,bx,by);
			double bd=dis(dx,dy,bx,by);
			double ac=dis(ax,ay,cx,cy);
			double bc=dis(bx,by,cx,cy);
			double acx=ax-cx,acy=ay-cy;
			double bcx=bx-cx,bcy=by-cy;
			double area=fabs(crs(acx,acy,bcx,bcy));//平行四边形面积 
			if(ad<ab/2.0){
				double abc=asin(fabs(crs(acx,acy,bcx,bcy)/(ab*bc)));
				double hhh=(area/2.0)/bd;
				double be=hhh/(sin(abc));
				double ex,ey;
				ex=(be/bc)*(cx-bx)+bx;
				ey=(be/bc)*(cy-by)+by;
				printf("%.12f %.12f\n",ex,ey);
				continue;
			}
			else{
				double cab=asin(fabs(crs(acx,acy,bcx,bcy)/(ab*ac)));
				double hhh=(area/2.0)/ad;
				double ae=hhh/sin(cab);
				double ex,ey;
				ex=(ae/ac)*(cx-ax)+ax;
				ey=(ae/ac)*(cy-ay)+ay;
				printf("%.12f %.12f\n",ex,ey);
			}
		}
		else if((ay-cy)*(dx-cx)==(dy-cy)*(ax-cx)){//ac
    		int mxx=mxm(ax,cx),mix=mim(ax,cx);
    		int mxy=mxm(ay,cy),miy=mim(ay,cy);
    		double aax,aay,bbx,bby,ccx,ccy,ddx,ddy;
    		aax=(double)ax;
    		aay=(double)ay;
    		bbx=(double)bx;
    		bby=(double)by;
    		ccx=(double)cx;
    		ccy=(double)cy;
    		ddx=(double)dx;
    		ddy=(double)dy;
    		if((dy-ay)*(cx-ax)!=(cy-ay)*(dx-ax)){
    			printf("-1\n");
    			continue;
			}
			if(dy>mxy||dx>mxx||dx<mix||dy<miy){
				printf("-1\n");
    			continue;
			}
			if(dx==ax&&dy==ay){
				printf("%.12f %.12f\n",(bbx+ccx)/2.0,(bby+ccy)/2.0);
				continue;
			}
			if(dx==cx&&dy==cy){
				printf("%.12f %.12f\n",(aax+bbx)/2.0,(aay+bby)/2.0);
				continue;
			}
			double ad=dis(ax,ay,dx,dy);
			double ac=dis(ax,ay,cx,cy);
			double cd=dis(dx,dy,cx,cy);
			double ab=dis(ax,ay,bx,by);
			double cb=dis(bx,by,cx,cy);
			double acx=ax-cx,acy=ay-cy;
			double bcx=bx-cx,bcy=by-cy;
			double area=fabs(crs(acx,acy,bcx,bcy));//平行四边形面积 
			if(ad<ac/2.0){
				double acb=asin(fabs(crs(acx,acy,bcx,bcy)/(ac*cb)));
				double hhh=(area/2.0)/cd;
				double ce=hhh/(sin(acb));
				double ex,ey;
				ex=(ce/cb)*(bx-cx)+cx;
				ey=(ce/cb)*(by-cy)+cy;
				printf("%.12f %.12f\n",ex,ey);
				continue;
			}
			else{
				double cab=asin(fabs(crs(acx,acy,bcx,bcy)/(ab*ac)));
				double hhh=(area/2.0)/ad;
				double ae=hhh/sin(cab);
				double ex,ey;
				ex=(ae/ab)*(bx-ax)+ax;
				ey=(ae/ab)*(by-ay)+ay;
				printf("%.12f %.12f\n",ex,ey);
				continue;
			}
		}
		else if((by-cy)*(dx-cx)==(dy-cy)*(bx-cx)){//bc
    		int mxx=mxm(cx,bx),mix=mim(cx,bx);
    		int mxy=mxm(cy,by),miy=mim(cy,by);
    		double aax,aay,bbx,bby,ccx,ccy,ddx,ddy;
    		aax=(double)ax;
    		aay=(double)ay;
    		bbx=(double)bx;
    		bby=(double)by;
    		ccx=(double)cx;
    		ccy=(double)cy;
    		ddx=(double)dx;
    		ddy=(double)dy;
    		if((dy-by)*(cx-bx)!=(cy-by)*(dx-bx)){
    			printf("-1\n");
    			continue;
			}
			if(dy>mxy||dx>mxx||dx<mix||dy<miy){
				printf("-1\n");
    			continue;
			}
			if(dx==bx&&dy==by){
				printf("%.12f %.12f\n",(aax+ccx)/2.0,(aay+ccy)/2.0);
				continue;
			}
			if(dx==cx&&dy==cy){
				printf("%.12f %.12f\n",(aax+bbx)/2.0,(aay+bby)/2.0);
				continue;
			}
			double bd=dis(bx,by,dx,dy);
			double bc=dis(bx,by,cx,cy);
			double cd=dis(dx,dy,cx,cy);
			double ba=dis(bx,by,ax,ay);
			double ca=dis(cx,cy,ax,ay);
			double bax=bx-ax,bay=by-ay;
			double cax=cx-ax,cay=cy-ay;
			double area=fabs(crs(bax,bay,cax,cay));//平行四边形面积 
			if(bd<bc/2.0){
				double bca=asin(fabs(crs(bax,bay,cax,cay)/(bc*ca)));
				double hhh=(area/2.0)/cd;
				double ce=hhh/(sin(bca));
				double ex,ey;
				ex=(ce/ca)*(ax-cx)+cx;
				ey=(ce/ca)*(ay-cy)+cy;
				printf("%.12f %.12f\n",ex,ey);
				continue;
			}
			else{
				double abc=asin(fabs(crs(bax,bay,cax,cay)/(bc*ba)));
				double hhh=(area/2.0)/bd;
				double be=hhh/sin(abc);
				double ex,ey;
				ex=(be/ba)*(ax-bx)+bx;
				ey=(be/ba)*(ay-by)+by;
				printf("%.12f %.12f\n",ex,ey);
				continue;
			}
		}
		else printf("-1\n");
	}
    return 0;
}
