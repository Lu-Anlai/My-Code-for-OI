#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
typedef unsigned long long ull;
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

inline void Read(void);
inline void Work(void);

int main(void){
	Read();
	Work();
	return 0;
}

struct Node{
	string f,t;
	inline Node(void){
		f=t="";
		return;
	}
	inline Node(const string& a,const string& b){
		f=a,t=b;
		return;
	}
};

Node r1[6];
Node r2[6];
string s,e;

inline void Read(void){
	cin>>s>>e;
	static string s1,s2;
	while(++n,cin>>s1>>s2){
		r1[n-1]=Node(s1,s2);
		r2[n-1]=Node(s2,s1);
	}
	--n;
	return;
}



inline void Work(void){
	BFS1(s,r1,n/2);
	BFS2(e,r2,n-n/2);
	return;
}
