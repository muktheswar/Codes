
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
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
template <typename T>
  T StringToNumber ( const string &Text )
  {
     istringstream ss(Text);
     T result;
     return ss >> result ? result : 0;
  }
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}
typedef struct node{
int left;
int right;
VI store;
int d;
}node;
bool func(const pair<vector<int>,int>& a,const pair<vector<int>,int>& b){
return a.second>b.second;
}
bool inter(int b1,int w1,int b2,int w2){
return !(b1>w2 || b2>w1);
}
VI getOrdering(VI& h, VI& b, VI&w){
int n=sz(h);
vector<bool> used(n);
int maxh,maxi;
VI final;
VVI (graph,n,n);
FOR(i,0,n)FOR(j,i+1,n)if(inter(h[i],w[i],h[j],w[j]))if(h[i]>h[j])graph[j][i]=1;else graph[i][j]=1;
FOR(i,0,n){
maxh=-1;
maxi=-1;
FOR(j,0,n){
if(used[j])continue;
bool f=false;
FOR(k,0,n)if(graph[k][j]&&!used[k]){f=true;break;}
if(f)continue;
if(h[j]>maxh){maxh=h[j];maxi=j;}
}
if(maxh==-1)break;
final.pb(maxh);
used[maxi]=1;
}
return final;
}
int main(){
int n;
cin>>n;
vector<int> a(n);
VI b(n);
VI c(n);
FOR(i,0,n)cin>>a[i];
FOR(i,0,n)cin>>b[i];
FOR(i,0,n)cin>>c[i];
vector<int> ans=getOrdering(a, b, c);
FOR(i,0,sz(ans))cout<<ans[i]<<" ";cout<<"\n";
	return 0;
}
