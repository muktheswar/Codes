#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

int t[110000], p[110000], perm[110000];

bool cmp(int a, int b) {
	int64 lp = t[a] * int64(p[a]) * (100LL - p[b]);
	int64 rp = t[b] * int64(p[b]) * (100LL - p[a]);
	cout<<"a"<<a<<"b"<<b<<"\n";
	return lp > rp;
}

int main() {
/*#ifdef RADs_project
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif*/

	int n;
	cin >> n;
	forn(i, n)
		scanf("%d%d", &t[i], &p[i]);

	forn(i, n)
		perm[i] = i;

	sort(perm, perm + n, cmp);
	forn(i, n)cout<<perm[i]<<" ";
	cout<<"\n";
	
	int64 prev = 0;
	double ans = 0;
	forn(i, n) {
		int id = perm[i];
		ans += t[id] + (prev * (100LL - p[id])) / 1E4;
		prev += p[id] * t[id];
	}

	printf("%.20lf\n", ans);

	return 0;
}
