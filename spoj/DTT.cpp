
// AUTHOR: AMAN JAIN
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>
#include <iterator>
#include <assert.h>
using namespace std;

#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size()) 
#define SORT(c) sort(ALL(c)) 
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
#define mt(x, y, z) mp(mp(x,y),z)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define setbits(x) __builtin_popcount(x) //tell number of 1's in binary form
#define GC getchar_unlocked
#define out_c(start,end) copy(start, end, ostream_iterator< typeof(*start) >(cout, " "));
template<class T>inline T modinv(T a,T n){T i=n,v=0,d=1;while(a>0){T t=i/a,x=a;a=i%x;i=x;x=d;d=v-t*x;v=x;}return (v+n)%n;}
LL modpow(LL n ,LL k,LL mod){LL ans=1;while(k>0){if(k&1)ans=(ans*n)%mod;k>>=1;n=(n*n)%mod;}return ans%mod;}
//FRACTION
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=GCD(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
//template<class T>inline void output(T a){if(a){T v=a%10;output(a/10);putchar((char)(v+'0'));}}

//template<class T>inline T input(T x){char c=GC();x=0;T s=1;while(c<48||c>57){if(c=='-')s=-1;c=GC();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=GC();}return x*s;}
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
  int StringToNumber ( const string &Text )
  {
     istringstream ss(Text);
     int result;
     return ss >> result ? result : 0;
  }
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T>inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}

int main(){
while(1){
int n=SI;
if(n==0)break;
vector<int> a(14),b(14);
int pera=0,perb=0;
FOR(i,0,n){int t=SI;if(i%2==0){a[t]++;}else {b[t]++;}}
FOR(i,1,14){pera+=a[i]/3;a[i]%=3;perb+=b[i]/3;b[i]%=3;}
int ca=0,cb=0;
for(int i=1;i<=13;i++){
for(int j=1;j<=13;j++){
for(int k=1;k<=13;k++){
if(i+j>k && i+k>j && k+j>i){
if(!(i==j && j==k)){
int f=0;
if(i==j || j==k || i==k){
if(i==j){if(a[i]==2){
int t=min(1,a[k]);ca+=t;a[i]-=2*t;a[k]-=t;
}
}
else if(j==k){if(a[j]==2){
int t=min(1,a[i]);ca+=t;a[i]-=t;a[k]-=2*t;
}
}
else if(i==k){if(a[i]==2){
int t=min(1,a[j]);ca+=t;a[j]-=t;a[k]-=2*t;
}
}
}
else {
int t=min(a[i],min(a[j],a[k]));
a[i]-=t;
a[j]-=t;
a[k]-=t;
ca+=t;
}
if(i==j || j==k || i==k){
if(i==j){if(b[i]==2){
int t=min(1,b[k]);cb+=t;b[i]-=2*t;b[k]-=t;
}
}
else if(j==k){if(b[j]==2){
int t=min(1,b[i]);cb+=t;b[i]-=t;b[k]-=2*t;
}
}
else if(i==k){if(b[i]==2){
int t=min(1,b[j]);cb+=t;b[j]-=t;b[k]-=2*t;
}
}
}
else{
int t=min(b[i],min(b[j],b[k]));
b[i]-=t;
b[j]-=t;
b[k]-=t;
cb+=t;
//if(t>0)cout<<i<<" "<<j<<" "<<k<<"\n";
}
}
}
}
}
}

//cout<<pera<<" "<<pera<<"\n";
//cout<<ca<<" "<<cb<<"\n";
if(pera==perb){
if(ca==cb)printf("0\n");
else if(ca>cb)printf("1\n");
else printf("2\n");
}
else{
if(pera>perb)printf("1\n");
else printf("2\n");
}
}
	return 0;
}
