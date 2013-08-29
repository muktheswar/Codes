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
#define  mp make_pair
#define pb push_back
typedef struct node{
int x;int y;int len;
}node;
int a,b;
int dfs(vector<vector<char> >&grid,int start,int end)
{
stack<node> S;
int maxi=1;
vector<vector<bool> > visit(a,vector<bool>(b));
node t;t.x=start;t.y=end;t.len=1;
S.push(t);
while(!S.empty()){
node top=S.top();
S.pop();
int x=top.x,y=top.y;
for(int i=-1;i<=1;i++){
for(int j=-1;j<=1;j++){
if(x+i>=0 && x+i<a && y+j>=0 && y+j<b && grid[x][y]==(grid[x+i][y+j]-1) && !visit[x+i][y+j] /*&& dis[i][j]==(grid[i][j]-64)*/){
node temp;temp.x=x+i;temp.y=y+j;temp.len=top.len+1;
if(temp.len>maxi)maxi=temp.len;
visit[x+i][y+j]=true;
S.push(temp);
}
}
}
visit[x][y]=true;
}
return maxi;
}
int main(){
int T=0;
while(1){
scanf("%d",&a);
scanf("%d",&b);
getchar();
if(a==0 && b==0)break;
vector<vector<char> > grid(a,vector<char>(b));
int dis[a][b];
vector<vector<bool> > visit(a,vector<bool>(b));
vector<pair<int,int> > po;
int f=0;
for(int i=0;i<a;i++){for(int j=0;j<b;j++){dis[i][j]=1;char c;scanf("%c",&c);if(c=='A'){po.pb(make_pair(i,j));f=1;} grid[i][j]=c;}getchar();}
if(f==0){printf("Case %d: %d\n",++T,0);continue;}
int maxi=1;
for(int i=0;i<po.size();i++){int ans=dfs(grid,po[i].first,po[i].second);if(ans>maxi)maxi=ans;}
printf("Case %d: %d\n",++T,maxi);
}
return 0;
}

