
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
int MAX;
vector<bool> lefti(300010),righti(300010),visit(300010);
int bsearchl(VI& a,int n,int low,int high){
if(low>high)return INF;
if(visit[low] && !lefti[low] && low!=0){lefti[low]=true;return low;}
int mid=low+(high-low)/2;
int ans=INF;
ans=bsearchl(a,n,low,mid-1);
if(ans==INF){
if(visit[mid] && !lefti[mid] && mid!=0){lefti[mid]=true;ans=mid;}
else ans=bsearchl(a,n,mid+1,high);
}
return ans;
}
int bsearchr(VI& a,int n,int low,int high){
if(low>high)return INF;
if(visit[high] && !righti[high] && high!=MAX){righti[high]=true;return high;}
int mid=low+(high-low)/2;
int ans=INF;
ans=bsearchr(a,n,mid+1,high);
if(ans==INF){
if(visit[mid] && !righti[mid] && mid!=MAX){righti[mid]=true;ans=mid;}
else ans=bsearchr(a,n,low,mid-1);
}
return ans;
}

int main(){
int n=SI;
MAX=n-1;
vector<int> a(n);
VI store;
FOR(i,0,n)visit[i]=lefti[i]=righti[i]=false;
int t=SI;t--;visit[t]=true;a[t]=0;store.pb(t);
cout<<"\n";
FOR(i,0,n-1){int t=SI;t--;store.pb(t);
int ans1=INF,ans2=INF;
if(t+1<n)ans1=bsearchl(a,t,t+1,n-1);
if(t-1>=0)ans2=bsearchr(a,t,0,t-1);
if(ans1!=INF && ans2!=INF){
int t1=a[ans1];
int t2=a[ans2];
if(t1<t2){a[t]=t1+1;righti[ans2]=false;}
else {a[t]=t2+1;lefti[ans1]=false;}
}
else{
if(ans1==INF){a[t]=a[ans2]+1;}
else a[t]=a[ans1]+1;
}
FOR(i,0,n)cout<<lefti[i]<<" ";cout<<"\n";
FOR(i,0,n)cout<<righti[i]<<" ";cout<<"\n";
visit[t]=true;}
int sum=0;
FOR(i,0,n){
sum+=a[store[i]];
printf("%d\n",sum);
}
	return 0;
}
