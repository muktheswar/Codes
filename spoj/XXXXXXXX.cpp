
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
#define SORT(c) sort(Aint(c)) 
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
int modpow(int n ,int k,int mod){int ans=1;while(k>0){if(k&1)ans=(ans*n)%mod;k>>=1;n=(n*n)%mod;}return ans%mod;}
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
typedef struct tree{int x;int y;int sum;set<int> s;}tree;
int a[50004];
tree M[100012];
void init(int node,int start,int end){
if(end<start)return;
if(start==end){M[node].x=M[node].y=start;M[node].sum=a[start];M[node].s.clear();M[node].s.insert(a[start]);return;}
int mid=start+(end-start)/2;
init(2*node,start,mid);
init(2*node+1,mid+1,end);
int ans=0;
if(M[2*node].x==0 || M[2*node].y==0){M[node]=M[2*node+1];return;}
if(M[2*node+1].x==0 || M[2*node+1].y==0){M[node]=M[2*node];return;}
M[node].sum=M[2*node].sum+M[2*node+1].sum;
set<int> in;
set_intersection(all(M[2*node].s),all(M[2*node+1].s), std::inserter(in,in.begin()));
FIT(it,in)ans+=*it;
M[node].sum-=ans;
M[node].x=min(M[2*node].x,M[2*node+1].x);
M[node].y=max(M[2*node].y,M[2*node+1].y);
M[node].s.clear();
set_union(all(M[2*node].s),all(M[2*node+1].s),std::inserter(M[node].s,M[node].s.begin()));
return;
}

tree query(int node,int start,int end,int x,int y){
if(start>end){tree t;t.x=t.y=t.sum=0;return t;}
if(x>end || y<start){tree t;t.x=t.y=t.sum=0;return t;}
if(start==end){if(M[node].x<=M[node].y && M[node].x>=x && M[node].y<=y)return M[node];
else {tree t;t.x=t.y=0;return t;}}
if(x<=start && y>=end)return M[node];
int mid=start+(end-start)/2;
tree p1=query(2*node,start,mid,x,y);
tree p2=query(2*node+1,mid+1,end,x,y);
if(p1.x==0 || p1.y==0)return p2;
if(p2.x==0 || p2.y==0)return p1;
int ans=0;
set<int> in;
set_intersection(all(p1.s),all(p2.s), std::inserter(in,in.begin()));
FIT(it,in)ans+=*it;
ans=p1.sum+p2.sum-ans;
tree t;
t.x=min(p1.x,p2.x);
t.y=max(p1.y,p2.y);
t.sum=ans;
t.s.clear();
set_union(all(p1.s),all(p2.s),std::inserter(t.s,t.s.begin()));
return t;
}

void update(int node,int start,int end,int po){
if(start>end)return ;
if(start==end && end==po){M[node].x=M[node].y=start;M[node].sum=a[start];M[node].s.clear();M[node].s.insert(a[start]);return;}
int mid=start+(end-start)/2;
if(po<=mid)update(2*node,start,mid,po);
else update(2*node+1,mid+1,end,po);
int ans=0;
if(M[2*node].x==0 || M[2*node].y==0){M[node]=M[2*node+1];return;}
if(M[2*node+1].x==0 || M[2*node+1].y==0){M[node]=M[2*node];return;}
M[node].sum=M[2*node].sum+M[2*node+1].sum;
set<int> in;
set_intersection(all(M[2*node].s),all(M[2*node+1].s), std::inserter(in,in.begin()));
FIT(it,in)ans+=*it;
M[node].sum-=ans;
M[node].x=min(M[2*node].x,M[2*node+1].x);
M[node].y=max(M[2*node].y,M[2*node+1].y);
M[node].s.clear();
set_union(all(M[2*node].s),all(M[2*node+1].s),std::inserter(M[node].s,M[node].s.begin()));
return;
}
int  main(){
int n;
scanf("%d",&n);
FOR(i,1,n+1)scanf("%d",&a[i]);
init(1,1,n);
int Q;scanf("%d",&Q);
while(Q--){
char ch;
int x,y;
getchar();
scanf("%c%d%d",&ch,&x,&y);
if(ch=='Q'){
tree t=query(1,1,n,x,y);
printf("%d\n",t.sum);
}
else{a[x]=y;update(1,1,n,x);}
}
	return 0;
}
