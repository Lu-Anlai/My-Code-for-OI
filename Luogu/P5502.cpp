#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline ll read(void){
	reg bool f=false;
	reg char ch=getchar();
	reg ll res=0;
	while(ch<'0'||'9'<ch)f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')res=10*res+ch-'0',ch=getchar();
	return f?-res:res;
}

const int MAXN=100000+5;

int n;
ll a[MAXN]={-1};
queue<int> Q,T;

inline ll gcd(reg ll a,reg ll b){
	return b==0?a:gcd(b,a%b);
}

int main(void){
	n=read();
	ll ans=0;
	for(reg int i=1,last=0;i<=n;++i){
		a[i]=read();
		last=0;
		while(!Q.empty()){
			int pos=Q.front();
			Q.pop();
			a[pos]=gcd(a[pos],a[i]);
			ans=max(ans,a[pos]*(i-pos+1));
			if(a[pos]==a[last])
				continue;
			T.push(pos);
			last=pos;
		}
		ans=max(ans,a[i]);
		while(!T.empty()){
			Q.push(T.front());
			T.pop();
		}
		if(a[last]!=a[i])
			Q.push((int)i);
	}
	printf("%lld\n",ans);
	return 0;
}
