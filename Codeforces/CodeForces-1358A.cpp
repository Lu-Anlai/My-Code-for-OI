#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
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

int n,m;

int main(void){
	reg int T=read();
	while(T--){
		n=read(),m=read();
		if(n>m)
			swap(n,m);
		reg ll ans=n*(m/2);
		if(m&1)
			ans+=ceil(n*0.5);
		printf("%lld\n",ans);
	}
	return 0;
}