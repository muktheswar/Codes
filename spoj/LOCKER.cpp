
// AUTHOR: AMAN JAIN
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;
#define LL long long
#define VI vector < int >
#define SI ({int x;scanf("%d",&x);x;})
#define INF 1000000007
LL modpow(LL n ,LL k,LL mod){LL ans=1;while(k>0){if(k&1)ans=(ans*n)%mod;k>>=1;n=(n*n)%mod;}return ans%mod;}
int main(){
int T=SI;
while(T--){
LL n;
scanf("%lld",&n);
if(n<=4)printf("%lld\n",n);
else{
if(n%3==0)printf("%lld\n",modpow(3,n/3,INF)%INF);
else if(n%3==1)printf("%lld\n",(4*modpow(3,(n-4)/3,INF))%INF);
else printf("%lld\n",(2*modpow(3,(n-2)/3,INF))%INF);
}
}
	return 0;
}
