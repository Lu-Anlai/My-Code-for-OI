#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=10*res+(ch^'0'),ch=getchar();
	return res;
}

int n,m,p;

int main(void){
	read(),n=read(),m=read(),p=read();
	reg int ans=1;
	for(reg int i=n-m+1;i>n-(m<<1)+1;--i)
		ans=1ll*ans*i%p;
	printf("%d\n",ans);
	return 0;
}