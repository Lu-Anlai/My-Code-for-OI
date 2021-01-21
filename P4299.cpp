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

const int MAXN=1e5+5;
const int inf=0x3f3f3f3f;

int n,m;

namespace UnionFind{
	int fa[MAXN];
	inline void Init(reg int n){
		for(reg int i=1;i<=n;++i)
			fa[i]=i;
		return;
	}
	inline int find(reg int x){
		if(x==fa[x])
			return x;
		else
			return fa[x]=find(fa[x]);
	}
}

namespace LCT{
	struct Node{
		int fa,ch[2];
		ll siz,sum;
		bool tRev;
		#define fa(x) unit[(x)].fa
		#define ch(x) unit[(x)].ch
		#define siz(x) unit[(x)].siz
		#define tRev(x) unit[(x)].tRev
		#define sum(x) unit[(x)].sum
	};
	#define lson(x) ch(x)[0]
	#define rson(x) ch(x)[1]
	Node unit[MAXN];
	inline bool get(reg int p){
		return rson(fa(p))==p;
	}
	inline bool isRoot(reg int p){
		assert(1<=p);
		assert(p<=n);

		return lson(fa(p))!=p&&rson(fa(p))!=p;
	}
	inline void pushup(reg int p){
		siz(p)=siz(lson(p))+siz(rson(p))+sum(p)+1;
		return;
	}
	inline void Rev(reg int p){
		swap(lson(p),rson(p));
		tRev(p)=!tRev(p);
		return;
	}
	inline void pushdown(reg int p){
		if(tRev(p)){
			if(lson(p))
				Rev(lson(p));
			if(rson(p))
				Rev(rson(p));
			tRev(p)=false;
		}
		return;
	}
	inline void rotate(reg int p){
			assert(p<=n);
		if(isRoot(p))
			return;
		reg int f=fa(p),ff=fa(f),dir=get(p);pushdown(ff),pushdown(f),pushdown(p);

			assert(f<=n);
		if(!isRoot(f)) ch(ff)[get(f)]=p;
		if(ch(p)[dir^1]) fa(ch(p)[dir^1])=f;
		ch(f)[dir]=ch(p)[dir^1];
		ch(p)[dir^1]=f,fa(f)=p;
		fa(p)=ff;
		pushup(f),pushup(p);
		return;
	}
	inline void update(reg int p){
		assert(p<=n);
		if(!isRoot(p))
			update(fa(p));
		pushdown(p);
		return;
	}
	inline void splay(reg int p){

			assert(p<=n);
		update(p);
		for(reg int f;f=fa(p),!isRoot(p);rotate(p))
			if(!isRoot(f))
				rotate(get(p)==get(f)?f:p);
		pushup(p);
		return;
	}
	inline void access(reg int p){
		for(reg int pre=0;p;pre=p,p=fa(p)){
			assert(p<=n);
			splay(p),sum(p)+=siz(rson(p)),sum(p)-=sum(rson(p)=pre),pushup(p);
		}
		return;
	}
	inline void makeRoot(reg int p){

			assert(p<=n);
		access(p),splay(p),Rev(p);
		return;
	}
	inline void split(reg int x,reg int y){

			assert(y<=n);
		makeRoot(x),access(y),splay(y);
		return;
	}
	inline void link(reg int x,reg int y){
		makeRoot(x),fa(x)=y,sum(y)+=siz(x),pushup(y);
		return;
	}
}

inline int getM(reg int x){
	using namespace LCT;
	reg int tot=siz(x);
	reg int f=(tot&1),half=(tot>>1);
	reg int np=n;
	reg int lsum=0,rsum=0;
	while(x){
		pushdown(x);
		reg int lef=siz(lson(x))+lsum;
		reg int rig=siz(rson(x))+rsum;
		if(lef<=half&&rig<=half){
			if(f){
				np=x;
				break;
			}
			else{
				np=min(np,x);
			}
		}
		if(lef<rig)
			lsum+=siz(lson(x))+sum(x)+1,x=rson(x);
		else
			rsum+=siz(rson(x))+sum(x)+1,x=lson(x);
	}
	assert(np<=n);
	splay(np);
	return np;
}

int main(void){
	n=read(),m=read();
	UnionFind::Init(n);
	reg int Xor=0;
	for(reg int i=1;i<=n;++i){
		Xor^=i;
		LCT::siz(i)=1;
	}
	while(m--){
		static char op;
		static int x,y;
		do
			op=getchar();
		while(!isalpha(op));
		switch(op){
			case 'A':{
				x=read(),y=read();
				assert(x<=n);
				assert(y<=n);
				LCT::link(x,y);
				x=UnionFind::find(x),y=UnionFind::find(y);
				LCT::split(x,y);
				reg int p=getM(y);
				Xor^=x^y^p;
				UnionFind::fa[p]=p;
				UnionFind::fa[x]=UnionFind::fa[y]=p;
				break;
			}
			case 'Q':{
				x=read();
				printf("%d\n",UnionFind::find(x));
				break;
			}
			case 'X':{
				getchar(),getchar(),printf("%d\n",Xor);
				break;
			}
		}
	}
	return 0;
}