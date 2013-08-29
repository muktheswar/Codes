#include<stdio.h>
#define GC getchar_unlocked
template<class T>inline void output(T a){if(a){T v=a%10;output(a/10);putchar((char)(v+'0'));}}
template<class T>inline T input(T x){char c=GC();x=0;T s=1;while(c<48||c>57){if(c=='-')s=-1;c=GC();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=GC();}return x*s;}
int maxn=1000000;
long long int ans[1000001];
int main(){
int i,j;
for ( i = 1; i <= maxn / 2; i++) {
   for ( j = i + i; j < maxn; j += i) {
      ans[j] +=(long long) i;
   }
}
ans[1] = 0;
for ( i = 3; i < maxn; i++)ans[i] += ans[i-1];
  int T;
   scanf("%d",&T);
   while(T--){
   int n;
   scanf("%d",&n);
	printf("%lld\n",ans[n]);
	}
 return 0;
 }
