#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;

const ll D[]={1,0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841,2290792932,32071101049,481066515734,7697064251745,130850092279664,2355301661033953,44750731559645106,895014631192902121};

int n;

int main(void){
	scanf("%d",&n);
	printf("%lld\n",D[n]);
	return 0;
}