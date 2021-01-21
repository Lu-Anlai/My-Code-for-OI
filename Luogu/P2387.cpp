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

inline int min(reg int a,reg int b){
	return a<b?a:b;
}

const int MAXN=5e4+5;
const int MAXM=1e5+5;
const int MAXV=MAXN+MAXM;
const int inf=0x3f3f3f3f;

namespace UnionFind{
	int fa[MAXV];
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
	inline void merge(reg int a,reg int b){
		reg int ra=find(a),rb=find(b);
		if(ra!=rb)
			fa[rb]=ra;
		return;
	}
	inline bool search(reg int a,reg int b){
		return find(a)==find(b);
	}
}

namespace LCT{
	struct Node{
		int fa,ch[2];
		int Max,val;
		bool tRev;
		#define fa(x) unit[(x)].fa
		#define ch(x) unit[(x)].ch
		#define siz(x) unit[(x)].siz
		#define Max(x) unit[(x)].Max
		#define val(x) unit[(x)].val
		#define tRev(x) unit[(x)].tRev
	};
	#define lson(x) ch(x)[0]
	#define rson(x) ch(x)[1]
	int tot;
	Node unit[MAXV];
	inline void New(reg int p,reg int v){
		fa(p)=lson(p)=rson(p)=0;
		Max(p)=v;
		tRev(p)=false;
		return;
	}
	inline bool get(reg int p){
		return rson(fa(p))==p;
	}
	inline bool isRoot(reg int p){
		return lson(fa(p))!=p&&rson(fa(p))!=p;
	}
	inline void pushup(reg int p){
		Max(p)=p;
		if(lson(p)&&val(Max(lson(p)))>val(Max(p)))
			Max(p)=Max(lson(p));
		if(rson(p)&&val(Max(rson(p)))>val(Max(p)))
			Max(p)=Max(rson(p));
		return;
	}
	inline void rotate(reg int p){
		if(isRoot(p))
			return;
		reg int f=fa(p),ff=fa(f),dir=get(p);
		if(!isRoot(f)) ch(ff)[get(f)]=p;
		if(ch(p)[dir^1]) fa(ch(p)[dir^1])=f;
		ch(f)[dir]=ch(p)[dir^1];
		ch(p)[dir^1]=f,fa(f)=p;
		fa(p)=ff;
		pushup(f),pushup(p);
		return;
	}
	inline void pushdown(reg int p){
		if(tRev(p)){
			swap(lson(p),rson(p));
			if(lson(p))
				tRev(lson(p))=!tRev(lson(p));
			if(rson(p))
				tRev(rson(p))=!tRev(rson(p));
			tRev(p)=false;
		}
		return;
	}
	inline void update(reg int p){
		if(!isRoot(p))
			update(fa(p));
		pushdown(p);
		return;
	}
	inline void splay(reg int p){
		update(p);
		for(reg int f;f=fa(p),!isRoot(p);rotate(p))
			if(!isRoot(f))
				rotate(get(p)==get(f)?f:p);
		pushup(p);
		return;
	}
	inline void access(reg int p){
		for(reg int pre=0;p;pre=p,p=fa(p))
			splay(p),rson(p)=pre,pushup(p);
		return;
	}
	inline void makeRoot(reg int p){
		access(p),splay(p),tRev(p)=!tRev(p);
		return;
	}
	inline void link(reg int x,reg int y){
		makeRoot(x),fa(x)=y;
		return;
	}
	inline void split(reg int x,reg int y){
		makeRoot(x),access(y),splay(y);
		return;
	}
	inline void cut(reg int x,reg int y){
		split(x,y);
		fa(x)=lson(y)=0;
		pushup(y);
		return;
	}
}

struct Edge{
	int x,y,a,b;
	inline bool operator<(const Edge& x)const{
		return a<x.a;
	}
};

int n,m;
Edge E[MAXM];

int main(void){
	n=read(),m=read();
	for(reg int i=1;i<=m;++i)
		E[i].x=read(),E[i].y=read(),E[i].a=read(),E[i].b=read();
	sort(E+1,E+m+1);
	for(reg int i=1;i<=n+m;++i)
		LCT::New(i,i);
	UnionFind::Init(n+m);
	for(reg int i=n+1;i<=n+m;++i)
		LCT::val(i)=E[i-n].b;
	reg int ans=inf;
	for(reg int i=1;i<=m;++i){
		if(UnionFind::search(E[i].x,E[i].y)){
			LCT::split(E[i].x,E[i].y);
			reg int id=LCT::Max(E[i].y);
			if(LCT::val(id)>E[i].b){
				LCT::cut(E[id-n].x,id),LCT::cut(E[id-n].y,id);
				LCT::link(E[i].x,i+n),LCT::link(E[i].y,i+n);
			}
		}
		else{
			UnionFind::merge(E[i].x,E[i].y);
			LCT::link(E[i].x,i+n),LCT::link(E[i].y,i+n);
		}
		if(UnionFind::search(1,n)){
			LCT::split(1,n);
			reg int id=LCT::Max(n);
			ans=min(ans,E[i].a+LCT::val(id));
		}
	}
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}