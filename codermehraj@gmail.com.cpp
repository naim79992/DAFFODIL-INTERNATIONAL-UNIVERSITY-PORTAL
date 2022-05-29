//codermehraj@gmail.com
#include <bits/stdc++.h>
using namespace std;

typedef struct point{
	int x,y;
};

point ar[4],final[4];
int bahu_a,bahu_b,bahu_c,bahu_d,korno_ac,korno_bd;

int area(point a, point b, point c, point d){
	int plus, minus;
	plus=(a.x*b.y)+(b.x*c.y)+(c.x*d.y)+(d.x*a.y);
	minus=(b.x*a.y)+(c.x*b.y)+(d.x*c.y)+(a.x*d.y);
	return plus-minus;
}

void khela_shuru(){
	for(int i=0;i<4;i++){ 		cin>>ar[i].x>>ar[i].y;
	}
	if(area(ar[0],ar[1],ar[2],ar[3])!=0){
		final[0]=ar[0];
		final[1]=ar[1];
		final[2]=ar[2];
		final[3]=ar[3];
	}
	else if(area(ar[0],ar[1],ar[3],ar[2])!=0){
		final[0]=ar[0];
		final[1]=ar[1];
		final[2]=ar[3];
		final[3]=ar[2];
	}
	else if(area(ar[0],ar[2],ar[1],ar[3])!=0){
		final[0]=ar[0];
		final[1]=ar[2];
		final[2]=ar[1];
		final[3]=ar[3];
	}
	else if(area(ar[0],ar[2],ar[3],ar[1])!=0){
		final[0]=ar[0];
		final[1]=ar[2];
		final[2]=ar[3];
		final[3]=ar[1];
	}
	else if(area(ar[0],ar[3],ar[2],ar[1])!=0){
		final[0]=ar[0];
		final[1]=ar[3];
		final[2]=ar[2];
		final[3]=ar[1];
	}
	else if(area(ar[0],ar[3],ar[1],ar[2])!=0){
		final[0]=ar[0];
		final[1]=ar[3];
		final[2]=ar[1];
		final[3]=ar[2];
	}
	return ;
}

int durutto(point a, point b){
	int dell_x,dell_y;
	dell_x = a.x - b.x;
	dell_y = a.y - b.y;
	return (dell_x*dell_x) + (dell_y*dell_y) ;
}

void bahu_bali(){
	bahu_a= durutto(final[0],final[1]);
	bahu_b= durutto(final[1],final[2]);
	bahu_c= durutto(final[2],final[3]);
	bahu_d= durutto(final[3],final[0]);
	korno_ac= durutto(final[0],final[2]);
	korno_bd= durutto(final[1],final[3]);
	return ;
}

point getdhal(point a, point b){
	int dell_x,dell_y;
	point ans;
	dell_x=max(a.x,b.x)-min(a.x,b.x);
	dell_y=max(a.y,b.y)-min(a.y,b.y);
	if(dell_y==0) {
		ans.y=0;
		ans.x=-1;
		return ans;
	}
	if(dell_x==0){
		ans.x=0;
		ans.y=-1;
		return ans;
	}
	ans.x=dell_x/__gcd(dell_x,dell_y);
	ans.y=dell_y/__gcd(dell_x,dell_y);
	dell_x=a.x-b.x;
	dell_y=a.y-b.y;
	if(dell_x<0 && dell_y<0);
	else if(dell_y<0 || dell_x<0) ans.x=ans.x*(-1);

	for(int cs=1;cs<=t;cs++){
		khela_shuru();
	bahu_bali();
	if(chksqr()){
		cout<<"Case "<<cs<<": Square\n";
	}
	else if(chkrech()){
		cout<<"Case "<<cs<<": Rectangle\n";
	}
	else if(chkrombh()){
		cout<<"Case "<<cs<<": Rhombus\n";
	}
	else if(chksaman()){
		cout<<"Case "<<cs<<": Parallelogram\n";
	}
	else if(chktrap()){
		cout<<"Case "<<cs<<": Trapezium\n";
	}
	else {
		cout<<"Case "<<cs<<": Ordinary Quadrilateral\n";
	}
	}
    return 0;
}
