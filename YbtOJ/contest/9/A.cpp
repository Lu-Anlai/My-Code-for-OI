#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
#define flush() (fwrite(wbuf,1,wp1,stdout),wp1=0)
#define putchar(c)(wp1==wp2&&(flush(),0),wbuf[wp1++]=c)
static char wbuf[1<<21];int wp1;const int wp2=1<<21;
inline int read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return f?-res:res;
}

inline void writeln(reg int x){
	static char buf[32];
	reg int p=-1;
	if(x==0)
		putchar('0');
	else
		while(x)
			buf[++p]=(x%10)^'0',x/=10;
	while(~p)
		putchar(buf[p--]);
	putchar('\n');
	return;
}

const int MAXN=1e5+5;

int n;
int a[MAXN];
int up[MAXN],down[MAXN];
int f[MAXN];

int main(void){
	up[0]=down[0]=1;
	n=read();
	for(reg int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]==a[i-1]||i==1)
			up[i]=up[i-1],down[i]=down[i-1];
		else if(a[i]>a[i-1])
			up[i]=up[i-1],down[i]=i;
		else
			up[i]=i,down[i]=down[i-1];
	}
	for(reg int i=1;i<=n;++i)
		f[i]=min(f[up[i]-1],f[down[i]-1])+1;
	writeln(f[n]);
	flush();
	return 0;
}