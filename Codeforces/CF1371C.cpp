#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline ll read(void){
	reg char ch=getchar();
	reg ll res=0;
	while(ch<'0'||'9'<ch)ch=getchar();
	while('0'<=ch&&ch<='9')res=10ll*res+ch-'0',ch=getchar();
	return res;
}

ll a,b,n,m;

int main(void){
	reg int T=read();
	while(T--){
		a=read(),b=read(),n=read(),m=read();
		if(a+b<n+m)
			puts("No");
		else if(min(a,b)>=m)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}