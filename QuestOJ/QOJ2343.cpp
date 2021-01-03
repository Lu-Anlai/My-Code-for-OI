#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
typedef unsigned long long ull;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
static char buf[100000],*p1=buf,*p2=buf;
inline int read(void){
	reg char ch=getchar();
	reg int res=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=res*10+(ch^'0'),ch=getchar();
	return res;
}

const int MOD=1e9+7;

inline int Add(reg int a,reg int b){
	reg int sum=a+b;
	return sum>=MOD?sum-MOD:sum;
}
inline int Mul(reg int a,reg int b){
	return 1ll*a*b%MOD;
}

const int MAXN=1e5+5;
const int MAXM=1e5+5;
const int MAXX=2e5+5;
const int X=1e5+50;

int n,m;
int cnt,head[MAXN],to[MAXM<<1],w[MAXM<<1],Next[MAXM<<1];

inline void Add_Edge(reg int u,reg int v,reg int len){
	Next[++cnt]=head[u];
	to[cnt]=v;
	w[cnt]=len;
	head[u]=cnt;
	return;
}

const ull base=17;
int base2p[MAXX<<1];
ull basep[MAXX<<1];

inline void InitBase(reg int s){
	base2p[0]=basep[0]=1;
	for(reg int i=1;i<=s;++i){
		base2p[i]=Add(base2p[i-1],base2p[i-1]);
		basep[i]=basep[i-1]*base;
	}
	return;
}

namespace SegmentTree{
	#define mid ( ( (l) + (r) ) >> 1 )
	struct Node{
		int lson,rson;
		int cnt;
		ull sum;
		ull Hash;
		#define lson(x) unit[(x)].lson
		#define rson(x) unit[(x)].rson
		#define cnt(x) unit[(x)].cnt
		#define sum(x) unit[(x)].sum
		#define Hash(x) unit[(x)].Hash
	};
	const int MAXSIZE=MAXN*50;
	int tot,rt[MAXN];
	Node unit[MAXSIZE];
	inline void pushup(reg int k){
		cnt(k)=cnt(lson(k))+cnt(rson(k));
		sum(k)=Add(sum(lson(k)),sum(rson(k)));
		Hash(k)=Hash(lson(k))+Hash(rson(k));
		return;
	}
	inline int build(reg int l,reg int r,reg int val){
		reg int k=++tot;
		if(l==r){
			cnt(k)=val;
			sum(k)=Mul(base2p[l],val);
			Hash(k)=basep[l]*val;
			return k;
		}
		lson(k)=build(l,mid,val),rson(k)=build(mid+1,r,val);
		pushup(k);
		return k;
	}
	inline int queryCnt(reg int k,reg int l,reg int r,reg int L,reg int R){
		if(L<=l&&r<=R)
			return cnt(k);
		if(L<=mid&&mid<R)
			return queryCnt(lson(k),l,mid,L,R)+queryCnt(rson(k),mid+1,r,L,R);
		else if(L<=mid)
			return queryCnt(lson(k),l,mid,L,R);
		else
			return queryCnt(rson(k),mid+1,r,L,R);
	}
	inline int querySum(reg int k,reg int l,reg int r,reg int L,reg int R){ //查询 [L,R] 内表示的二进制数的具体值
		if(L<=l&&r<=R)
			return sum(k);
		if(L<=mid&&mid<R)
			return Add(querySum(lson(k),l,mid,L,R),querySum(rson(k),mid+1,r,L,R));
		else if(L<=mid)
			return querySum(lson(k),l,mid,L,R);
		else
			return querySum(rson(k),mid+1,r,L,R);
	}
	inline ull queryHash(reg int k,reg int l,reg int r,reg int L,reg int R){ //查询 [L,R] 的 Hash 值
		if(L<=l&&r<=R)
			return Hash(k);
		if(L<=mid&&mid<R)
			return queryHash(lson(k),l,mid,L,R)+queryHash(rson(k),mid+1,r,L,R);
		else if(L<=mid)
			return queryHash(lson(k),l,mid,L,R);
		else
			return queryHash(rson(k),mid+1,r,L,R);
	}
	inline int find(reg int k,reg int l,reg int r,reg int pos){
		if(l==r)
			return l;
		if(pos>mid)
			return find(rson(k),mid+1,r,pos);
		if(queryCnt(lson(k),l,mid,pos,mid)==mid-pos+1)
			return find(rson(k),mid+1,r,mid+1);
		else
			return find(lson(k),l,mid,pos);
	}
	inline int update(reg int pre,reg int l,reg int r,reg int pos){
		reg int k=++tot;
		lson(k)=lson(pre),rson(k)=rson(pre);
		if(l==r){
			cnt(k)=1;
			sum(k)=base2p[l];
			Hash(k)=basep[l];
			return k;
		}
		if(pos<=mid)
			lson(k)=update(lson(pre),l,mid,pos);
		else
			rson(k)=update(rson(pre),mid+1,r,pos);
		pushup(k);
		return k;
	}
	inline int move(reg int p,reg int q,reg int l,reg int r,reg int L,reg int R){
		if(R<l||r<L)
			return p;
		if(L<=l&&r<=R)
			return q;
		reg int k=++tot;
		lson(k)=move(lson(p),lson(q),l,mid,L,R);
		rson(k)=move(rson(p),rson(q),mid+1,r,L,R);
		pushup(k);
		return k;
	}
	inline int plus(reg int k,reg int l,reg int r,reg int w){
		reg int pos=find(k,l,r,w);
		reg int tmp=update(k,l,r,pos);
		if(pos!=w)
			tmp=move(tmp,rt[0],l,r,w,pos-1);
		return tmp;
	}
	inline bool same(reg int p,reg int q){
		return cnt(p)==cnt(q)&&sum(p)==sum(q)&&Hash(p)==Hash(q);
	}
	inline bool cmp(reg int p,reg int q,reg int l,reg int r){
		if(l==r)
			return cnt(p)<=cnt(q);
		if(same(rson(p),rson(q)))
			return cmp(lson(p),lson(q),l,mid);
		else
			return cmp(rson(p),rson(q),mid+1,r);
	}
	#undef lson
	#undef rson
	#undef cnt
	#undef sum
	#undef Hash
	#undef mid
}
struct Node{
	int id,rt;
	inline Node(reg int id=0,reg int rt=0):id(id),rt(rt){
		return;
	}
};

