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

inline void read(reg char *s){
	*s=getchar();
	while(!isdigit(*s))*s=getchar();
	while(isdigit(*s))*(++s)=getchar();
	*s='\0';
	return;
}

const int MAXN=20+5;
const int MAXM=20+5;
const int inf=0x3f3f3f3f;
const int MAXV=MAXN*MAXM*2;
const int MAXE=(MAXN*MAXM*2+MAXN*MAXM*8)*2;

int n,m;
char S[MAXN][MAXM],T[MAXN][MAXM],C[MAXN][MAXM];
int cnt=1,head[MAXV],to[MAXE],w[MAXE],p[MAXE],Next[MAXE];

inline void Add_Edge(reg int u,reg int v,reg int len,reg int val){
	Next[++cnt]=head[u];
	to[cnt]=v,w[cnt]=len,p[cnt]=val;
	head[u]=cnt;
	return;
}

inline void Add_Tube(reg int u,reg int v,reg int len,reg int val){
	Add_Edge(u,v,len,val);
	Add_Edge(v,u,0,-val);
	return;
}

bool inque[MAXV];
int dis[MAXV];
queue<int> Q;

inline bool spfa(int s,reg int t){
	memset(dis,0x3f,sizeof(dis));
	inque[s]=true,dis[s]=0,Q.push(s);
	while(!Q.empty()){
		reg int u=Q.front();
		Q.pop();
		inque[u]=false;
		for(reg int i=head[u];i;i=Next[i]){
			int v=to[i];
			if(dis[v]>dis[u]+p[i]&&w[i]){
				dis[v]=dis[u]+p[i];
				if(!inque[v]){
					inque[v]=true;
					Q.push(v);
				}
			}
		}
	}
	return dis[t]!=inf;
}

int cost;
bool vis[MAXV];
int cur[MAXV];

inline int dfs(reg int u,reg int t,reg int lim){
	if(u==t){
		cost+=dis[t]*lim;
		return lim;
	}
	vis[u]=true;
	reg int flow=0;
	for(reg int &i=cur[u];i;i=Next[i]){
		reg int v=to[i];
		if(dis[v]==dis[u]+p[i]&&w[i]&&!vis[v]){
			reg int f=dfs(v,t,min(lim-flow,w[i]));
			if(f){
				flow+=f;
				w[i]-=f,w[i^1]+=f;
				if(flow==lim)
					break;
			}
		}
	}
	vis[u]=false;
	return flow;
}

inline int dinic(reg int s,reg int t){
	reg int res=0;
	while(spfa(s,t)){
		memcpy(cur,head,sizeof(head));
		res+=dfs(s,t,inf);
	}
	return res;
}

inline int getId(reg int i,reg int j){
	return (i-1)*m+j;
}

inline int getNum(reg char ch){
	return ch^'0';
}

int main(void){
	n=read(),m=read();
	reg int nm=n*m;
	for(reg int i=1;i<=n;++i)
		read(S[i]+1);
	for(reg int i=1;i<=n;++i)
		read(T[i]+1);
	for(reg int i=1;i<=n;++i)
		read(C[i]+1);
	reg int tot1=0,tot2=0;
	for(reg int i=1;i<=n;++i)
		for(reg int j=1;j<=m;++j){
			if(S[i][j]=='1')
				++tot1;
			if(T[i][j]=='1')
				++tot2;
		}
	if(tot1!=tot2)
		puts("-1");
	else{
		reg int s=0,t=(nm<<1)|1;
		for(reg int i=1;i<=n;++i)
			for(reg int j=1;j<=m;++j){
				if(S[i][j]==T[i][j])
					Add_Tube(getId(i,j),getId(i,j)+nm,getNum(C[i][j])>>1,0);
				else{
					if(S[i][j]=='1')
						Add_Tube(s,getId(i,j),1,0);
					if(T[i][j]=='1')
						Add_Tube(getId(i,j)+nm,t,1,0);
					Add_Tube(getId(i,j),getId(i,j)+nm,((getNum(C[i][j])-1)>>1)+1,0);
				}
				const int dx[]={-1,-1,-1,0,0,1,1,1};
				const int dy[]={-1,0,1,-1,1,-1,0,1};
				for(reg int k=0;k<8;++k){
					reg int fx=i+dx[k],fy=j+dy[k];
					if(1<=fx&&fx<=n&&1<=fy&&fy<=m)
						Add_Tube(getId(i,j)+nm,getId(fx,fy),inf,1);
				}
			}
		dinic(s,t);
		printf("%d\n",cost);
	}
	return 0;
}