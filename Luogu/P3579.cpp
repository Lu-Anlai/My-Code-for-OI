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

int a,b,c,d;

int main(void){
	reg int T=read();
    while(T--){
		a=read(),b=read(),c=read(),d=read();
		if(c<a){
			swap(a,c);
			swap(b,d);
		}
		if(c<=b)
			if(d<=b)
				printf("%d\n",d);
			else
				printf("%d\n",b);
		else{
			reg int last,ans=1;
			for(reg int i=1;i<=min(b,d);i=last+1){
				last=min(b/(b/i),d/(d/i));
				if(b/last>(a-1)/last&&d/last>(c-1)/last)
					ans=last;
			}
        	printf("%d\n",ans);
		}
    }
    return 0;
}
