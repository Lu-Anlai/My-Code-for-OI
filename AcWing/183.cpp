#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(x) ( (x) & ( - (x) ) )

const int MAXSIZE=9;
const int MAXCSIZE=3;

int cnt[1<<MAXSIZE];
int p[1<<MAXSIZE];

inline void Init(void){
	for(reg int i=0;i<(1<<MAXSIZE);++i)
		for(reg int j=i;j;j-=lowbit(j))
			++cnt[i];
	for(reg int i=0;i<MAXSIZE;++i)
		p[1<<i]=i;
	return;
}

struct Node{
	int S[MAXSIZE][MAXSIZE];
	char str[MAXSIZE][MAXSIZE+1];
	inline int Read(void){
		for(reg int i=0;i<MAXSIZE;++i)
			for(reg int j=0;j<MAXSIZE;++j)
				S[i][j]=(1<<MAXSIZE)-1;
		reg int res=0;
		for(reg int i=0;i<MAXSIZE;++i)
			for(reg int j=0;j<MAXSIZE;++j){
				static int x;
				scanf("%d",&x);
				str[i][j]=x;
			}
		for(reg int i=0;i<MAXSIZE;++i)
			for(reg int j=0;j<MAXSIZE;++j)
				switch(str[i][j]){
					case 0:
						++res;
						break;
					default:
						draw(i,j,str[i][j]-1);
				}
		return res;
	}
	inline void draw(reg int x,reg int y,reg int v){
		str[x][y]=v+1;
		for(reg int i=0;i<MAXSIZE;++i){
			S[x][i]&=~(1<<v);
			S[i][y]&=~(1<<v);
		}
		reg int fx=x/MAXCSIZE*MAXCSIZE,fy=y/MAXCSIZE*MAXCSIZE;
		for(reg int i=0;i<MAXCSIZE;++i)
			for(reg int j=0;j<MAXCSIZE;++j)
				S[fx+i][fy+j]&=~(1<<v);
		S[x][y]=1<<v;
		return;
	}
	inline void Print(void){
		for(reg int i=0;i<MAXSIZE;++i,putchar('\n'))
			for(reg int j=0;j<MAXSIZE;++j)
				putchar(str[i][j]);
		putchar('\n');
		return;
	}
	inline int GetScore(void){
		reg int res=0;
		static const int G[9][9]={
			6,6,6,6,6,6,6,6,6,
			6,7,7,7,7,7,7,7,6,
			6,7,8,8,8,8,8,7,6,
			6,7,8,9,9,9,8,7,6,
			6,7,8,9,10,9,8,7,6,
			6,7,8,9,9,9,8,7,6,
			6,7,8,8,8,8,8,7,6,
			6,7,7,7,7,7,7,7,6,
			6,6,6,6,6,6,6,6,6};
		for(reg int i=0;i<MAXSIZE;++i)
			for(reg int j=0;j<MAXSIZE;++j)
				res+=str[i][j]*G[i][j];
		return res;
	}
};

int ans=-1;
Node a;

inline void DFS(reg int need,Node a){
	if(!need){
		ans=max(ans,a.GetScore());
		return;
	}
	for(reg int i=0;i<MAXSIZE;++i)
		for(reg int j=0;j<MAXSIZE;++j)
			if(a.str[i][j]==0){
				if(!a.S[i][j])
					return;
				if(cnt[a.S[i][j]]==1){
					a.draw(i,j,p[a.S[i][j]]);
					--need;
				}
			}
	for(reg int i=0;i<MAXSIZE;++i){
		reg int sor=0,sand=(1<<MAXSIZE)-1,drawn=0;
		for(reg int j=0;j<MAXSIZE;++j){
			sand&=~(sor&a.S[i][j]);
			sor|=a.S[i][j];
			if(a.str[i][j]!=0)
				drawn|=a.S[i][j];
		}
		if(sor!=(1<<MAXSIZE)-1)
			return;
		for(reg int j=sand;j;j-=lowbit(j)){
			if(!(drawn&lowbit(j))){
				for(reg int k=0;k<MAXSIZE;++k){
					if(a.S[i][k]&lowbit(j)){
						--need;
						a.draw(i,k,p[lowbit(j)]);
						break;
					}
				}
			}
		}
	}
	for(reg int i=0;i<MAXSIZE;++i){
		reg int sor=0,sand=(1<<MAXSIZE)-1,drawn=0;
		for(reg int j=0;j<MAXSIZE;++j){
			sand&=~(sor&a.S[j][i]);
			sor|=a.S[j][i];
			if(a.str[j][i]!=0)
				drawn|=a.S[j][i];
		}
		if(sor!=(1<<MAXSIZE)-1)
			return;
		for(reg int j=sand;j;j-=lowbit(j)){
			if(!(drawn&lowbit(j))){
				for(reg int k=0;k<MAXSIZE;++k){
					if(a.S[k][i]&lowbit(j)){
						--need;
						a.draw(k,i,p[lowbit(j)]);
						break;
					}
				}
			}
		}
	}
	for(reg int i=0;i<MAXSIZE;++i){
		reg int sor=0,sand=(1<<MAXSIZE)-1,drawn=0;
		for(reg int j=0;j<MAXSIZE;++j){
			reg int sx=i/MAXCSIZE*MAXCSIZE,sy=i%MAXCSIZE*MAXCSIZE;
			reg int dx=j/MAXCSIZE,dy=j%MAXCSIZE;
			sand&=~(sor&a.S[sx+dx][sy+dy]);
			sor|=a.S[sx+dx][sy+dy];
			if(a.str[sx+dx][sy+dy]!=0)
				drawn|=a.S[sx+dx][sy+dy];
		}
		if(sor!=(1<<MAXSIZE)-1)
			return;
		for(reg int j=sand;j;j-=lowbit(j)){
			if(!(drawn&lowbit(j))){
				for(reg int k=0;k<MAXSIZE;++k){
					reg int sx=i/MAXCSIZE*MAXCSIZE,sy=i%MAXCSIZE*MAXCSIZE;
					reg int dx=k/MAXCSIZE,dy=k%MAXCSIZE;
					if(a.S[sx+dx][sy+dy]&lowbit(j)){
						--need;
						a.draw(sx+dx,sy+dy,p[lowbit(j)]);
						break;
					}
				}
			}
		}
	}
	if(!need){
		ans=max(ans,a.GetScore());
		return;
	}
	reg int Min=MAXSIZE,posx=-1,posy=-1;
	for(reg int i=0;i<MAXSIZE;++i)
		for(reg int j=0;j<MAXSIZE;++j){
			if(a.str[i][j]==0&&cnt[a.S[i][j]]<Min){
				Min=cnt[a.S[i][j]];
				posx=i,posy=j;
			}
		}
	if(posx==-1&&posy==-1)
		return;
	reg int k=a.S[posx][posy];
	while(k){
		Node temp=a;
		temp.draw(posx,posy,p[lowbit(k)]);
		DFS(need-1,temp);
		k-=lowbit(k);
	}
	return;
}

int main(void){
	Init();
	reg int n=a.Read();
	DFS(n,a);
	printf("%d\n",ans);
	return 0;
}
