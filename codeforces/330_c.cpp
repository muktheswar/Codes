#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<deque>
#include<cmath>
#include<map>
#include<queue>
#define FOR(i,j,k,l) for(((i)=(j));((i)<(k));((i)+=(l)))
#define REP(i,n) for((i)=0;(i)<(n);(i)++)
#define ABS(x) (((x)>=0)?((x)):(-(x)))
#define SWAP(x,y) do{x^=y;y^=x;x^=y;}while(0)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define VLL vector<ll>
#define VI vector<int>
#define PB push_back
#define POB pop_back
#define PI (3.141592654)
typedef  int ll;
typedef long double ld;

#define MOD (1000000007)
#define FEQ(x,y) (ABS((x)-(y))<0.000002)
using namespace std;

int main() {
  ll nin, inum;
  ll x, y, z, i, j, k, n;
    //each test case
      cin>>n;int m=n;
      char r[n+1][n+1];
      FOR(i,0,n,1)cin>>r[i];int cn;
      int mode=0;
      int p1=0;
      FOR(i,0,n,1){
          cn=0;
          FOR(j,0,m,1){
              if(r[i][j]=='E')cn++;//;else mode|=1;                 
          }
          if(cn==n)p1|=1;
      }
      
      FOR(j,0,n,1){
          cn=0;
          FOR(i,0,m,1){
              if(r[i][j]=='E')cn++;//;else mode|=1;                 
          }
          if(cn==n)p1|=2;
      }
      if(p1==3)cout<<-1;
	  else if(p1==2)FOR(i,0,n,1){FOR(j,0,m,1)if(r[i][j]=='.'){printf("%d %d\n",i+1,j+1);break;}}
	  else FOR(j,0,m,1){FOR(i,0,n,1)if(r[i][j]=='.'){printf("%d %d\n",i+1,j+1);break;}}
	  
return 0;
}
