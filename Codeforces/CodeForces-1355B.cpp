#include<bits/stdc++.h>
using namespace std;
#define reg register
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg char ch=getchar();
	reg int res=0;
	while(ch<'0'||'9'<ch)ch=getchar();
	while('0'<=ch&&ch<='9')res=10*res+ch-'0',ch=getchar();
	return res;
}

const int MAXN=200000+5;

int n;
int a[MAXN];

int main(void){
	reg int T=read();
	while(T--){
		n=read();
		for(reg int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+n+1);
		reg int cnt=0,ans=0;
		for(reg int i=1;i<=n;++i){
			++cnt;
			if(a[i]==cnt){
				cnt=0;
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}