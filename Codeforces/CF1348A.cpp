#include<bits/stdc++.h>
using namespace std;
#define reg register
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg int res=0;
	while(ch<'0'||'9'<ch)f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')res=10*res+ch-'0',ch=getchar();
	return f?-res:res;
}

int main(void){
	reg int T=read();
	while(T--){
		reg int n=read();
		reg int ans=(1<<n);
		for(reg int i=1;i<=n/2;++i)
			ans-=(1<<(i+n/2-1));
		for(reg int i=1;i<=n/2-1;++i)
			ans+=(1<<i);
		printf("%d\n",ans);
	}
	return 0;
}