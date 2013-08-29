
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
int T=SI;
while(T--){
int h=SI;
int w=SI;
//cout<<h<<" "<<w<<"\n"; 
//vector<string> grid;
char grid[w][h+1];
vector<vector<int> > parent(w,vector<int>(h,-1));
FOR(i,0,w){scanf("%s",grid[i]);/*string s;cin>>s;grid.pb(s);*/}
if(grid[0][0]=='#')grid[0][0]='.';
if(grid[w-1][h-1]=='#')grid[w-1][h-1]='.';
VVI(visit,w,h);
VVI(dis,w,h);
FOR(i,0,w){
FOR(j,0,h){
if(grid[i][j]!='#' || (i==0 && j==0)){
int ans=0;
int f=0;
int x,y;
if(i-1>=0 && grid[i-1][j]!='#'){f=1;ans=dis[i-1][j];parent[i][j]=(i-1)*h+j;x=i-1;y=j;}
if(j-1>=0 && grid[i][j-1]!='#'){f=1;ans=max(dis[i][j-1],ans);if(i-1<0 ||dis[i-1][j]<dis[i][j-1]){parent[i][j]=i*h+j-1;x=i;y=j-1;}}
if(i==0 && j==0){f=1;visit[0][0]=1;x=0;y=0;}
if(f==0 || visit[x][y]==0)continue;
dis[i][j]+=ans;
if(grid[i][j]=='*' && f==1 && visit[x][y]==1)dis[i][j]++;
visit[i][j]=1;
}
}
}
FOR(i,0,w){FOR(j,0,h)cout<<dis[i][j]<<" ";cout<<"\n";}
int final=dis[w-1][h-1];
cout<<final<<"\n";
FOR(i,0,w)FOR(j,0,h){dis[i][j]=0;visit[i][j]=0;}
visit[0][0]=1;
int x=w-1,y=h-1;
while(parent[x][y]!=-1){
visit[x][y]=1;
int x1=parent[x][y]/h;
int y1=parent[x][y]%h;
x=x1;
y=y1;
}
if(parent[x][y]=-1)visit[x][y]=1;
FOR(i,0,w){FOR(j,0,h)cout<<visit[i][j]<<" ";cout<<"\n";}
//FOR(i,0,w){FOR(j,0,h)cout<<visit[i][j]<<" ";cout<<"\n";}
for(int i=w-1;i>=0;i--){
for(int j=h-1;j>=0;j--){
if(i==w-1 && j==h-1)continue;
if(grid[i][j]!='#' || (i==0 && j==0)){
int ans=0;
int f=0;
int x,y;
if(i+1<w && grid[i+1][j]!='#'){f=1;ans=dis[i+1][j];x=i+1;y=j;}
if(j+1<h && grid[i][j+1]!='#'){f=1;ans=max(dis[i][j+1],ans);x=i;y=j+1;}
if(f==0 || visit[x][y]==0)continue;
dis[i][j]+=ans;
if(visit[i][j]==0 && grid[i][j]=='*' && visit[x][y]==1)dis[i][j]++;
visit[i][j]=1;
}
}
}
final+=dis[0][0];
printf("%d\n",final);
}
	return 0;
}