namespace Heap{
	#define lson(x) ch[(x)][0]
	#define rson(x) ch[(x)][1]
	const int MAXSIZE=4e5+5;
	int tot,Rt,siz;
	Node unit[MAXSIZE];
	int ch[MAXSIZE][2],dep[MAXSIZE];
	inline int merge(int p,int q){
		if(!p||!q)
			return p+q;
		if(SegmentTree::cmp(unit[q].rt,unit[p].rt,0,X))
			swap(p,q);
		rson(p)=merge(rson(p),q);
		if(dep[rson(p)]>dep[lson(p)])
			swap(lson(p),rson(p));
		dep[p]=dep[lson(p)]+1;
		return p;
	}
	inline void push(const Node& a){
		++siz;
		unit[++tot]=a;
		Rt=merge(tot,Rt);
		return;
	}
	inline void pop(void){
		--siz;
		Rt=merge(lson(Rt),rson(Rt));
		return;
	}
	inline Node top(void){
		return unit[Rt];
	}
	inline bool empty(void){
		return siz==0;
	}
	#undef lson
	#undef rson
}

bool vis[MAXN];
int from[MAXN];

using SegmentTree::rt;

inline void dijkstra(reg int s,reg int t){
	reg int inf=SegmentTree::build(0,X,1);
	for(reg int i=1;i<=n;++i)
		rt[i]=inf;
	rt[0]=rt[s]=SegmentTree::build(0,X,0);
	Heap::push(Node(s,rt[s]));
	while(!Heap::empty()){
		while(!Heap::empty()&&vis[Heap::top().id])
			Heap::pop();
		if(Heap::empty())
			break;
		reg int u=Heap::top().id;
		Heap::pop();
		vis[u]=true;
		for(reg int i=head[u];i;i=Next[i]){
			reg int v=to[i];
			if(vis[v])
				continue;
			reg int tmp=SegmentTree::plus(rt[u],0,X,w[i]);
			if(SegmentTree::cmp(rt[v],tmp,0,X))
				continue;
			rt[v]=tmp;
			from[v]=u;
			Heap::push(Node(v,rt[v]));
		}
	}
	if(rt[t]==inf)
		puts("-1");
	else{
		printf("%d\n",SegmentTree::querySum(rt[t],0,X,0,X));
		/*
		static int path[MAXN];
		reg int tot=0;
		for(reg int i=t;i!=s;i=from[i])
			path[++tot]=i;
		path[++tot]=s;
		printf("%d\n",tot);
		for(reg int i=tot;i>=1;--i)
			printf("%d%c",path[i],i==1?'\n':' ');
		*/
	}
	return;
}
int main(void){
	n=read(),m=read();
	reg int s=read(),t=read();
	for(reg int i=1;i<=m;++i){
		static int u,v,x;
		u=read(),v=read(),x=read();
		Add_Edge(u,v,x);
		Add_Edge(v,u,x);
	}
	InitBase(X);
	dijkstra(s,t);
	return 0;
}