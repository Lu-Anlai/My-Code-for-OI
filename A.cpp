#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
#define flush() (fwrite(wbuf,1,wp1,stdout),wp1=0)
#define putchar(c) (wp1==wp2&&(flush(),0),wbuf[wp1++]=c)
static char wbuf[1<<21];int wp1;const int wp2=1<<21;
inline int read(void){
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return res;
}

inline ll readll(void){
	reg char ch=getchar();
	reg ll res=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return res;
}

inline void writeln(reg int x){
	static char buf[32];
	reg int p=-1;
	if(x==0) putchar('0');
	else while(x) buf[++p]=(x%10)^'0',x/=10;
	while(~p) putchar(buf[p--]);
	putchar('\n');
	return;
}

const long double eps=1e-6;

inline int sgn(reg long double x){
	if(fabs(x)<eps)
		return 0;
	else
		return x<0?-1:1;
}

int main(void){
	reg int T=read();
	while(T--){
		reg int n=read();
		reg int cnt=0;
		reg long double sum=0;
		for(reg int i=1;i<=n;++i){
			static long double x,y,z;
			x=readll(),y=readll(),z=readll();
			if(y) ++cnt;
			sum+=x-z;
		}
		reg int ans=0;
		if(cnt&1)
			ans=(sgn(sum)>=0)?40:60;
		else
			ans=(sgn(sum)>0)?40:60;
		writeln(ans);
	}
	flush();
	return 0;
}