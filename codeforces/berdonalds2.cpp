#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 205
#define M 40005
using namespace std;

struct node{
	int x, s;
	bool operator < (node const &T) const{return s > T.s;}
};


int n, m, ret, ed, x, y, w, mx, p, t, z;
int l[N], v[N][N], u[N], r[N], L[N];
int qd[M], qn[M], qw[M], ex[M], ey[M], ew[M];
priority_queue<node> q;

void bd(int x, int y, int w){
	qd[++ed] = y, qn[ed] = l[x], l[x] = ed, qw[ed] = w;
}


void Flood(int x, int v[]){
	node cur;
	FOR(i,0,n) v[i] = (1<<30), u[i] = 0;
	q.push((node){x, 0});
	while (!q.empty()){
		cur = q.top(), q.pop();
		if (u[cur.x]) continue;
		v[cur.x] = cur.s;
		u[cur.x] = 1;
		EXP(i,l[cur.x]) q.push((node){qd[i], qw[i] + cur.s});
	}
}

bool cmp(int a, int b){
	return v[a][x] == v[b][x] ? v[a][y] > v[b][y] : v[a][x] > v[b][x];
}

int main(){
	scanf("%d%d", &n, &m);
	FOR(i,0,m){
		scanf("%d%d%d", &x, &y, &w);
		x--, y--, w<<=1;
		bd(x, y, w), bd(y, x, w);
		ex[i] = x, ey[i] = y, ew[i] = w;
	}

	FOR(i,0,n) Flood(i, v[i]);
	
	ret = (1<<30);
	FOR(i,0,n){
		mx = 0;
		FOR(j,0,n) mx = max(mx, v[j][i]);
		ret = min(ret, mx);
	}

	FOR(i,0,m){
		x = ex[i], y = ey[i], w = ew[i];
		FOR(j,0,n) r[j] = j;
		sort(r, r + n, cmp);
		
		L[0] = r[0];
		t = 1;
		FOR(j,1,n){
			if (v[r[j]][y] > v[L[t-1]][y]) L[t++] = r[j];
		}
		
		FOR(j,0,t-1){
			z = (v[L[j]][y] - v[L[j+1]][x] + w) / 2;
			ret = min(ret, v[L[j+1]][x] + z);
		}
	}
	
	printf("%d", ret / 2);
	if (ret & 1) printf(".5");
	puts("");
	return 0;
}
