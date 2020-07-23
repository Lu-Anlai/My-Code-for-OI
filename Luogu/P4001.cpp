#include<bits/stdc++.h>
using namespace std;
#define reg register
#define INF 0X3F3F3F3F
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

const int MAXN=1000+5;
const int MAXM=1000+5;

inline void Read(void);
inline void Work(void);

int main(void){
	Read();
	Work();
	return 0;
}

int n,m,s,t;
int cnt=1,head[MAXN*MAXM],to[MAXN*MAXM*6],w[MAXN*MAXM*6],Next[MAXN*MAXM*6];

inline void Add_Edge(reg int u,reg int v,reg int len){
	Next[++cnt]=head[u];
	to[cnt]=v;
	w[cnt]=len;
	head[u]=cnt;
	return;
}

inline void Add_Tube(reg int u,reg int v,reg int len){
	Add_Edge(u,v,len);
	Add_Edge(v,u,len);
	return;
}

inline int GetID(reg int i,reg int j){
	return (i-1)*m+j;
}

inline void Read(void){
	n=read(),m=read(),s=1,t=GetID(n,m);
	for(reg int i=1;i<=n;++i)
		for(reg int j=1;j<m;++j){
			static int x;
			x=read();
			Add_Tube(GetID(i,j),GetID(i,j+1),x);
		}
	for(reg int i=1;i<n;++i)
		for(reg int j=1;j<=m;++j){
			static int x;
			x=read();
			Add_Tube(GetID(i,j),GetID(i+1,j),x);
		}
	for(reg int i=1;i<n;++i)
		for(reg int j=1;j<m;++j){
			static int x;
			x=read();
			Add_Tube(GetID(i,j),GetID(i+1,j+1),x);
		}
	return;
}

int dep[MAXN*MAXM];
queue<int> Q;

inline bool BFS(int s,reg int t){
	memset(dep,-1,sizeof(dep));
	while(!Q.empty())Q.pop();
	dep[s]=1,Q.push(s);
	while(!Q.empty()){
		reg int ID=Q.front();
		Q.pop();
		for(reg int i=head[ID];i;i=Next[i])
			if(dep[to[i]]==-1&&w[i]>0){
				dep[to[i]]=dep[ID]+1;
				Q.push(to[i]);
			}
	}
	return dep[t]!=-1;
}

int cur[MAXN*MAXM];

inline int DFS(reg int ID,reg int t,reg int lim){
	if(ID==t)
		return lim;
	reg int flow=0;
	for(reg int &i=cur[ID];i;i=Next[i])
		if(dep[to[i]]==dep[ID]+1&&w[i]>0){
			reg int f=DFS(to[i],t,min(lim-flow,w[i]));
			if(f){
				flow+=f;
				w[i]-=f;
				w[i^1]+=f;
				if(flow==lim)
					break;
			}
		}
	return flow;
}

inline int Dinic(reg int s,reg int t){
	reg int res=0;
	while(BFS(s,t)){
		memcpy(cur,head,sizeof(head));
		res+=DFS(s,t,INF);
	}
	return res;
}

inline void Work(void){
	reg int ans=Dinic(s,t);
	printf("%d\n",ans);
	return;
}