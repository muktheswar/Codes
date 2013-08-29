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
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
 
 int N; 
 int* h;  
 void bfs(int start_vertex,vector<bool>& V,vector< vector<int> >&W) { 
      queue<int> Q; 
      Q.push(start_vertex); 
      V[start_vertex] = true;
      while(!Q.empty()) { 
           int i = Q.front();
           Q.pop(); 
           FIT(it,W[i]) { 
                if(!V[*it] && h[*it]>h[i]+1) { 
                     V[*it] = true; 
                     h[*it]=h[i]+1;
		     Q.push(*it); 
                } 
           } 
      } 
 }  
 float cal(int start_vertex,vector<bool>& V,vector< vector<int> >&W) { 
      queue<int> Q; 
      Q.push(start_vertex); 
      V[start_vertex] = true;
      float ans=1;
      while(!Q.empty()) { 
           int i = Q.front();
           Q.pop(); 
           FIT(it,W[i]) { 
                if(!V[*it] && h[*it]>h[i]) { 
                     V[*it] = true; 
		     ans+=1./(h[*it]+1);
		     Q.push(*it); 
                } 
           } 
      } 
      return ans;
 }  
int main(){
	cin>>N;
	h=new int[N];
	vector< vector<int> > W(N);
	for(int i=0;i<N-1;i++){
		h[i]=INF;
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		W[a].pb(b);
		W[b].pb(a);
	}
	h[0]=0;
	h[N-1]=INF;
	vector<bool> V(N,false);
	vector<bool> V1(N,false);
	bfs(0,V,W);
	printf("%.20f\n",cal(0,V1,W));
	return 0;
}
