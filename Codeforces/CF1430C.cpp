#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg char ch=getchar();
	reg int res=0;
	while(ch<'0'||'9'<ch)ch=getchar();
	while('0'<=ch&&ch<='9')res=10*res+ch-'0',ch=getchar();
	return res;
}

int n;

int main(void){
	reg int t=read();
	while(t--){
		n=read();
		puts("2");
		printf("%d %d\n",n-1,n);
		for(reg int i=n;i>2;--i)
			printf("%d %d\n",i-2,i);
	}
	return 0;
}